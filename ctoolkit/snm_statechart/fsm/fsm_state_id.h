#ifndef STATE_ID_H_
#define STATE_ID_H_

/* Ignore other macros that will not be processed here at all */
#include "fsm_undef.h"

/* Pass 1: build a public enum of all states */
#undef  STATE
#define STATE(state)    STATE_##state,

typedef enum
{
    STATE_INVALID,          /* Default struct initialiser is 0, so do not use */
    #include "test1.fsm"
    STATE_LAST
} state_id_t;

#define STATE_MIN (STATE_INVALID + 1)
#define STATE_MAX (STATE_LAST    - 1)

#endif /*STATE_ID_H_*/
