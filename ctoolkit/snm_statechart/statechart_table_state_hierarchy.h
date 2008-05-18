#ifndef STATECHART_TABLE_STATE_HIERARCHY_H_
#define STATECHART_TABLE_STATE_HIERARCHY_H_


/* Statechart build pass 3: build a set of child state tables per state */
#ifdef STATECHART_BUILD_TABLES

/* 
 * For each state, build a table of child states
 *
 * E.g. for State0 this should result in a table of the form:
 *      static const transition_t State0TransTable[] = { };
 * 
 * Later we can hook this back into State0:
 *      State.TransTable = &State0TransTable[0];
 * 
 * We put a dummy element on the end in case of a state with no transitions
 */
#include "statechart_undef.h"   /* Ignore unused statechart macros */

#undef  STATE
#define STATE(type, state, parent, child)                                   \
    static const transition_t state ## TransTable[] =                       \
    {

#undef  TRANS
#define TRANS(type,trans,event,state,guard,guard_qual,action,action_qual)   \
        {                                                                   \
            EVENT_##event,                                                  \
            STATE_##state,                                                  \
            GUARD_##guard,                                                  \
            guard_qual,                                                     \
            ACTION_##action,                                                \
            action_qual,                                                    \
            #trans                                                          \
        },
  
#undef  STATE_END
#define STATE_END                                                           \
        {                                                                   \
            EVENT_NO_EVENT,                                                 \
            STATE_NO_STATE,                                                 \
            GUARD_NO_GUARD,                                                 \
            NO_QUAL,                                                        \
            ACTION_NO_ACTION,                                               \
            NO_QUAL,                                                        \
            "Dummy Transition"                                              \
        }                                                                   \
    };

#include STATECHART_FILE
    
#endif /* STATECHART_BUILD_TABLES */


#endif /*STATECHART_TABLE_STATE_HIERARCHY_H_*/
