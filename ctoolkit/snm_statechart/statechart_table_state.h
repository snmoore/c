#ifndef STATECHART_TABLE_STATE_H_
#define STATECHART_TABLE_STATE_H_


/* Statechart build pass 3: build a table of all states */
#ifdef STATECHART_BUILD_TABLES
 
#include "statechart_undef.h"   /* Ignore unused statechart macros */

#undef  STATE
#define STATE(type, state, parent)                                      \
    {                                                                   \
        #state,                                                         \
        STATE_TYPE_##type,                                              \
        &States[STATE_##parent],                                        \
        NO_STATE,                                                       \
                                                                        \
        {                                                               \
            (sizeof(state ## EntryTable) / sizeof(action_t))    - 1,    \
            state ## EntryTable                                         \
        },                                                              \
                                                                        \
        {                                                               \
            (sizeof(state ## ExitTable)  / sizeof(action_t))    - 1,    \
            state ## ExitTable                                          \
        },                                                              \
                                                                        \
        {                                                               \
            (sizeof(state ## TransTable) / sizeof(tran_t))      - 1,    \
            state ## TransTable                                         \
        },

#undef  STATE_END
#define STATE_END                                                       \
    },

static state_t States[STATE_TOTAL] =
{
    #include STATECHART_FILE
};

#endif /* STATECHART_BUILD_TABLES */


#endif /*STATECHART_TABLE_STATE_H_*/
