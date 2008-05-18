#ifndef STATECHART_ENUM_EVENT_H_
#define STATECHART_ENUM_EVENT_H_


/* Statechart build pass 1: build an enum of all events */
#ifdef STATECHART_BUILD_ENUMS

#include "statechart_undef.h"   /* Ignore unused statechart macros */

#undef  EVENT
#define EVENT(event)    EVENT_##event,

typedef enum
{
    #include STATECHART_FILE
    EVENT_DUMMY
} event_id_t;

#define EVENT_FIRST     (0)
#define EVENT_LAST      (EVENT_DUMMY - 1)
#define EVENT_TOTAL     (EVENT_LAST - EVENT_FIRST + 1)

#endif /* STATECHART_BUILD_ENUMS */


#endif /*STATECHART_ENUM_EVENT_H_*/
