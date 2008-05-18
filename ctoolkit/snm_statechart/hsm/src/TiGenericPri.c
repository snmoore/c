/* *************************************************************************** */
/* ****************************** HEADER FILES ******************************* */
/* *************************************************************************** */
/*$Include$*/
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "mrdtypes.h"
#include "eos_inc.h"
#include "SemaphorePub.h"
#include "nu_os.h"
#include "diagint.h"
/*$End$*/

/* *************************************************************************** */
/* **************************** CLASS HEADER FILE **************************** */
/* *************************************************************************** */
#include "TiGenericPub.h"

/* *************************************************************************** */
/* ************************ MACRO FUNCTION PROTOTYPES ************************ */
/* *************************************************************************** */

/* *************************************************************************** */
/* ********************************** DEBUG ********************************** */
/* *************************************************************************** */
/*$Debug$*/
/* the following lines are in a specific order and must not be changed                    */
#define  FILE_LOG_LEVEL 0               /* 1) define the logging level for this file      */
#include "os_debug.h"                 /* 2) include all the asserts and logging externs */
/* your program can now use os_debug_l1/2/3, os_assert and os_except                      */
/*$End$*/

/* *************************************************************************** */
/* ********************** PRE CODE GENERATOR DEFINITIONS ********************* */
/* *************************************************************************** */
/*$PreCodeGen$*/
/* *************************************************************************** */
/* ************************** CONSTANT DECLARATIONS ************************** */
/* *************************************************************************** */
#define MAX_STATE_DEPTH 10

#define AP_ID_LOCK      0   /* used for g_CurrentApId */
#define INST_COUNT_LOCK 1   /* used for g_NumberOfInstances */
#define MAX_LOCK        2

/* *************************************************************************** */
/* ******************************** TYPEDEFS ********************************* */
/* *************************************************************************** */
typedef struct
{
    TI_GENERIC_CLASS_ID Id;
    const TI_GENERIC_CLASS    *Info;
} TI_GENERIC_CLASS_ID_INFO;



/* *************************************************************************** */
/* ************************** VARIABLE DECLARATIONS ************************** */
/* *************************************************************************** */
/* this is used to produce a unquie number per instance*/
static TS_GFSM_HANDLE_ID g_CurrentApId = 0;

/* this holds a count of the number of instances for each class*/
static UINT8 g_NumberOfInstances[ CLASS_ID_MAX ];

/* max value is CLASS_ID_MAX */
/* this is for the UTT where you will have to register each class you want
to use */
static TI_GENERIC_CLASS_ID_INFO  g_GenericClassInfo[ CLASS_ID_MAX ];
static UINT16  g_GenericClassInfoCount = 0;
static BOOLEAN g_GenericClassInfoLock  = FALSE;



/* *************************************************************************** */
/* *********************** ALLOC & FREE DECLARATIONS ************************* */
/* *************************************************************************** */
TS_SEMAPHORE FsmSemaphore[MAX_LOCK];

/*$End$*/

/* *************************************************************************** */
/* *************************** FUNCTION PROTOTYPES *************************** */
/* *************************************************************************** */
static void FsmLogInformation( TI_GENERIC* This, int type, int index );
static void FsmCreateLock(  void );
static void FsmLock( int mode, int Lock );
static int FsmFindClassIdIndexCompare( const void* arg1, const void* arg2 );
static int FsmFindClassIdIndex( TI_GENERIC_CLASS_ID Id );
static int FsmFindIndexFromThis( TL_GFSM_THREAD* Thread, TI_GENERIC* This );
static TS_GFSM_HANDLE_ID FsmGetUniqueHandleId(  void );
static void FsmChangeState( TI_GENERIC* This, UINT8 NextState, TL_EVENT_QUEUE* Event, 
                            BOOLEAN ProcessEvent );
static BOOLEAN FsmRetrieveEvent( TL_GFSM_THREAD* GFsm, TL_EVENT_QUEUE* Item );

/* *************************************************************************** */
/* ********************* POST CODE GENERATOR DEFINITIONS ********************* */
/* *************************************************************************** */
/*$PostCodeGen$*/

/* add your code here */

/*$End$*/

/* *************************************************************************** */
/* **************************** USER'S FUNCTIONS ***************************** */
/* *************************************************************************** */

/*******************************************************************************
*
* FUNCTION: FsmLogInformation
*
* $UniqueID:3D8F2940010E$
*
* $Parm:int type$
* This is the type of logging, eg State, Event, Transistion
* $End$
*
* $Parm:int index$
* This is the index used for each type, eg the 2nd state name
* $End$
*
* $Description$
* This logs information about class state changes to wini-fred
* $End$
*******************************************************************************/
/*$Function$*/
static void FsmLogInformation( TI_GENERIC* This, int type, int index )
{
    /* called by the GFSM code to log states, events, etc */
    os_debug_l3(("Generic pointer = %08X", This ));
    dt_diag_event_log (-1, type, (This->ThisClass->type << 8) + index);
}

/*******************************************************************************
*
* FUNCTION: FsmCreateLock
*
* $UniqueID:3CD2B9860144$
*
* $Parm: void$
* not used
* $End$
*
* $Description$
* This creates the two sempahore locks required by the GFSM
* 
* AP_ID_LOCK       used for g_CurrentApId
* INST_COUNT_LOCK  used for g_NumberOfInstances
* $End$
*******************************************************************************/
/*$Function$*/
static void FsmCreateLock(  void )
{
    int i;

    for ( i = 0; i < MAX_LOCK; i++ )
    {
        LibSemCreate( &FsmSemaphore[i] );
    }
}

/*******************************************************************************
*
* FUNCTION: FsmLock
*
* $UniqueID:3CD2B9860176$
*
* $Parm:int mode$
* This can either be AP_ID_LOCK or INST_COUNT_LOCK
* $End$
*
* $Parm:int Lock$
* True to lock, false to unlock
* $End$
*
* $Description$
* This applies the lock to either AP_ID_LOCK or INST_COUNT_LOCK
* $End$
*******************************************************************************/
/*$Function$*/
static void FsmLock( int mode, int Lock )
{
    if ( Lock )
    {
        LibSemLock( &FsmSemaphore[mode] );
    }
    else
    {
        LibSemUnlock( &FsmSemaphore[mode] );
    }
}

/*******************************************************************************
*
* FUNCTION: FsmFindClassIdIndexCompare
*
* $UniqueID:3CD2B98601D0$
*
* $Parm:const void* arg1$
* a pointer to a TI_GENERIC_CLASS_ID structure
* $End$
*
* $Parm:const void* arg2$
* a pointer to a TI_GENERIC_CLASS_ID_INFO structure
* $End$
*
* $Description$
* This is used by the bsearch function. This is used to find the class info
* structure held in g_GenericClassInfo
* $End$
*******************************************************************************/
/*$Function$*/
static int FsmFindClassIdIndexCompare( const void* arg1, const void* arg2 )
{
    TI_GENERIC_CLASS_ID *Item1 = (TI_GENERIC_CLASS_ID*)arg1;
    TI_GENERIC_CLASS_ID_INFO *Item2 = (TI_GENERIC_CLASS_ID_INFO*)arg2;

    return(*Item1 - Item2->Id);
}

/*******************************************************************************
*
* FUNCTION: FsmFindClassIdIndex
*
* $UniqueID:3CD2B9860234$
*
* $Parm:TI_GENERIC_CLASS_ID Id$
* The class id to find
* $End$
*
* $Description$
* This returns the index to the class info structure that has been registered.
* If no index is found then -1 is returned
* $End$
*******************************************************************************/
/*$Function$*/
static int FsmFindClassIdIndex( TI_GENERIC_CLASS_ID Id )
{
    int index;
    TI_GENERIC_CLASS_ID_INFO *Result = (TI_GENERIC_CLASS_ID_INFO*)bsearch(&Id, g_GenericClassInfo,
        g_GenericClassInfoCount, sizeof(g_GenericClassInfo[0]),
        FsmFindClassIdIndexCompare);

    index = ( Result ? Result - g_GenericClassInfo : -1 );

    return index;
}

/*******************************************************************************
*
* FUNCTION: FsmFindIndexFromThis
*
* $UniqueID:3CD2B9860270$
*
* $Parm:TL_GFSM_THREAD* Thread$
* <Please enter description here>
* $End$
*
* $Parm:TI_GENERIC* This$
* <Please enter description here>
* $End$
*
* $Description$
* <please add description here >
* $End$
*******************************************************************************/
/*$Function$*/
static int FsmFindIndexFromThis( TL_GFSM_THREAD* Thread, TI_GENERIC* This )
{
    int i, imax = Thread->m_InstanceArray.ItemCount;

    for ( i = 0; i < imax && ((TS_GFSM_HANDLE_ITEM*)LibArrayElementAt( &Thread->m_InstanceArray, i ))->This != This; i++ )
    {
        /* do nothing */
    }

    return ( i < imax ? i:-1 );
}

/*******************************************************************************
*
* FUNCTION: FsmGetUniqueHandleId
*
* $UniqueID:3CD2B98602F2$
*
* $Parm: void$
* not used
* $End$
*
* $Description$
* This returns the g_CurrentApId which has been incremented by one. This is a
* thread safe function
* $End$
*******************************************************************************/
/*$Function$*/
static TS_GFSM_HANDLE_ID FsmGetUniqueHandleId(  void )
{
    FsmLock( AP_ID_LOCK, TRUE );
    g_CurrentApId++;
    FsmLock( AP_ID_LOCK, FALSE );

    return g_CurrentApId;
}

/*******************************************************************************
*
* FUNCTION: FsmChangeState
*
* $UniqueID:3CD2B9860338$
*
* $Parm:UINT8 NextState$
* The next state to move to
* $End$
*
* $Parm:TL_EVENT_QUEUE* Event$
* A structure that hold the event
* $End$
*
* $Parm:BOOLEAN ProcessEvent$
* If true then the event is used to work out the next state, otherwise the
* next state parameter is used
* $End$
*
* $Description$
* This changes state within a class
* $End$
*******************************************************************************/
/*$Function$*/
static void FsmChangeState( TI_GENERIC* This, UINT8 NextState, TL_EVENT_QUEUE* Event, 
                            BOOLEAN ProcessEvent )
{
    TL_STATE_ID src[MAX_STATE_DEPTH], dst[MAX_STATE_DEPTH];
    TL_STATE_ID state;
    int src_max, dst_max;
    int s, d, e, i, imax;
    int src_t = -1, log_i, dt;
    TS_GFSM_ARG Arg;

    const TL_GEN_STATE *StatePtr;
    const TL_GEN_TRANS *Trans = NULL;
    const TL_GEN_INTERNAL *IntTrans;


    if ( This->ThisClass->EntryState == s_NULL )
    {
        /* we have no state machine, so exit*/
        return;
    }

    /* now to setup the call back data */
    Arg.Qual = 0;
    if ( Event )
    {
        Arg.Mode  = Event->ArgMode;
        Arg.Value = Arg.Mode == GFSM_ARG_VALUE ? (int)(Event->pArgData) : 0;
        Arg.pData = (Arg.Mode == GFSM_ARG_CONST || Arg.Mode == GFSM_ARG_POINTER ) ? Event->pArgData  : NULL;
    }
    else
    {
        Arg.Mode  = GFSM_ARG_NONE;
        Arg.Value = 0;
        Arg.pData = NULL;
    }

    state = This->ThisInst.CurrentState;
    for ( src_max = 0; state != s_ROOT; src_max++ )
    {
        src[ src_max ] = state;
        state = This->ThisClass->StateInfo[state].ParentId;
    }
    os_except( src_max <= MAX_STATE_DEPTH, ("too many nested states (%d)",src_max) );


    if ( ProcessEvent )
    {
        NextState = This->ThisInst.CurrentState;
        //we need to find the transistion
        for ( e = 0 ; Trans == NULL && e < src_max ; e++ )
        {
            StatePtr = &This->ThisClass->StateInfo[ src[e] ];
            for ( i = StatePtr[0].TransIndex, imax = StatePtr[1].TransIndex; i < imax; i++ )
            {
                Trans = &This->ThisClass->TransList[i];
                //check that the events match and also the guard func returns true
                if ( Trans->Event == Event->Event && Trans->GuardFnc(This, Trans->GuardQual ) )
                {
                    NextState = Trans->NextState;
                    src_t = e;
                    log_i = i;
                    break;
                }
                Trans = NULL;
            }
        }
    }


    //find out if This state has any child state states
    while ( NextState != s_ROOT && This->ThisClass->StateInfo[NextState].ChildId != s_NULL )
    {
        NextState = This->ThisClass->StateInfo[NextState].ChildId;
    }

    state = NextState;
    for ( dst_max = 0; state != s_ROOT; dst_max++ )
    {
        dst[ dst_max ] = state;
        state = This->ThisClass->StateInfo[state].ParentId;
    }
    os_except( src_max <= MAX_STATE_DEPTH, ("too many nested states (%d)", src_max) );

    s= src_max - 1;
    d = dst_max - 1;
    for ( ; s >= 0 && d >= 0 && src[s] == dst[d]; s--, d-- )
    {
        //do nothing
    }

    for ( e = src_max - 1; ProcessEvent && e > s ; e-- )
    {
        //need to check this state for any internal events
        StatePtr = &This->ThisClass->StateInfo[ src[e] ];

        for ( i = StatePtr[0].InterIndex, imax = StatePtr[1].InterIndex; i < imax; i++ )
        {
            IntTrans = &This->ThisClass->IntList[i];
            //check that the events match and also the guard func returns true
            if ( IntTrans->Event == Event->Event && IntTrans->GuardFnc(This, IntTrans->GuardQual ) )
            {
                //now we want to run the action
                FsmLogInformation( This, INT_LOG_ID, i );
                //os_assert( IntTrans->ActionFnc != a_NULL_FNC, "invalid null ction for entry/exit",0 );
                Arg.Qual = IntTrans->ActionQual;
                IntTrans->ActionFnc( This, Arg.Qual, &Arg );
            }
        }
    }

    if ( Trans && src_t > s )
    {
        dt = src_t - s;
        s += dt;
        d += dt;
    }


    for ( e = 0; e <= s; e++ )
    {
        //need to do any exit actions
        StatePtr = &This->ThisClass->StateInfo[ src[e] ];
        for ( i = StatePtr[0].ExitIndex, imax = StatePtr[1].ExitIndex; i < imax; i++ )
        {
            FsmLogInformation( This, EXT_LOG_ID, i );
            Arg.Qual = This->ThisClass->ExitList[i].ActionQual;
            This->ThisClass->ExitList[i].ActionFnc( This, Arg.Qual, &Arg );
        }

    }

    //need to do any transistion actions
    if ( Trans )
    {
        FsmLogInformation( This, TRA_LOG_ID, log_i );
        if ( Trans->ActionFnc != A_NULL_FNC)
        {
            //now we want to run the transistion action
            Arg.Qual = Trans->ActionQual;
            Trans->ActionFnc( This, Arg.Qual, &Arg );
        }
    }

    //we now want to change state
    This->ThisInst.CurrentState = NextState;
    FsmLogInformation( This, STA_LOG_ID, NextState );

    for ( e = d; e >= 0; e-- )
    {
        //need to do any entry actions
        StatePtr = &This->ThisClass->StateInfo[ dst[e] ];
        for ( i = StatePtr[0].EntryIndex, imax = StatePtr[1].EntryIndex; i < imax; i++ )
        {
            FsmLogInformation( This, ENT_LOG_ID, i );
            Arg.Qual = This->ThisClass->EntryList[i].ActionQual;
            This->ThisClass->EntryList[i].ActionFnc( This, Arg.Qual, &Arg );
        }
    }

    /* if the arg pointer has been set to null then we don't need to free it latter on */
    if ( Event )
    {
        Event->pArgData = Arg.pData;
    }
}

/*******************************************************************************
*
* FUNCTION: FsmRetrieveEvent
*
* $UniqueID:3CD2B98603C5$
*
* $Parm:TL_GFSM_THREAD* GFsm$
* a pointer to the thread which holds the event queue you want to process
* $End$
*
* $Parm:TL_EVENT_QUEUE* Item$
* this is the return parameter
* $End$
*
* $Description$
* this retieves an event from the thread structure. If there is no event then
* false is returned
* $End$
*******************************************************************************/
/*$Function$*/
static BOOLEAN FsmRetrieveEvent( TL_GFSM_THREAD* GFsm, TL_EVENT_QUEUE* Item )
{
    BOOLEAN Result;

    if ( GFsm->m_EventFifo.ItemCount )
    {
        /* we have an event on the queue */
        Result = LibFifoPop( &GFsm->m_EventFifo, Item );
        os_assert( Result, ("Error in fifo"));
        os_assert( Item->This, ("Error in fifo item"));
    }
    else
    {
        Item->This  = NULL;
        Item->Event = 0;
        Result      = FALSE;
    }

    return Result;

}

/*******************************************************************************
*
* FUNCTION: FsmGetCurrentTask
*
* $UniqueID:3CD2B98600F4$
*
* $Parm: void$
* not used
* $End$
*
* $Description$
* This returns a void pointer which is unique to each task
* $End$
*******************************************************************************/
/*$Function:GFSM Provider Interface:3D93201302EC$*/
void* FsmGetCurrentTask(  void )
{
    ID TskId;
    get_tidx(&TskId);
    return (void*)TskId;
}

/*******************************************************************************
*
* FUNCTION: FsmIfIsThisValid
*
* $UniqueID:3CD2B98602CA$
*
* $Description$
* <please add description here >
* $End$
*******************************************************************************/
/*$Function:GFSM Provider Interface:3D93201302EC$*/
BOOLEAN FsmIfIsThisValid( TI_GENERIC* This )
{
    BOOLEAN Ret = FALSE;

    if ( This && This->ThisInst.Mode > GFSM_INVALID && This->ThisInst.Mode < GFSM_LAST )
    {
        TL_GFSM_THREAD *Thread = This->ThisInst.Thread;
        if ( Thread->m_InstanceArray.ItemSize == SIZE_OF_INT(TS_GFSM_HANDLE_ITEM)
            && Thread->m_EventFifo.ItemSize   == SIZE_OF_INT(TL_EVENT_QUEUE) )
        {
            TS_ARRAY *Array            = &Thread->m_InstanceArray;
            TS_GFSM_HANDLE_ID HandleId = This->ThisInst.HandleId;
            TS_GFSM_HANDLE_ITEM * Item;
            int i, imax = Array->ItemCount;

            /* we know at least a nearly correct pointer */
            for ( i = 0; i < imax ; i++ )
            {
                Item = (TS_GFSM_HANDLE_ITEM*)LibArrayElementAt( Array, i );
                if ( Item->HandleId == HandleId && Item->This == This )
                {
                    Ret = TRUE;
                    break;
                }
            }
        }
    }

    return Ret;
}

/*******************************************************************************
*
* FUNCTION: FsmIfRegisterClass
*
* $UniqueID:3CD2B987004B$
*
* $Parm:TI_GENERIC_CLASS_ID Id$
* The class id
* $End$
*
* $Parm:const TI_GENERIC_CLASS* Info$
* The class info structure
* $End$
*
* $Description$
* This registers a new class into the array. If the class is regisitered correctly
* then the class id value is returned, else TI_CLASS_NULL_ID is return if it fails
* $End$
*******************************************************************************/
/*$Function:GFSM Provider Interface:3D93201302EC$*/
TI_GENERIC_CLASS_ID FsmIfRegisterClass( TI_GENERIC_CLASS_ID Id, 
                                        const TI_GENERIC_CLASS* Info )
{
    int x;
    TI_GENERIC_CLASS_ID RetClassId = Id;
    os_except( g_GenericClassInfoCount < sizeof(g_GenericClassInfo)/sizeof(g_GenericClassInfo[0]), ("More than %d classes",g_GenericClassInfoCount));
    os_except( g_GenericClassInfoLock == FALSE, ("too late to register new class"));


    /* this finds the correct place to insert the new class id into */
    x = FsmFindClassIdIndex(Id);
    if ( x != -1 )
    {
        os_assert( FALSE, ("Class is already registered"));
        /*
        * if the other class is a different name, then it means that we have two class with the same class id. This
        * is very bad, and will causes errors when creating new instances. One of the class ids must be changed
        */
        os_except( strcmp(Info->Name, g_GenericClassInfo[x].Info->Name) == 0, ("There are two different class with the same class id"));
        RetClassId = TI_CLASS_NULL_ID;
    }
    else
    {
        for ( x = 0; x < g_GenericClassInfoCount && g_GenericClassInfo[x].Id < Id; x++ );

        /* move all other class along by one */
        memmove( &g_GenericClassInfo[x+1],&g_GenericClassInfo[x], sizeof(g_GenericClassInfo[0]) * (g_GenericClassInfoCount - x) );
        g_GenericClassInfo[x].Id = Id;
        g_GenericClassInfo[x].Info = Info;
        g_GenericClassInfoCount++;
        switch ( Info->ClassType )
        {
        case STRUCTURE_CLASS_TYPE:
        case DEFAULT_CLASS_TYPE:
        case DYNAMIC_CLASS_TYPE:
            /* we don't need to do anything for these */
            break;

        case STATIC_CLASS_TYPE:
        case CONSTANT_CLASS_TYPE:
            /* All these classes are defined at build time, so we have effectivly created them all already */
            /*g_NumberOfInstances[x] = Info->MaxNumOfInstances;*/
            break;
        default:
            os_assert( 0, ("Unkown class type from %s", Info->Name ));
            RetClassId = TI_CLASS_NULL_ID;
            break;
        }
    }

    return RetClassId;

}

/*******************************************************************************
*
* FUNCTION: FsmIfIsClassRegistered
*
* $UniqueID:3CD2B98700B9$
*
* $Parm:TI_GENERIC_CLASS_ID Id$
* the class id
* $End$
*
* $Description$
* this returns TRUE if the class has been registered
* $End$
*******************************************************************************/
/*$Function:GFSM Provider Interface:3D93201302EC$*/
BOOLEAN FsmIfIsClassRegistered( TI_GENERIC_CLASS_ID Id )
{
    int i = FsmFindClassIdIndex( Id );

    return ( i != -1 ? TRUE : FALSE );
}

/*******************************************************************************
*
* FUNCTION: FsmIfCheckClassId
*
* $UniqueID:3CD2B98700FF$
*
* $Parm:TI_GENERIC_CLASS_ID Id$
* The class id
* $End$
*
* $Description$
* this checks that the Id and the class pointer are the same type
* $End$
*******************************************************************************/
/*$Function:GFSM Provider Interface:3D93201302EC$*/
TI_GENERIC* FsmIfCheckClassId( TI_GENERIC* This, TI_GENERIC_CLASS_ID Id )
{
    if ( This && This->ThisClass->type != Id )
    {
        int IdIndex = FsmFindClassIdIndex(Id);
        const TI_GENERIC_CLASS *ClassInfo = g_GenericClassInfo[IdIndex].Info;

        os_assert( IdIndex != -1, ("unknown class id"));
        os_assert( This->ThisClass->type == Id, ("Can not convert %s* to %s*", This->ThisClass->Name, ClassInfo->Name ));
    }

    return This;
}

/*******************************************************************************
*
* FUNCTION: FsmIfConfigure
*
* $UniqueID:3CD2B987014F$
*
* $Parm: void$
* not used
* $End$
*
* $Description$
* This must be called once all the classes have been registered
* $End$
*******************************************************************************/
/*$Function:GFSM Provider Interface:3D93201302EC$*/
void FsmIfConfigure(  void )
{
    UINT x;

    memset ( g_NumberOfInstances, 0, sizeof ( g_NumberOfInstances ) );
    /* create a semaphore to use */
    FsmCreateLock();

    os_assert( TI_CLASS_NULL_ID == 0, ("TI_CLASS_NULL must be first  class in TiGenericDef.m"));
    os_assert( TI_GENERIC_ID    == 1, ("TI_GENERIC    must be second class in TiGenericDef.m"));

    g_GenericClassInfoLock = TRUE;

    for ( x = 0 ; x < g_GenericClassInfoCount; x++ )
    {
        switch ( g_GenericClassInfo[x].Info->ClassType )
        {
        case STRUCTURE_CLASS_TYPE:
        case DEFAULT_CLASS_TYPE:
        case DYNAMIC_CLASS_TYPE:
            /* we don't need to do anything for these */
            break;

        case STATIC_CLASS_TYPE:
        case CONSTANT_CLASS_TYPE:
            /* All these classes are defined at build time, so we also have to call each classes constructure */
            /* but we don't know about any instances pointers g_GenericClassInfo[x].Info->NewFn(This, NULL); */

            /* All these classes are defined at build time, so we have effectivly created them all already */
            g_NumberOfInstances[x] = g_GenericClassInfo[x].Info->MaxNumOfInstances;
            break;

        default:
            os_assert( 0, ("Unkown class type from %s", g_GenericClassInfo[x].Info->Name ));
            break;
        }


        if ( g_GenericClassInfo[x].Info->Memory )
        {
            /* we have valid memory, so set it to zero */
            os_assert( g_GenericClassInfo[x].Info->SizeOfPublic    % sizeof(int) == 0, ("error in structure aligment") );
            os_assert( g_GenericClassInfo[x].Info->SizeOfProtected % sizeof(int) == 0, ("error in structure aligment") );
            os_assert( g_GenericClassInfo[x].Info->SizeOfPrivate   % sizeof(int) == 0, ("error in structure aligment") );
            memset( g_GenericClassInfo[x].Info->Memory, 0,
                (g_GenericClassInfo[x].Info->SizeOfPublic + g_GenericClassInfo[x].Info->SizeOfProtected+ g_GenericClassInfo[x].Info->SizeOfPrivate + SIZE_OF_INT(TI_GENERIC))
                * g_GenericClassInfo[x].Info->MaxNumOfInstances );
        }
        if ( g_GenericClassInfo[x].Info->ConfigFn )
        {
            g_GenericClassInfo[x].Info->ConfigFn(0);
        }
    }

}

/*******************************************************************************
*
* FUNCTION: FsmIfConfigureThread
*
* $UniqueID:3CD2B9870195$
*
* $Parm:TL_GFSM_THREAD* GFsm$
* the pointer to a thread structure
* $End$
*
* $Description$
* Each task needs a TL_GFSM_THREAD structure which must be configured before
* use, This must be done striaght after the task has been created.
* $End$
*******************************************************************************/
/*$Function:GFSM Provider Interface:3D93201302EC$*/
void FsmIfConfigureThread( TL_GFSM_THREAD* GFsm )
{
    /* create a dynamic FIFO for the GFSM events */
    LibFifoCreateDynamic( &GFsm->m_EventFifo, SIZE_OF_INT(TL_EVENT_QUEUE) );
    LibFifoSetSize( &GFsm->m_EventFifo, MAX_NUM_OF_TI_GENERIC_QUEUE_EVENTS, 64 );

    /* create a dynamic ARRAY to store all created instances attached to this thread*/
    LibArrayCreateDynamic( &GFsm->m_InstanceArray, SIZE_OF_INT(TS_GFSM_HANDLE_ITEM) );
    LibArraySetSize( &GFsm->m_InstanceArray, MAX_NUM_OF_TI_GENERIC_INSTANCES, 16 );

    GFsm->m_MaxInstanceCount     = 0; /* this is used for debuging only */
    GFsm->m_MaxEventCount        = 0; /* this is used for debuging only */
    GFsm->m_pTask                = FsmGetCurrentTask();
}

/*******************************************************************************
*
* FUNCTION: FsmIfDeconfigureThread
*
* $UniqueID:3CD2B98701E5$
*
* $Parm:TL_GFSM_THREAD* GFsm$
* the pointer to a thread structure
* $End$
*
* $Description$
* This cleans up any lose ends from the GFSM Thread
* $End$
*******************************************************************************/
/*$Function:GFSM Provider Interface:3D93201302EC$*/
void FsmIfDeconfigureThread( TL_GFSM_THREAD* GFsm )
{
    /* all instance should be destroyed now */
    os_assert( GFsm->m_InstanceArray.ItemCount == 0, ("Not all class instances are destoryed"));

    /* destroy all thread internal buffer */
    LibFifoDestroy( &GFsm->m_EventFifo );
    LibArrayDestroy( &GFsm->m_InstanceArray );
}

/*******************************************************************************
*
* FUNCTION: FsmIfCreateInstanceWithData
*
* $UniqueID:3CD2B9870235$
*
* $Parm:TL_GFSM_THREAD* thread$
* the pointer to a thread structure
* $End$
*
* $Parm:TI_GENERIC* Parent$
* the parent class
* $End$
*
* $Parm:TI_GENERIC_CLASS_ID Id$
* The class id of the new class to create
* $End$
*
* $Parm:void* ParentData$
* and init data you want to pass to the new instance
* $End$
*
* $Description$
* This creates a new instance of your class and attaches it to either thread
* or parent class
* $End$
*******************************************************************************/
/*$Function:GFSM Provider Interface:3D93201302EC$*/
TI_GENERIC* FsmIfCreateInstanceWithData( TL_GFSM_THREAD* thread, TI_GENERIC* Parent, 
                                         TI_GENERIC_CLASS_ID Id, void* ParentData )
{
    int MemSizeReq, x, xmax,  offset, PtrIndex;
    TI_GENERIC *This = NULL;
    int IdIndex = FsmFindClassIdIndex(Id);
    const TI_GENERIC_CLASS *ClassInfo = g_GenericClassInfo[IdIndex].Info;

    os_except( IdIndex != -1, ("Can not find class id. has it been registered??"));
    //lock.Lock();

    /* 0) check to see if we are in the same task as the Thread was created in*/
    if ( thread->m_pTask != FsmGetCurrentTask() )
    {
        os_assert(0, ("you can only create classes attached to the same thread and task"));
        return NULL;
    }

    /* 0) if this is a null class then return NULL striaght away */
    if ( !ClassInfo->Name[0] )
    {
        return NULL;
    }

    /* 0a) we can only create the folowing types of classes */
    if ( ClassInfo->ClassType != DEFAULT_CLASS_TYPE && ClassInfo->ClassType != DYNAMIC_CLASS_TYPE )
    {
        os_assert( 0, ("Invalid class type from %s", ClassInfo->Name ));
        return NULL;
    }

    FsmLock( INST_COUNT_LOCK, TRUE );
    {
        /* 1) check that we have not exceed the max number of this type of class */
        if ( g_NumberOfInstances[IdIndex] >= ClassInfo->MaxNumOfInstances  )
        {
            FsmLock( INST_COUNT_LOCK, FALSE );
            os_assert ( FALSE, ("too many instances of %s created", ClassInfo->Name) );
            return This;
        }

        /* 2) check that we have alloc enough memory for this instance */
        MemSizeReq = ClassInfo->SizeOfPrivate
        + ClassInfo->SizeOfProtected
        + ClassInfo->SizeOfPublic
        + SIZE_OF_INT(TI_GENERIC);
        if ( ClassInfo->Memory )
        {
            for ( x = 0, xmax = ClassInfo->MaxNumOfInstances; x < xmax; x++ )
            {
                This = (TI_GENERIC*)(((UINT8*)ClassInfo->Memory) + (x * MemSizeReq));
                if ( This->ThisInst.Mode == GFSM_INVALID )
                {
                    break;
                }
            }
            os_except( x < xmax, ("no free instances left"));
        }
        else
        {
            This = xAlloc( MemSizeReq );
        }
        if ( !This )
        {
            FsmLock( INST_COUNT_LOCK, FALSE );
            os_assert ( FALSE, ("memory allocation of instanced failed") );
            return This;
        }
        memset( This, 0x00,MemSizeReq );

        /* 3) check the current tide mark */
        if ( thread->m_InstanceArray.ItemCount > thread->m_MaxInstanceCount )
        {
            thread->m_MaxInstanceCount = (UINT8)thread->m_InstanceArray.ItemCount;
            os_debug_l3 (( "***GENERIC FSM INFO*** max instance count = %d", thread->m_MaxInstanceCount ));
        }


        //the class information
        This->ThisClass = ClassInfo;

        //the number of instances
        This->ThisInst.Mode         = GFSM_VALID;
        This->ThisInst.CurrentState = s_ROOT;
        This->ThisInst.HandleId     = FsmGetUniqueHandleId();

        /* 4) now to set up all the instance data for this class */
        {
            TS_GFSM_HANDLE_ITEM Item;
            Item.This     = This;
            Item.HandleId = This->ThisInst.HandleId;
            LibArrayAdd( &thread->m_InstanceArray, &Item );
        }
        g_NumberOfInstances[IdIndex]++;
    }
    FsmLock( INST_COUNT_LOCK, FALSE );



    //check that the parent pointer is valid
    os_except( IsThisSafeValid(Parent), ("Invalid class ptr") );
    This->ThisInst.Parent = Parent;
    This->ThisInst.Root   = ( Parent ? Parent->ThisInst.Root : This );
    This->ThisInst.Thread = thread;
    /* NOTE if we require more RAM we can lose this parameter and just type cast XXXX to TI_GENERIC */
    This->ThisInst.This = This;

    offset = SIZE_OF_INT(TI_GENERIC);
    PtrIndex = 0;
    if ( ClassInfo->SizeOfPublic > 0 )
    {
        This->ptr[PtrIndex++] = (UINT8*)This + offset;
        offset += ClassInfo->SizeOfPublic;
    }
    if ( ClassInfo->SizeOfProtected > 0 )
    {
        This->ptr[PtrIndex++] = (UINT8*)This + offset;
        offset += ClassInfo->SizeOfProtected;
    }
    if ( ClassInfo->SizeOfPrivate > 0 )
    {
        This->ptr[PtrIndex++] = (UINT8*)This + offset;
        offset += ClassInfo->SizeOfPrivate;
    }

    /*now add an event to move the state machine to it's start state*/
    FsmIfAddEventToGenericClass( This, E_GEN_FSM_RESET );

    /* now to call the new function for the class */
    ClassInfo->NewFn(This, ParentData );


    return This;
}

/*******************************************************************************
*
* FUNCTION: FsmIfGenericAttachInstanceToThreadWithData
*
* $UniqueID:3CD2B9870312$
*
* $Parm:TL_GFSM_THREAD* thread$
* a pointer to the gfsm thread you want to attach to
* $End$
*
* $Parm:TI_GENERIC* Parent$
* the parent class
* $End$
*
* $Parm:TI_GENERIC* This$
* The class
* $End$
*
* $Parm:void* ParentData$
* not used
* $End$
*
* $Description$
* This attacheds a STATIC type class to a thread. this then allows the class
* to use events
* $End$
*******************************************************************************/
/*$Function:GFSM Provider Interface:3D93201302EC$*/
TI_GENERIC* FsmIfGenericAttachInstanceToThreadWithData( TL_GFSM_THREAD* thread, 
                                                        TI_GENERIC* Parent, 
                                                        TI_GENERIC* This, void* ParentData )
{
    int IdIndex = FsmFindClassIdIndex( This->ThisClass->type);
    const TI_GENERIC_CLASS *ClassInfo = g_GenericClassInfo[IdIndex].Info;

    os_except( IdIndex != -1, ("Can not find class id. has it been registered??"));
    //lock.Lock();

    /* 0) check to see if we are in the same task as the Thread was created in*/
    if ( thread->m_pTask != FsmGetCurrentTask() )
    {
        os_assert(0, ("you can only attach a object within the same task and thread"));
        return NULL;
    }

    /* 1) check that we have the correct type of class */
    if ( This->ThisClass->ClassType != STATIC_CLASS_TYPE )
    {
        os_assert( 0, ("can only attach static classes not %s", This->ThisClass->Name ));
        return 0;
    }

    if ( This->ThisInst.Mode != GFSM_UNATTACHED )
    {
        os_assert( 0, ("instance %s already attached", This->ThisClass->Name ));
        return 0;
    }


    //the class information
    os_assert ( This->ThisClass == ClassInfo, ("error in mapping class info"));;

    //the number of instances
    This->ThisInst.Mode         = GFSM_VALID;
    This->ThisInst.CurrentState = s_ROOT;
    This->ThisInst.HandleId     = FsmGetUniqueHandleId();
    This->ThisInst.This         = This;

    //check that the parent pointer is valid
    os_except( IsThisSafeValid(Parent), ("Invalid class ptr") );
    This->ThisInst.Parent = Parent;
    This->ThisInst.Root   = ( Parent ? Parent->ThisInst.Root : This );
    This->ThisInst.Thread = thread;

   /* 4) now to set up all the instance data for This class */
    {
        TS_GFSM_HANDLE_ITEM Item;
        Item.This     = This;
        Item.HandleId = This->ThisInst.HandleId;
        LibArrayAdd( &thread->m_InstanceArray, &Item );
    }


    ClassInfo->NewFn(This, ParentData );

    //now add an event to move the state machine to it's start state
    FsmIfAddEventToGenericClass( This, E_GEN_FSM_RESET );

    return This;
}

/*******************************************************************************
*
* FUNCTION: FsmIfDeleteGenericInstance
*
* $UniqueID:3CC7C3DB019F$
*
* $Description$
* This deletes an instance of your class
* $End$
*******************************************************************************/
/*$Function:GFSM Provider Interface:3D93201302EC$*/
BOOLEAN FsmIfDeleteGenericInstance( TI_GENERIC** ThisPtr )
{
    TI_GENERIC * This;
    BOOLEAN Result = FALSE;
    int x;

    /* check argument is valid or not, if is NULL, nothing to do */
    if( ThisPtr == NULL || (This = *ThisPtr) == NULL ) return FALSE;

    /* 1) check that we have a valid This to delete */
    if ( !IsThisValid(This) )
    {
        os_assert( FALSE, ("The instance to delete is not valid"));
    }
    /* 2) check to see if we are in the same task as the Thread was created in*/
    else if ( This->ThisInst.Thread->m_pTask != FsmGetCurrentTask() )
    {
        os_assert( FALSE, ("you can only attach a object within the same task and thread"));
    }
    /* 3) check to see if it is the type of instance we can delete */
    else if ( This->ThisClass->ClassType != DEFAULT_CLASS_TYPE && This->ThisClass->ClassType != DYNAMIC_CLASS_TYPE )
    {
        os_assert( FALSE, ("You can not delete constant or static instances"));
    }
    else
    {
        TL_EVENT_QUEUE *Item;
        /*we have found a pointer match, so call it's destuctor but first call any exit actions */
        os_debug_l3(("Deleting Class %08X::%s", This, This->ThisClass->Name ));
        FsmChangeState( This, s_ROOT, NULL, FALSE);
        This->ThisClass->DeleteFn(This);

        /* we have now got to check the event queue for any events for This instance */
        for ( x = This->ThisInst.Thread->m_EventFifo.ItemCount - 1; x >= 0 ; x-- )
        {
            Item = (TL_EVENT_QUEUE*)LibFifoElementAt( &This->ThisInst.Thread->m_EventFifo, x );
            if ( Item->This == This )
            {
                /* we need to remove this item */
                LibFifoRemoveAt( &This->ThisInst.Thread->m_EventFifo, x );
            }
        }

        FsmLock( INST_COUNT_LOCK, TRUE );
        {
            g_NumberOfInstances[FsmFindClassIdIndex(This->ThisClass->type) ]--;
        }
        FsmLock( INST_COUNT_LOCK, FALSE );

        Result = LibArrayRemoveAt( &This->ThisInst.Thread->m_InstanceArray, FsmFindIndexFromThis( This->ThisInst.Thread, This ) );
        This->ThisInst.Mode = GFSM_INVALID;
        This->ThisInst.This = NULL;

        if ( !This->ThisClass->Memory )
        {
            xFree( &This );
        }
    }

    os_assert( Result, ("can not delete instance"));

    /* if success, reset instance pointer */
    if( Result ) *ThisPtr = NULL;

    return Result;

}

/*******************************************************************************
*
* FUNCTION: FsmIfAddEventToGenericClass
*
* $UniqueID:3CD2B9880024$
*
* $Parm:TS_GFSM_EVENT Event$
* the event to store
* $End$
*
* $Description$
* This adds an event on to the correct thread that belongs to your instance
* $End$
*******************************************************************************/
/*$Function:GFSM Provider Interface:3D93201302EC$*/
void FsmIfAddEventToGenericClass( TI_GENERIC* This, TS_GFSM_EVENT Event )
{
    FsmIfAddEventToGenericClassWithData( This, Event, GFSM_ARG_NONE, 0 );
}

/*******************************************************************************
*
* FUNCTION: FsmIfAddEventToGenericClassWithData
*
* $Parm:TS_GFSM_EVENT Event$
* the event to store
* $End$
*
* $Description$
* This adds an event with data on to the correct thread that belongs to your instance
* $End$
*******************************************************************************/
/*$Function$*/
void FsmIfAddEventToGenericClassWithData( TI_GENERIC* This, TS_GFSM_EVENT Event, TS_GFSM_ARG_MODE ArgMode, const void *Arg )
{
    TL_EVENT_QUEUE Item;
    BOOLEAN Added = FALSE;

    if ( IsThisValid(This) )
    {
        if ( This->ThisInst.Mode == GFSM_VALID )
        {
            os_assert( (Event & 0x80) != 0 || This->ThisClass->type == (TI_GENERIC_CLASS_ID)(Event >> 8), ("incorrect event for specified class") );
            os_assert( This->ThisInst.Thread->m_pTask == FsmGetCurrentTask(), ("you can only attach a object within the same task and thread"));

            /* we can ignore the global event E_NULL */
            if ( Event == E_NULL )
            {
                Added = TRUE;
            }
            else
            {
                Item.Event = Event;
                Item.This  = This;
                Item.ArgMode  = ArgMode;
                Item.pArgData = (void*)Arg;
                Added = LibFifoPush( &This->ThisInst.Thread->m_EventFifo, &Item);
                if( This->ThisInst.Thread->m_EventFifo.ItemCount > This->ThisInst.Thread->m_MaxEventCount )
                {
                    This->ThisInst.Thread->m_MaxEventCount = (UINT8)This->ThisInst.Thread->m_EventFifo.ItemCount;
                    os_debug_l3(( "***GENERIC FSM INFO*** max event count = %d", This->ThisInst.Thread->m_MaxEventCount ));
                }
            }
        }
        else if ( This->ThisInst.Mode == GFSM_UNATTACHED && This->ThisClass->ClassType == STATIC_CLASS_TYPE )
        {
            /* we have an unattached instance, so inform the user and throw the event away */
            os_assert( FALSE, ("unattached %s can not process event id %d", This->ThisClass->Name, Event));
        }
    }
    os_assert( Added, ("error in adding event"));
}

/*******************************************************************************
*
* FUNCTION: FsmIfProcessEventQueue
*
* $UniqueID:3CD2B9880088$
*
* $Parm:TL_GFSM_THREAD* GFsm$
* a pointer to the GFSM structure
* $End$
*
* $Description$
* this must be called to pump the generic FSM on each thread
* returns false if no events are processed
* $End$
*******************************************************************************/
/*$Function:GFSM Provider Interface:3D93201302EC$*/
BOOLEAN FsmIfProcessEventQueue( TL_GFSM_THREAD* GFsm )
{
    TL_EVENT_QUEUE Item;
    BOOLEAN ret = FALSE;

    while ( FsmRetrieveEvent( GFsm, &Item ) )
    {
        ret = TRUE;
        os_assert( IsThisValid(Item.This), ("Instance not valid") );

        //we have a valid event, first to check for internal trans
        if ( Item.Event == E_GEN_FSM_RESET )
        {
            FsmChangeState( Item.This,  Item.This->ThisClass->EntryState, NULL, FALSE);
        }
        else
        {
            FsmChangeState( Item.This, 0, &Item, TRUE);
        }

        /* if we still have a valid pointer we need to free th ememory */
        if ( Item.ArgMode == GFSM_ARG_POINTER && Item.pArgData != NULL )
        {
            xFree( &Item.pArgData);
        }
    }

    LibFifoFreeExtra( &GFsm->m_EventFifo );

    return ret;
}

/*******************************************************************************
*
* FUNCTION: FsmIfGenericStateIsActive
*
* $UniqueID:$
*
* $Parm:TL_GFSM_THREAD* GFsm$
* a pointer to the GFSM structure
* $End$
*
* $Parm:UINT8 nState$
* state enum of this GFSM instance
* $End$
*
* $Description$
* Test given state is active or not. If one state is active, all its parent
* states are also active.
* $End$
*******************************************************************************/
/*$Function:GFSM Provider Interface:$*/
BOOLEAN FsmIfGenericStateIsActive( TI_GENERIC* This, UINT8 nState )
{
    BOOLEAN bActive = FALSE;

    /* 1) check that we have a valid This to check */
    if ( !IsThisValid(This) )
    {
        os_assert( FALSE, ("The instance is not valid"));
    }
    /* 2) check to see if we are in the same task as the Thread was created in*/
    else if ( This->ThisInst.Thread->m_pTask != FsmGetCurrentTask() )
    {
        os_assert( FALSE, ("you can only attach a object within the same task and thread"));
    }
    else
    {
        UINT8 state;    /* state router */
        for( state = This->ThisInst.CurrentState;
             state != s_ROOT;
             state = This->ThisClass->StateInfo[state].ParentId )
        {
            if( state == nState )
            { /* got it */
                bActive = TRUE;
                break;
            }
        }
    }

    /* return value */
    return bActive;
}

/*******************************************************************************
*
* MACRO: G_TRUE
*
* $UniqueID:3CD2B98800E2$
*
* <C_GENERIC* This>
* This is a pointer to a generic class.
* 
* <UINT8 Qual>
* This is the qualify value
* 
* RETURN: BOOLEAN
* returns true if the guard condition is valid
*
* $Description$
* This is the default gaurd used by the generic code generator. This function
* always returns TRUE
* $End$
*******************************************************************************/
START_PUBLIC_GUARD ( G_TRUE )
{
    return ( 1 );
}
END_PUBLIC_GUARD

/*******************************************************************************
*
* MACRO: G_FALSE
*
* $UniqueID:3CD2B9880151$
*
* <C_GENERIC* This>
* This is a pointer to a generic class.
* 
* <UINT8 Qual>
* This is the qualify value
* 
* RETURN: BOOLEAN
* returns true if the guard condition is valid
*
* $Description$
* This is the oposite of G_TRUE and will always return FALSE
* $End$
*******************************************************************************/
START_PUBLIC_GUARD ( G_FALSE )
{
    return ( 0 );
}
END_PUBLIC_GUARD

/*******************************************************************************
*
* MACRO: A_NULL
*
* $UniqueID:3CD2B98801BF$
*
* <C_GENERIC* This>
* This is a pointer to a generic class.
* 
* <UINT8 Qual>
* This is the qualify value
*
* $Description$
* This is the default action used by the generic code generator. This function
* performs no action
* $End$
*******************************************************************************/
START_PUBLIC_ACTION ( A_NULL )
{
}
END_PUBLIC_ACTION


/* *************************************************************************** */
/* *********************************** END *********************************** */
/* *************************************************************************** */

