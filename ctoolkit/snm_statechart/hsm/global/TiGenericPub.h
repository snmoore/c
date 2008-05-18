/* *************************************************************************** */
/* ****************************** HEADER FILES ******************************* */
/* *************************************************************************** */
#include "mrdtypes.h"
#include "FifoPub.h"
#include "ArrayPub.h"


/* PUBLIC EVENTS Functions */
#define START_PUBLIC_EVENT( name ) enum { ESTART_##name = (name##_ID << 8) + 0x80,
#define ADD_PUBLIC_EVENT( event ) event,
#define ADD_PUBLIC_COMMENT( comment )
#define END_PUBLIC_EVENT( name ) EEND_##name };

/* Public Actions and Guards */
#define DECLARE_PUBLIC_ACTION( Name ) extern void Name##_FNC ( struct TI_GENERIC_s *This, UINT8 Qual, TS_GFSM_ARG *pArg );
#define DECLARE_PUBLIC_GUARD( Name )  extern BOOLEAN Name ( struct TI_GENERIC_s * This, UINT8 Qual );

/* Allow each class to generate their own class Id
** These Ids must not conflict and be within the range 0x0001 to 0xFFFE */
#define GEN_DECLARE_CLASS_ID( Name, Id ) \
    extern const TI_GENERIC_CLASS Name##_CLASS_INFO; \
    enum { Name##_ID = Id };

/* generate a list of class types IDs */
typedef enum
{
    #define DEFINE_CLASS(a) a##_ID,
    #include "TiGenericDef.m"
    CLASS_ID_MAX
};

typedef UINT16 TI_GENERIC_CLASS_ID;
typedef struct _TS_GFSM_ARG         TS_GFSM_ARG;

/*$End$*/

/* *************************************************************************** */
/* ********************** INSTANCE STRUCTURE DEFINITION ********************** */
/* *************************************************************************** */
#ifndef TI_GENERIC_already_defined
#define TI_GENERIC_already_defined
typedef struct TI_GENERIC_s TI_GENERIC;
#endif

/* *************************************************************************** */
/* ************************ PUBLIC EVENT DEFINITIONS ************************* */
/* *************************************************************************** */
START_PUBLIC_EVENT        ( TI_GENERIC )
    /*$UniqueID:3D93FD93034C$*/
    ADD_PUBLIC_EVENT      ( E_ACCEPT )
       ADD_PUBLIC_COMMENT ((This is a global event which is normally used to indicate that the))
       ADD_PUBLIC_COMMENT ((user or class has accepted an action and needs to inform its parent))

    /*$UniqueID:3D93FD940087$*/
    ADD_PUBLIC_EVENT      ( E_CANCEL )
       ADD_PUBLIC_COMMENT ((This is a global event which is normally used to indicate that the))
       ADD_PUBLIC_COMMENT ((user or class has terminated without completing any actions))

    /*$UniqueID:3D93FD94011D$*/
    ADD_PUBLIC_EVENT      ( E_DONE )
       ADD_PUBLIC_COMMENT ((This is a global event which is normally used to indicate that the))
       ADD_PUBLIC_COMMENT ((user or class has finished completing any action required))

    /*$UniqueID:3D93FD940267$*/
    ADD_PUBLIC_EVENT      ( E_GEN_FSM_RESET )
       ADD_PUBLIC_COMMENT ((This is a global event which is only used by the GFSM itself.))
       ADD_PUBLIC_COMMENT ((Do not use this event))

    /*$UniqueID:3D93FD94038A$*/
    ADD_PUBLIC_EVENT      ( E_NULL )
       ADD_PUBLIC_COMMENT ((This is a global event which is used to allow thw class to pass))
       ADD_PUBLIC_COMMENT ((an event in to the state machine and for the state machine to ignore))
       ADD_PUBLIC_COMMENT ((it ))

END_PUBLIC_EVENT          ( TI_GENERIC )

/* *************************************************************************** */
/* ****************************** PUBLIC MS API ****************************** */
/* *************************************************************************** */

/* *************************************************************************** */
/* ****************************** PUBLIC ACTIONS ***************************** */
/* *************************************************************************** */
DECLARE_PUBLIC_ACTION ( A_NULL )

/* *************************************************************************** */
/* ****************************** PUBLIC GUARDS ****************************** */
/* *************************************************************************** */
DECLARE_PUBLIC_GUARD ( G_TRUE )
DECLARE_PUBLIC_GUARD ( G_FALSE )

/* *************************************************************************** */
/* ********************** PRE CODE GENERATOR DEFINITIONS ********************* */
/* *************************************************************************** */
/*$PreCodeGen$*/


/* *************************************************************************** */
/* ******************************** ENUMS ************************************ */
/* *************************************************************************** */


#undef GEN_STATE_CODE
#undef GEN_STATE_CODE_ENUM

/* the following two constants should be a power of 2 to inprove speed */
#define MAX_NUM_OF_TI_GENERIC_INSTANCES    (1<<5) /* the max number of instances allowed per thread*/
#define MAX_NUM_OF_TI_GENERIC_QUEUE_EVENTS (1<<4) /* the MIN number of queued events per thread*/

#define s_ROOT 0xFF
#define s_NULL 0xFF

#define UNATTACHED_INSTANCE {GFSM_UNATTACHED,0,0,NULL, NULL, NULL, NULL }, {&CLASS_INFO}
#define CONSTANT_INSTANCE   {GFSM_CONSTANT,0,0,NULL, NULL, NULL, NULL }, {&CLASS_INFO}

#define DEFAULT_CLASS_TYPE   0
#define DYNAMIC_CLASS_TYPE   1
#define STATIC_CLASS_TYPE    2
#define CONSTANT_CLASS_TYPE  3
#define STRUCTURE_CLASS_TYPE 4
#define INTERFACE_CLASS_TYPE 4 /* this is treated the same as structures */

#define GEN_V2_00 200
#define GEN_V2_01 201

/*                       [  [  [   7     +   4       -1]  /     4       ]  *     4         ] */
#define SIZE_OF_INT( a ) (  (  (sizeof(a)+sizeof(int)-1)  /  sizeof(int))   *sizeof(int)   )

/* Register the class id and class info structure */
#define REGISTER_CLASS( Name ) FsmIfRegisterClass( Name##_ID, &Name##_CLASS_INFO )


/* PUBLIC and PRIVATE GUARD Functions */
#define DECLARE_PRIVATE_GUARD( Name ) static BOOLEAN Name ( TI_GENERIC * This, UINT8 Qual );
#define DECLARE_PUBLIC_GAURD( Name ) extern BOOLEAN Name ( TI_GENERIC * This, UINT8 Qual );
#define START_PUBLIC_GAURD( Name ) BOOLEAN Name ( TI_GENERIC *This, UINT8 Qual ) {{
#define END_PUBLIC_GAURD }}
#define START_PRIVATE_GAURD( Name ) \
static BOOLEAN Name ( TI_GENERIC *THIS_PTR, UINT8 Qual ) \
{ \
    CLASS_TYPE *This = (CLASS_TYPE*)THIS_PTR; \
    os_assert( This->ThisClass->type == CLASS_ID, ("Incorrect Class") ); \
    os_assert( IsThisValid(This), ("Instance not valid") );
#define END_PRIVATE_GAURD }

#define START_PUBLIC_GUARD( Name ) BOOLEAN Name ( TI_GENERIC *This, UINT8 Qual ) {{
#define END_PUBLIC_GUARD }}
#define START_PRIVATE_GUARD( Name ) \
static BOOLEAN Name ( TI_GENERIC *THIS_PTR, UINT8 Qual ) \
{ \
    CLASS_TYPE *This = (CLASS_TYPE*)THIS_PTR; \
    os_assert( This->ThisClass->type == CLASS_ID, ("Incorrect Class") ); \
    os_assert( IsThisValid(This), ("Instance not valid") );
#define END_PRIVATE_GUARD }

/* PUBLIC and PRIVATE ACTIONS Functions */
#define DECLARE_PRIVATE_ACTION( Name) static void Name##_FNC ( TI_GENERIC *THIS_PTR, UINT8 Qual, TS_GFSM_ARG *pArg );
#define START_PUBLIC_ACTION( Name ) void Name##_FNC ( TI_GENERIC *This, UINT8 Qual, TS_GFSM_ARG *pArg ) {{
#define END_PUBLIC_ACTION }}
#define START_PRIVATE_ACTION( Name ) \
/*lint -save -e528 */ /* Don't mind that action fns don't seem to be called. */ \
static void Name##_FNC ( TI_GENERIC *THIS_PTR, UINT8 Qual, TS_GFSM_ARG *pArg ) \
{ \
    /*lint -save -e740 */ /* Don't mind the cast. */ \
    CLASS_TYPE *This = (CLASS_TYPE*)THIS_PTR; \
    /*lint -restore */ \
    os_assert( This->ThisClass->type == CLASS_ID, ("Incorrect Class") ); \
    os_assert( IsThisValid(This), ("Instance not valid") );
#define END_PRIVATE_ACTION }
/*lint -restore */ /* Turn off -e528 disabling above. */


/* STANDARD Class Functions */
#define START_CLASS_CONFIGURE static void Configure( UINT8 Mode ) {
#define END_CLASS_CONFIGURE }
#define START_CLASS_DECONFIGURE static void DeConfigure( UINT8 Mode ) {
#define END_CLASS_DECONFIGURE }
#define START_CLASS_NEW static void New( TI_GENERIC * GenericThis, void* ParentData ) { \
/*lint -save -e740 */ /* unusual pointer cast */ \
CLASS_TYPE* This = (CLASS_TYPE*)GenericThis; \
/*lint -restore */
#define END_CLASS_NEW }
#define START_CLASS_DELETE static void Delete( TI_GENERIC * GenericThis ) \
/*lint -save -e740 */ /* unusual pointer cast */ \
{ CLASS_TYPE* This = (CLASS_TYPE*)GenericThis; \
/*lint -restore */
#define END_CLASS_DELETE }
#define START_CLASS_PROCESS_SIGNAL static BOOLEAN ProcessSignal( TI_GENERIC * GenericThis, void* Signal, int Mode ) \
/*lint -save -e740 */ /* unusual pointer cast */ \
{ CLASS_TYPE* This = (CLASS_TYPE*)GenericThis; \
/*lint -restore */
#define END_CLASS_PROCESS_SIGNAL }

/* NOTE if we require more RAM we can lose this parameter and just type cast XXXX to TI_GENERIC */
/*#define GetThis( THIS_PTR ) ((TI_GENERIC*)(THIS_PTR))*/
#define GetThis( THIS_PTR ) ( (THIS_PTR) ? (THIS_PTR)->ThisInst.This : NULL )

#define GetThisParent( THIS_PTR ) ((THIS_PTR)->ThisInst.Parent)
#define GetThisRoot( THIS_PTR )   ((THIS_PTR)->ThisInst.Root)
#define GetThisThread( THIS_PTR ) ((THIS_PTR)->ThisInst.Thread)
#define CastThis(THIS_PTR, Id ) ((Id*)FsmIfCheckClassId( GetThis(THIS_PTR), Id##_ID ))
#ifdef WIN32
    #define IsThisValid(THIS_PTR) ( FsmIfIsThisValid( GetThis(THIS_PTR) ) )
#else
    #define IsThisValid(THIS_PTR) ( (THIS_PTR) && (THIS_PTR)->ThisInst.Mode > GFSM_INVALID && (THIS_PTR)->ThisInst.Mode < GFSM_LAST)
#endif
#define IsThisSafeValid(THIS_PTR) ( (THIS_PTR)==NULL || IsThisValid(THIS_PTR) )

/* *************************************************************************** */
/* ******************************** TYPEDEFS ********************************* */
/* *************************************************************************** */
typedef UINT32 TS_GFSM_EVENT;
typedef UINT8  TL_STATE_ID;
typedef UINT16 TS_GFSM_HANDLE_ID;


typedef struct _TI_GENERIC_INST     TI_GENERIC_INST;
typedef struct _TI_GENERIC_CLASS    TI_GENERIC_CLASS;

typedef void (*GEN_NEW_FNC)( TI_GENERIC * GenericThis, void * ParentData);
typedef void (*GEN_DELETE_FNC)( TI_GENERIC * GenericThis );
typedef void (*GEN_CONFIG_FNC)( UINT8 Mode);
typedef void (*GEN_DECONFIG_FNC)( UINT8 Mode );
typedef void (*GEN_ACTION_FNC)( TI_GENERIC *, UINT8, TS_GFSM_ARG * );

typedef BOOLEAN (*GEN_PROC_MSG_FNC)( TI_GENERIC * GenericThis, void * Signal, int Mode );
typedef BOOLEAN (*GEN_GUARD_FNC)( TI_GENERIC *, UINT8  );

#define FsmIfGuard( This, guard, qual ) guard( (TI_GENERIC*)(This), qual )  /*lint -e(826) */
#define FsmIfAction(This, action, qual) action##_FNC( GetThis(This), qual, NULL )


typedef struct
{
    TL_STATE_ID     Id;
    TL_STATE_ID     ParentId;
    TL_STATE_ID     ChildId;
    const char      *Name;

    UINT8           EntryIndex;
    UINT8           ExitIndex;
    UINT8           InterIndex;
    UINT8           TransIndex;
} TL_GEN_STATE;

typedef struct
{
    TS_GFSM_EVENT   Event;
    UINT8           NextState;
    GEN_GUARD_FNC   GuardFnc;
    UINT8           GuardQual;
    GEN_ACTION_FNC  ActionFnc;
    UINT8           ActionQual;
} TL_GEN_TRANS;

typedef struct
{
    TS_GFSM_EVENT   Event;
    GEN_GUARD_FNC   GuardFnc;
    UINT8           GuardQual;
    GEN_ACTION_FNC  ActionFnc;
    UINT8           ActionQual;
} TL_GEN_INTERNAL;

typedef struct
{
    GEN_ACTION_FNC  ActionFnc;
    UINT8           ActionQual;
} TL_GEN_ACTIONS;

typedef enum
{
    GFSM_ARG_NONE,
    GFSM_ARG_VALUE,
    GFSM_ARG_CONST,
    GFSM_ARG_POINTER
} TS_GFSM_ARG_MODE;


struct _TS_GFSM_ARG
{
    UINT8            Qual;
    TS_GFSM_ARG_MODE Mode;
    int              Value;
    void             *pData;
};

typedef struct
{
    TI_GENERIC    *This;
    TS_GFSM_EVENT Event;
    TS_GFSM_ARG_MODE     ArgMode;
    void                *pArgData;
} TL_EVENT_QUEUE;

typedef struct
{
    TI_GENERIC        *This;
    TS_GFSM_HANDLE_ID  HandleId;
} TS_GFSM_HANDLE_ITEM;


typedef struct TL_GFSM_THREAD_s
{
    TS_ARRAY        m_InstanceArray;
    TS_FIFO         m_EventFifo;
    UINT8           m_MaxInstanceCount;
    UINT8           m_MaxEventCount;
    void            *m_pTask;
} TL_GFSM_THREAD;

typedef enum
{
    GFSM_INVALID,
    GFSM_VALID,
    GFSM_UNATTACHED,
    GFSM_CONSTANT,
    GFSM_LAST
} TS_GFSM_MODE;


/* this holds any information that relates to a single instance of a class */
struct _TI_GENERIC_INST
{
    TS_GFSM_MODE            Mode;              /*1 used for self checking              */
    UINT8                   CurrentState;       /*1 the current fsm stat                */
    TS_GFSM_HANDLE_ID       HandleId;           /*2 unquie app ID for duration of HHP   */
    TI_GENERIC             *Parent;             /*4 parent of this class                */
    TI_GENERIC             *Root;               /*4 first parent of this class          */
    TL_GFSM_THREAD         *Thread;             /*4 used to hold the thread information */
/* NOTE if we require more RAM we can lose this parameter and just type cast XXXX to TI_GENERIC */
    TI_GENERIC             *This;               /*4 used to hold generic pointer to it self */
};                       /* TOTAL                20 bytes                               */

/* this holds all information that relates to a whole class */
struct _TI_GENERIC_CLASS
{                                               /*BYTES  DESCRIPTION */
    const char *        Name;                   /*4+ name of class */
    TI_GENERIC_CLASS_ID type;                   /*2  id for the class */
    UINT16              SizeOfPrivate;          /*2  size of private data required */
    UINT16              SizeOfProtected;        /*2  size of protected data required */
    UINT16              SizeOfPublic;           /*2  size of public data required */
    UINT8               MaxNumOfInstances;      /*1  max number of instances allowed */
    UINT8               ClassType;              /*1  type of class */
    GEN_NEW_FNC         NewFn;                  /*4  pointer to create new instance func */
    GEN_DELETE_FNC      DeleteFn;               /*4  pointer to destory instance func */
    GEN_CONFIG_FNC      ConfigFn;               /*4  pointer for power up function */
    GEN_DECONFIG_FNC    DeConfigFn;             /*4  pointer for power down function */

    GEN_PROC_MSG_FNC    ProcessMsgFn;           /*4  pointer to message process func */

    UINT8               EntryState;             /*1  entry state id */
    UINT8               ExitState;              /*1  exit state id */
    const TL_GEN_STATE       *StateInfo;        /*4  pointer to state list */
    const TL_GEN_ACTIONS     *EntryList;        /*4  pointer to list of entry actions */
    const TL_GEN_ACTIONS     *ExitList;         /*4  pointer to list of exit actions */
    const TL_GEN_INTERNAL    *IntList;          /*4  pointer to list of internal transaction */
    const TL_GEN_TRANS       *TransList;        /*4  pointer to list of transaction */
    UINT               *Memory;                 /*4  pointer to memory for claa alloc */
};
                                         /* TOTAL 43 bytes ROM */

#define GFSM_CREATE_DUMMY_CLASS_INFO( name ) const TI_GENERIC_CLASS name##_CLASS_INFO = \
{ #name, name##_ID, 0,0,0,0,0, NULL, NULL, NULL, NULL, NULL, 0,0, NULL, NULL, NULL, NULL, NULL, NULL }

/* *************************************************************************** */
/* ******************************** ENUMS ************************************ */
/* *************************************************************************** */
/* generate a list of class info structures IDs */
#define DEFINE_CLASS(a) extern const TI_GENERIC_CLASS a##_CLASS_INFO;
#include "TiGenericDef.m"

/* generate a list of logging types */
enum
{
    #define DEFINE_LOG_TYPE(a) a##_LOG_ID,
    #include "TiGenericDef.m"
    CLASS_LOG_TYPE_MAX
};



/* *************************************************************************** */
/* ****************************** STRUCTURES ********************************* */
/* *************************************************************************** */

/* *************************************************************************** */
/* ************************** VARIABLE DECLARATIONS ************************** */
/* *************************************************************************** */

/* *************************************************************************** */
/* ************************ PUBLIC EVENT DEFINITIONS ************************* */
/* *************************************************************************** */
/*lint -emacro((50,740,826), FsmIfDeleteInstance) */
#define FsmIfCreateInstance( Parent, Id ) /*lint -save -e826 -e740 */ (Id*)FsmIfCreateInstanceWithData( Parent->ThisInst.Thread, (TI_GENERIC *)Parent, Id##_ID, NULL ) /*lint -restore */
#define FsmIfCreateInstanceFromThread( thread, Id ) (Id*)FsmIfCreateInstanceWithData( thread, NULL, Id##_ID, NULL )
#define FsmIfAttachInstanceToThread( thread, THIS_PTR ) FsmIfGenericAttachInstanceToThreadWithData( thread, NULL, (TI_GENERIC*)THIS_PTR, NULL )
#define FsmIfAttachInstanceToParent( Parent, THIS_PTR ) FsmIfGenericAttachInstanceToThreadWithData( Parent->ThisInst.Thread, (TI_GENERIC*)Parent, (TI_GENERIC*)THIS_PTR, NULL )
#define FsmIfDeleteInstance( THIS_PTR )  FsmIfDeleteGenericInstance( &((TI_GENERIC*)(THIS_PTR)) )

#define FsmIfAddEvent(                    THIS_PTR, Event          ) FsmIfAddEventToGenericClass(         GetThis(THIS_PTR), Event )
#define FsmIfAddEventWithValue(           THIS_PTR, Event, Value   ) FsmIfAddEventToGenericClassWithData( GetThis(THIS_PTR), Event, GFSM_ARG_VALUE,   (void*)(Value) )
#define FsmIfAddEventWithPointer(         THIS_PTR, Event, Pointer ) FsmIfAddEventToGenericClassWithData( GetThis(THIS_PTR), Event, GFSM_ARG_POINTER, (Pointer) )
#define FsmIfAddEventWithConst(           THIS_PTR, Event, Const   ) FsmIfAddEventToGenericClassWithData( GetThis(THIS_PTR), Event, GFSM_ARG_CONST,   (Const) )

#define FsmIfAddEventToParent(            THIS_PTR, Event          ) FsmIfAddEventToGenericClass(         GetThisParent(THIS_PTR), Event )
#define FsmIfAddEventToParentWithValue(   THIS_PTR, Event, Value   ) FsmIfAddEventToGenericClassWithData( GetThisParent(THIS_PTR), Event, GFSM_ARG_VALUE,   (void*)(Value) )
#define FsmIfAddEventToParentWithPointer( THIS_PTR, Event, Pointer ) FsmIfAddEventToGenericClassWithData( GetThisParent(THIS_PTR), Event, GFSM_ARG_POINTER, (Pointer) )
#define FsmIfAddEventToParentWithConst(   THIS_PTR, Event, Const   ) FsmIfAddEventToGenericClassWithData( GetThisParent(THIS_PTR), Event, GFSM_ARG_CONST,   (Const) )

#define FsmIfStateIsActive( THIS_PTR, State ) FsmIfGenericStateIsActive( GetThis(THIS_PTR), State )

/*$End$*/

/* *************************************************************************** */
/* **************************** PUBLIC STRUCTURES **************************** */
/* *************************************************************************** */
/* PublicAccess Attributes */
struct TI_GENERIC_s
{
/*$InstStruct$*/
    TI_GENERIC_INST            ThisInst;
    const TI_GENERIC_CLASS*    ThisClass;
    void*                      ptr[3];
/*$end$*/
};

/* *************************************************************************** */
/* *************************** FUNCTION PROTOTYPES *************************** */
/* *************************************************************************** */
extern void* FsmGetCurrentTask(  void );
extern BOOLEAN FsmIfIsThisValid( TI_GENERIC* This );
extern TI_GENERIC_CLASS_ID FsmIfRegisterClass( TI_GENERIC_CLASS_ID Id, 
                                               const TI_GENERIC_CLASS* Info );
extern BOOLEAN FsmIfIsClassRegistered( TI_GENERIC_CLASS_ID Id );
extern TI_GENERIC* FsmIfCheckClassId( TI_GENERIC* This, TI_GENERIC_CLASS_ID Id );
extern void FsmIfConfigure(  void );
extern void FsmIfConfigureThread( TL_GFSM_THREAD* GFsm );
extern void FsmIfDeconfigureThread( TL_GFSM_THREAD* GFsm );
extern TI_GENERIC* FsmIfCreateInstanceWithData( TL_GFSM_THREAD* thread, TI_GENERIC* Parent, 
                                                TI_GENERIC_CLASS_ID Id, void* ParentData );
extern TI_GENERIC* FsmIfGenericAttachInstanceToThreadWithData( TL_GFSM_THREAD* thread, 
                                                               TI_GENERIC* Parent, 
                                                               TI_GENERIC* This, 
                                                               void* ParentData );
extern BOOLEAN FsmIfDeleteGenericInstance( TI_GENERIC** ThisPtr );
extern void FsmIfAddEventToGenericClass( TI_GENERIC* This, TS_GFSM_EVENT Event );
extern void FsmIfAddEventToGenericClassWithData( TI_GENERIC* This, TS_GFSM_EVENT Event, TS_GFSM_ARG_MODE ArgMode, const void *Arg );
extern BOOLEAN FsmIfGenericStateIsActive( TI_GENERIC* This, UINT8 nState );
extern BOOLEAN FsmIfProcessEventQueue( TL_GFSM_THREAD* GFsm );

/* *************************************************************************** */
/* *********************************** END *********************************** */
/* *************************************************************************** */
#endif

