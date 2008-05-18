#include "fsm_event.h"  /* For event_t */

/*  Ignore other macros that will not be processed here at all */
#include "fsm_undef.h"

/* Pass 1: create an event structure for each event */
#undef  EVENT 
#define EVENT(event)     static event_t event = { #event };

#include "test1.fsm"

/* Create an invalid event */
static event_t EventInvalid = { "EventInvalid" };

/* Pass 2: build a public table of all events */
#undef  EVENT
#define EVENT(event)     &event,

event_t *EventTable[] =
{
    &EventInvalid,          /* Default struct initialiser is 0, so do not use */
    #include "test1.fsm"
};
