#ifdef GEN_STATE_CODE_ENUM
#undef GEN_STATE_CODE_ENUM

#if ENTRY_STATE == s_NULL 
#error this should not be compiled in since you have no state machine
#endif

/*******************************************************************************
*                             EVENT IDs
*
* DESCRIPTION:
* This generates a set of enums which are used for events. Each event is made
* up of a Class ID, internal/external type and the event number. The Class ID
* is used to ensure that the correct event is processed by each class. The 
* external bit is used to determine if the event is for internal use only or
* if it can be used by other class's FSMs.
*
* 8 bits        1 Bit       7 Bits
* ----------------------------------------------
* | Class Id        | external |   event num   |
* ----------------------------------------------
*
* This defines all the internal events. The external events are declared in the
* Pub.h file as constants
*
* where class Id = 1
*   e_start      = class Id << 8 = 0x10
*   e_Event1     = 0x10
*   e_Event2     = 0x11
*       :
*   e_Event6     = 0x12
*   e_Event7     = 0x13
*   s_MAX_EVENTS = 0x14
*
*******************************************************************************/
enum
{
    GE_EVT=(CLASS_ID<<8)-1,
    #define GEN_DECLARE_EVENT( e_Event ) e_Event,
    #include MACRO_FILE
    e_MAX_EVENTS
};


#endif

#ifdef GEN_STATE_CODE
#undef GEN_STATE_CODE

#if ENTRY_STATE == s_NULL 
#error this should not be compiled in since you have no state machine
#endif



/*******************************************************************************
*                             STATE IDs
*
* DESCRIPTION:
* This generates a set of enums which are used to repersent each state within
* the class's FSM.
*
*   s_State1     = 0
*   s_State2     = 1
*       :
*   s_State6     = 5
*   s_State7     = 6
*   s_MAX_STATES = 7
*
*******************************************************************************/
enum
{
    #define GEN_STA_START( type, s_ParentState, s_State, s_ChildState ) s_State,
    #include MACRO_FILE
    s_MAX_STATES
};


/*******************************************************************************
*                             ACTIONS
*
* DESCRIPTION:
* This generates a set of enums which we can use to identify any Action's
* Functions. This allows us to store a simple UINT8 ( 1 byte ) instead of
* a function pointer ( 4 bytes ) throughout the rest of the FSM
*
*      enum             Function Ptr Array
*   a_Act1_ID = 0       | a_Act1_FNC * |
*   a_Act2_ID = 1       | a_Act2_FNC * |
*        :                      :
*   a_Act5_ID = 6       | a_Act5_FNC * |
*   a_Act6_ID = 7       | a_Act6_FNC * |
*   a_MAX_ACTIONS       |   NULL       |
*
*******************************************************************************/
#if 0
#define GEN_DECLARE_ACTION( a_Action ) void a_Action##_FNC ( TI_GENERIC *this, UINT8 Qual, TS_GFSM_ARG *pArg );
#include MACRO_FILE
enum
{
    #define GEN_DECLARE_ACTION( a_Action ) a_Action##_ID,
    #include MACRO_FILE
    a_MAX_ACTIONS
};
const GEN_ACTION_FNC GenActions[a_MAX_ACTIONS+1] =
{
    #define GEN_DECLARE_ACTION( a_Action ) a_Action##_FNC,
    #include MACRO_FILE
   NULL
};
#endif

/* ANF00000991 
 * The correct static or non-static prototypes are generated correctly via the
 * DECLARE_PRIVATE_ACTION or DECLARE_PUBLIC_ACTION macros in the *.c/h files
 */


/*******************************************************************************
*                             GUARDS
*
* DESCRIPTION:
* This generates a set of externs to all the guards used within the FSM
*
* eg
* BOOLEAN g_Valid( TI_GENERIC *This, UINT8 Qual );
* BOOLEAN g_IsKey( TI_GENERIC *This, UINT8 Qual );
*
*******************************************************************************/

/* ANF00000991 
 * The correct static or non-static prototypes are generated correctly via the
 * DECLARE_PRIVATE_GUARD or DECLARE_PUBLIC_GUARD macros in the *.c/h files
 */


/*******************************************************************************
*                          TRANSACTION LIST
*
* DESCRIPTION:
* To allow each state to contain as many transactions as required ( max 255 ) we
* generate a list of all the transactions within the FSM, and store
* an index to the first transaction attached to each state. From this information
* and the information stored on the next state we can extract all the transactions
*
* Index to first trans On State                 List of all transactions
*   GR_TRA_s_Sta1   0 --------------------------------> | Trans3 |
*                                                       | Trans0 |
*   GR_TRA_s_Sta2   2 --------------------------------> | Trans2 |
*   GR_TRA_s_Sta3   2 ---------------/                  | Trans2 |
*                                                       | Trans2 |
*   GR_TRA_s_Sta5   5 --------------------------------> | Trans3 |
*   GR_TRA_LAST_TRA 6---------------------------------> |    0   |
*
*******************************************************************************/
enum
{
    #define GEN_STA_START( type, s_ParentState, s_State, s_ChildState ) GR_TRA_##s_State, GE_TRA_##s_State = GR_TRA_##s_State
    #define GEN_STA_ADD_TRA( TrgState, Event, GuardFn, GuardQual, ActionFn, ActionQual ) +1
    #define GEN_STA_END -1,
    #include MACRO_FILE
    GR_TRA_LAST_TRA
};

static const TL_GEN_TRANS GenTrans[GR_TRA_LAST_TRA+1] =
{
    #define GEN_STA_ADD_TRA( TrgState, Event, GuardFn, GuardQual, ActionFn, ActionQual ) \
        { Event, TrgState, GuardFn, GuardQual, ActionFn##_FNC, ActionQual  },
    #include MACRO_FILE
    0
};


/*******************************************************************************
*                          INTERNAL TRANSACTION LIST
*
* DESCRIPTION:
* To allow each state to contain as many internal transactions as required 
* ( max 255 ). We generate a list of all the transactions within the FSM, and store
* an index to the first internal transaction attached to each state. From this information
* and the information stored on the next state we can extract all the internal transactions
*
* Index to first int trans On State              List of all internal transactions
*   GR_INT_s_Sta1   0 --------------------------------> | Int Trans1 |
*                                                       | Int Trans4 |
*   GR_INT_s_Sta2   2 --------------------------------> | Int Trans1 |
*   GR_INT_s_Sta3   2 ---------------/                  | Int Trans4 |
*                                                       | Int Trans2 |
*   GR_INT_s_Sta5   5 --------------------------------> | Int Trans3 |
*   GR_INT_LAST_INT 6---------------------------------> |    0       |
*
*******************************************************************************/
enum
{
    #define GEN_STA_START( type, s_ParentState, s_State, s_ChildState ) GR_INT_##s_State, GE_INT_##s_State = GR_INT_##s_State
    #define GEN_STA_ADD_INT( Event, GuardFn, GuardQual, ActionFn, ActionQual ) +1
    #define GEN_STA_END -1,
    #include MACRO_FILE
    GR_INT_LAST_INT
};
static const TL_GEN_INTERNAL GenInterTrans[GR_INT_LAST_INT+1] =
{
    #define GEN_STA_ADD_INT( Event, GuardFn, GuardQual, ActionFn, ActionQual ) \
        { Event, GuardFn, GuardQual, ActionFn##_FNC, ActionQual  },
    #include MACRO_FILE
    0
};


/*******************************************************************************
*                          ENTRY ACTIONS LIST
*
* DESCRIPTION:
* To allow each state to contain as many entry actions as required 
* ( max 255 ). We generate a list of all the entry actions within the FSM, and store
* an index to the first entry actions attached to each state. From this information
* and the information stored on the next state we can extract all the entry actions.
* To save on memory we store each action and qual inside a single UINT8 array, 
* otherwise we would waste 4 bytes ( due to padding ) per action. This also ensures
* that the qual is a value between 0 and 255. To retieve the correct action/qual
* you will need to use the following lines
*
* action = ActionList[index*2]
* qual   = ActionList[(index*2)+1]
*  
*    
* Index to first entry action On State              List of all entry actions
*   GR_ENT_s_Sta1   0 --------------------------------> | a_Act3_ID |
*                                                       |     1     |
*   GR_ENT_s_Sta2   1 --------------------------------> | a_Act1_ID |
*                                                       |     0     |
*                                                       | a_Act7_ID |
*                                                       |     0     |
*   GR_ENT_s_Sta3   3 --------------------------------> | a_Act1_ID |
*                                                       |     0     |
*                                                       | a_Act3_ID |
*                                                       |     1     |
*   GR_ENT_LAST_ENT 5 --------------------------------> |     0     |
*                                                       |     0     |
*
*******************************************************************************/
enum
{
    #define GEN_STA_START( type, s_ParentState, s_State, s_ChildState ) GR_ENT_##s_State, GE_ENT_##s_State = GR_ENT_##s_State
    #define GEN_STA_ADD_ENTRY( ActionFn, ActionQual ) +1
    #define GEN_STA_END -1,
    #include MACRO_FILE
    GR_ENT_LAST_ENT
};
static const TL_GEN_ACTIONS GenEntryAct[GR_ENT_LAST_ENT+1] =
{
    #define GEN_STA_ADD_ENTRY( ActionFn, ActionQual ) { ActionFn##_FNC, ActionQual },
    #include MACRO_FILE
    0
};


/*******************************************************************************
*                          EXIT ACTIONS LIST
*
* DESCRIPTION:
* To allow each state to contain as many exit actions as required 
* ( max 255 ). We generate a list of all the exit actions within the FSM, and store
* an index to the first exit actions attached to each state. From this information
* and the information stored on the next state we can extract all the exit actions.
* To save on memory we store each action and qual inside a single UINT8 array, 
* otherwise we would waste 4 bytes ( due to padding ) per action. This also ensures
* that the qual is a value between 0 and 255. To retieve the correct action/qual
* you will need to use the following lines
*
* action = ActionList[index*2]
* qual   = ActionList[(index*2)+1]
*  
*    
* Index to first exit action On State              List of all exit actions
*   GR_EXT_s_Sta1   0 --------------------------------> | a_Act3_ID |
*                                                       |     1     |
*   GR_EXT_s_Sta2   1 --------------------------------> | a_Act1_ID |
*                                                       |     0     |
*                                                       | a_Act7_ID |
*                                                       |     0     |
*   GR_EXT_s_Sta3   3 --------------------------------> | a_Act1_ID |
*                                                       |     0     |
*                                                       | a_Act3_ID |
*                                                       |     1     |
*   GR_EXT_LAST_EXT 5 --------------------------------> |     0     |
*                                                       |     0     |
*
*******************************************************************************/
enum
{
    #define GEN_STA_START( type, s_ParentState, s_State, s_ChildState ) GR_EXT_##s_State, GE_EXT_##s_State = GR_EXT_##s_State
    #define GEN_STA_ADD_EXIT( ActionFn, ActionQual ) +1
    #define GEN_STA_END -1,
    #include MACRO_FILE
    GR_EXT_LAST_EXT
};
static const TL_GEN_ACTIONS GenExitAct[GR_EXT_LAST_EXT+1] =
{
    #define GEN_STA_ADD_EXIT( ActionFn, ActionQual ) { ActionFn##_FNC, ActionQual },
    #include MACRO_FILE
    0
};


/*******************************************************************************
*                          STATE LIST
*
* DESCRIPTION:
* This holds the information held on each sate. This includes the follow
*
*   State Id (DEBUG)
*   State Name (DEBUG)
*
*   Parent Id
*   Index to first Entry action
*   Index to first Exit action
*   Index to first internal transition
*   Index to first transition
* 
*
*******************************************************************************/
static const TL_GEN_STATE GenState[] =
{
    #define GEN_STA_START( type, s_ParentState, s_State, s_ChildState ) \
        {s_State, s_ParentState, s_ChildState, #s_State, GR_ENT_##s_State, GR_EXT_##s_State, GR_INT_##s_State, GR_TRA_##s_State },
    #include MACRO_FILE
    {s_ROOT, s_ROOT, s_ROOT, NULL, GR_ENT_LAST_ENT, GR_EXT_LAST_EXT, GR_INT_LAST_INT, GR_TRA_LAST_TRA }
};


#endif



#ifdef GEN_DEFINE_MACROS
#undef GEN_DEFINE_MACROS

    #ifndef GEN_STA_START
    #define GEN_STA_START( type, s_ParentState, s_State, s_ChildState )
    #endif

    #ifndef GEN_STA_COMMENT
    #define GEN_STA_COMMENT( comment )  /* #comment */
    #endif

    #ifndef GEN_STA_ADD_ENTRY
    #define GEN_STA_ADD_ENTRY( ActionFn, ActionQual )
    #endif
    #ifndef GEN_STA_ADD_EXIT
    #define GEN_STA_ADD_EXIT( ActionFn, ActionQual )
    #endif
    #ifndef GEN_STA_ADD_INT
    #define GEN_STA_ADD_INT( Event, GuardFn, GuardQual, ActionFn, ActionQual )
    #endif


    #ifndef GEN_STA_ADD_TRA
    #define GEN_STA_ADD_TRA( TrgState, Event, GuardFn, GuardQual, ActionFn, ActionQual )
    #endif
    #ifndef GEN_STA_TRA_COMMENT
    #define GEN_STA_TRA_COMMENT( comment )
    #endif

    #ifndef GEN_STA_END
    #define GEN_STA_END
    #endif

    #ifndef GEN_DECLARE_EVENT
    #define GEN_DECLARE_EVENT( e_Event )
    #endif

    #ifndef GEN_DECLARE_ACTION
    #define GEN_DECLARE_ACTION( a_Action )
    #endif

    #ifndef GEN_DECLARE_CLASS
    #define GEN_DECLARE_CLASS( g_Guard )
    #endif

#endif

#ifdef GEN_UNDEFINE_MACROS
#undef GEN_UNDEFINE_MACROS
#ifndef GEN_ABORT_UNDEFINE_MACROS
    #undef GEN_STA_START
    #undef GEN_STA_COMMENT
    #undef GEN_STA_ADD_ENTRY
    #undef GEN_STA_ADD_EXIT
    #undef GEN_STA_ADD_INT
    #undef GEN_STA_ADD_TRA
    #undef GEN_STA_TRA_COMMENT
    #undef GEN_STA_END
    #undef GEN_DECLARE_EVENT
    #undef GEN_DECLARE_ACTION
    #undef GEN_DECLARE_CLASS
#endif
#endif


#ifdef GEN_CLASS_INFO

#if GFSM_TYPE == GEN_V2_00
    /* we have found the correct generic fsm version */
#else
    #error you are using the wrong generic FSM. Try re-generating the source code again
#endif

static void Configure( UINT8 Mode );
static void DeConfigure( UINT8 Mode );
#if MAXS_NUM_INSTANCES != 0
static void New( TI_GENERIC * GenericThis, void *ParentData );
static void Delete( TI_GENERIC * GenericThis );
#endif
static BOOLEAN ProcessSignal( TI_GENERIC * GenericThis, void* Signal, int Mode );

#if STEREOTYPE == DEFAULT_CLASS_TYPE && MAXS_NUM_INSTANCES != 0
/* if the memory is defined at build time we need to define a array large enough that it can hold all the
instances defined. We use a UINT to make sure it starts on a word boundary */
static UINT InstanceMemory[MAXS_NUM_INSTANCES][(SIZE_OF_PRIVATE+SIZE_OF_PROTECTED+SIZE_OF_PUBLIC+SIZE_OF_INT(TI_GENERIC))/sizeof(UINT)];
#endif


const TI_GENERIC_CLASS CLASS_INFO = 
{                                               /*BYTES  DESCRIPTION*/
    CLASS_NAME,                     /*4+ name of class */
    CLASS_ID,                       /*2  id for the class */

    SIZE_OF_PRIVATE,                /*2  size of private data required */
    SIZE_OF_PROTECTED,              /*2  size of protected data required */
    SIZE_OF_PUBLIC,                 /*2  size of public data required */
    MAXS_NUM_INSTANCES,             /*1  max number of instances allowed */
    STEREOTYPE,                     /*1  type of class */

#if MAXS_NUM_INSTANCES != 0
    New,                            /*4  pointer to create new instance func */
    Delete,                         /*4  pointer to destory instance func */
    Configure,                      /*4  pointer for power up function */
    DeConfigure,                    /*4  pointer for power down function */
    ProcessSignal,                  /*4  pointer to message process func */
#else
    NULL,
    NULL,
    Configure,                      /*4  pointer for power up function */
    DeConfigure,                    /*4  pointer for power down function */
    NULL,
#endif

    ENTRY_STATE,                    /*1  entry state id */
    EXIT_STATE,                     /*1  exit state id */

#if ENTRY_STATE != s_NULL 
    GenState,                       /*4  pointer to state list */
    GenEntryAct,                    /*4  pointer to list of entry actions */
    GenExitAct,                     /*4  pointer to list of exit actions */
    GenInterTrans,                  /*4  pointer to list of internal transaction */
    GenTrans,                       /*4  pointer to list of transaction */
#else
    NULL,                           /*4  pointer to state list */
    NULL,                           /*4  pointer to list of entry actions */
    NULL,                           /*4  pointer to list of exit actions */
    NULL,                           /*4  pointer to list of internal transaction */
    NULL,                           /*4  pointer to list of transaction */
#endif

#if STEREOTYPE == DEFAULT_CLASS_TYPE && MAXS_NUM_INSTANCES != 0
    InstanceMemory[0]
#else
    NULL
#endif


};



#endif
