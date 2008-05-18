#ifndef EVENT_ID_H_
#define EVENT_ID_H_

/* Ignore other macros that will not be processed here at all */
#include "fsm_undef.h"

/* Pass 1: build a public enum of all events */
#undef  EVENT
#define EVENT(event)    EVENT_##event,

typedef enum
{
    EVENT_INVALID,          /* Default struct initialiser is 0, so do not use */
    #include "test1.fsm"
    EVENT_LAST
} event_id_t;

#define EVENT_MIN (EVENT_INVALID + 1)
#define EVENT_MAX (EVENT_LAST    - 1)

#endif /*EVENT_ID_H_*/
