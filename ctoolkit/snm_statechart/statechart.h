#ifndef STATECHART_H_
#define STATECHART_H_


#include "statechart_types.h"

/* 
 * Build the statechart
 * 
 * The C file must define STATECHART_FILE *before* including this file
 * 
 * Pass 1: build a set of enums e.g. all events, states, transitions etc
 * Pass 2: build a set of function declarations e.g. actions and guards
 * Pass 3: build a set of tables e.g. transitions per state, all actions & states
 *
 * Note that the order of these three passes is important
 * 
 * Then finally collate everything into a statechart
 */
#define STATECHART_BUILD_ENUMS
//    #include "statechart_enum_action.h"
    #include "statechart_enum_event.h"
//    #include "statechart_enum_guard.h"
    #include "statechart_enum_state.h"
//    #include "statechart_enum_transition.h"
#undef STATECHART_BUILD_ENUMS

#define STATECHART_BUILD_DECLARATIONS
    #include "statechart_declare_action.h"
    #include "statechart_declare_guard.h"
#undef STATECHART_BUILD_DECLARATIONS

#define STATECHART_BUILD_TABLES
    #include "statechart_table_entry.h"         /* Per state */
    #include "statechart_table_exit.h"          /* Per state */
    #include "statechart_table_transition.h"    /* Per state */

//    #include "statechart_table_action.h"        /* All actions */
//    #include "statechart_table_guard.h"         /* All guards */
    #include "statechart_table_state.h"         /* All states */
#undef STATECHART_BUILD_TABLES

static statechart_t Statechart = {
                                    NULL,
                                    NULL,

                                    { STATE_TOTAL,  &States[0] }
                                 };

/*
 * Export the public interface to the statechart processing functions
 */
extern int Validate(statechart_t *Statechart); 
extern int Initialise(statechart_t *Statechart);

#endif /*STATECHART_H_*/
