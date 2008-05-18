#ifndef STATECHART_TABLE_TRANSITION_H_
#define STATECHART_TABLE_TRANSITION_H_


/* Statechart build pass 3: build a set of transition tables per state */
#ifdef STATECHART_BUILD_TABLES

/* 
 * For each state, build a table of transitions
 *
 * E.g. for State0 this should result in a table of the form:
 *      static const tran_t State0TransTable[] = { };
 * 
 * Later we can hook this back into State0:
 *      State.TransTable = &State0TransTable[0];
 * 
 * We put a dummy element on the end in case of a state with no transitions
 * 
 * Note that ideally the TargetState field would be a pointer to a state ie
 * &States[STATE_##state], but we have a chicken and egg situation - states
 * need to refer to transitions and vice-versa - so we use an enum into the
 * master States array here
 */
#include "statechart_undef.h"   /* Ignore unused statechart macros */

#undef  STATE
#define STATE(type, state, parent)                      \
    static tran_t state ## TransTable[] =               \
    {

#undef  TRANS
#define TRANS(type, trans, event, state, guard, action) \
        {                                               \
            #trans,                                     \
            TRANSITION_TYPE_##type,                     \
                                                        \
            EVENT_##event,                              \
            STATE_##state,                              \
                                                        \
            guard,                                      \
            action                                      \
        },
  
#undef  STATE_END
#define STATE_END                                       \
        {                                               \
            "Dummy Transition",                         \
            TRANSITION_TYPE_NORMAL,                     \
                                                        \
            EVENT_NO_EVENT,                             \
            STATE_NO_STATE,                             \
                                                        \
            NO_GUARD,                                   \
            NO_ACTION,                                  \
        }                                               \
    };

#include STATECHART_FILE
    
#endif /* STATECHART_BUILD_TABLES */


#endif /*STATECHART_TABLE_TRANSITION_H_*/
