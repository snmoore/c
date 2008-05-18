#ifndef STATECHART_TYPES_H_
#define STATECHART_TYPES_H_


/*
 * Valid actions, events, guards, transitions, states etc all start at 0
 * 
 * The invalid actions etc need to be consistent across all instances of
 * statecharts, hence they need to be here in the public interface, rather than
 * being generated in the statechart_enum_*.h header files
 * 
 * In the *.sc file you can use short versions of these names ie NO_ACTION etc
 */
#define ACTION_NO_ACTION    -1      /* See action_id_t     */
#define EVENT_NO_EVENT      -1      /* See event_id_t      */
#define GUARD_NO_GUARD      -1      /* See guard_id_t      */
#define TRANS_NO_TRANSITION -1      /* See transition_id_t */
#define STATE_NO_STATE      -1      /* See state_id_t      */
#define STATE_NO_PARENT     -1
#define STATE_NO_CHILD      -1

#define NO_ACTION           NULL
#define NO_GUARD            NULL
#define NO_STATE            NULL

/* 
 * Miscellaneous
 */
#define NO_QUAL (0)

typedef enum bool
{
    FALSE,
    TRUE
} bool_t;

/*
 * Actions
 */
typedef void (*action_t)(unsigned int Qual);

typedef struct actions              /* Table of action functions; 8 bytes */
{
    int             Total;
    action_t       *Array;
} actions_t;

/*
 * Guards
 */
typedef void (*guard_t)(unsigned int Qual);

typedef struct guards               /* Table of guard functions; 8 bytes */
{
    int             Total;
    action_t       *Array;
} guards_t;

/*
 * Transitions
 */
typedef enum tran_type
{
    TRANSITION_TYPE_INITIAL,        /* Initial trans within a composite state */
    TRANSITION_TYPE_NORMAL,         /* Normal transition between states       */
    TRANSITION_TYPE_SELF,           /* Self transition ie no state change     */
    TRANSITION_TYPE_INTERNAL        /* Like self, do no entry & exit actions  */
} tran_type_t;

typedef struct tran {               /* A transition; 24 bytes */
    char           *Name;
    tran_type_t     Type;
    
    int             Event;
    int             TargetState;
    
    guard_t         Guard;
    action_t        Action;
} tran_t;

typedef struct trans                /* Table of transitions; 8 bytes */
{
    int             Total;
    tran_t         *Array;
} trans_t;

/*
 * States
 */
typedef enum state_type
{
    STATE_TYPE_TOP,                 /* The (single) top state in a statechart */
    STATE_TYPE_SIMPLE,              /* A state with no children               */
    STATE_TYPE_COMPOSITE,           /* A state with children                  */
    STATE_TYPE_PSEUDO               /* Pseudo-state; currenty unused          */
} state_type_t;

typedef struct state state_t;
struct state                        /* A state; 28 bytes */
{
    char           *Name;
    state_type_t    Type;
    
    state_t        *Parent;
    state_t        *Current;
    
    actions_t       EntryTable;
    actions_t       ExitTable;
    trans_t         TranTable;
};

typedef struct states               /* Table of states; 8 bytes */
{
    int             Total;
    state_t        *Array;
} states_t;

/*
 * Statechart
 */
typedef struct statechart_tag       /* The statechart; 12 bytes */
{
    state_t        *Top;
    state_t        *Current;

    states_t        StateTable;
} statechart_t;

#endif /*STATECHART_TYPES_H_*/
