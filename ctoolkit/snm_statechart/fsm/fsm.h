#ifndef FSM_H_
#define FSM_H_


/* !!! EVENTS !!! */

/* Ignore other macros that will not be processed here at all */
#include "fsm_undef.h"

/* Pass 1: build a public enum of all events */
#undef  EVENT
/* #define EVENT(event)    EVENT_ FSM_NAME _##event, */

#define Str(x) x
#define Xstr(a, b, c) ##a_b_##c 
/* #define OP plus */
#define EVENT(event) Xstr(EVENT, FSM_NAME, ##event),

typedef enum
{
    EVENT_INVALID,          /* Default struct initialiser is 0, so do not use */
    #include FSM_FILE
    EVENT_LAST
} event_id_t;

#define EVENT_MIN (EVENT_INVALID + 1)
#define EVENT_MAX (EVENT_LAST    - 1)


#endif /*FSM_H_*/
