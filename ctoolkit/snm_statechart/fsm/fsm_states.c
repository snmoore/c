#include "fsm_state.h"      /* For state_t */
#include "fsm_event_id.h"   /* For EVENT_* enum */

/*  Ignore other macros that will not be processed here at all */
#include "fsm_undef.h"

/* Pass 1: create a state structure for each state */
#undef  STATE
#undef  TRANSITION
#undef  STATE_END

//#define STATE(state)        static state_t state = { #state,
//#define TRANSITION(event)   EVENT_##event
//#define STATE_END           };

#define STATE(state)        static state_t state = { #state, {
#define TRANSITION(event)   EVENT_##event,
#define STATE_END           } };

#include "test1.fsm"

/* Create an invalid state */
static state_t StateInvalid = { "StateInvalid", 0 };

/*  Pass 2: build a public table of all states */
#undef  STATE
#undef  TRANSITION
#undef  STATE_END

#define STATE(state)        &state,
#define TRANSITION(event)
#define STATE_END

state_t *StateTable[] =
{
    &StateInvalid,          /* Default struct initialiser is 0, so do not use */
    #include "test1.fsm"
};
