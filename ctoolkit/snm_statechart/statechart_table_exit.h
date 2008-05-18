#ifndef STATECHART_TABLE_EXIT_H_
#define STATECHART_TABLE_EXIT_H_


/* Statechart build pass 3: build a set of exit action tables per state */
#ifdef STATECHART_BUILD_TABLES

/* 
 * For each state, build a table of exit actions
 *
 * E.g. for State0 this should result in a table of the form:
 *      static const int State0ExitTable[] = { };
 * 
 * Later we can hook this back into State0:
 *      State.EntryTable = &State0ExitTable[0];
 * 
 * We put a dummy element on the end in case of a state with no exit actions
 */
#include "statechart_undef.h"   /* Ignore unused statechart macros */

#undef  STATE
#define STATE(type, state, parent)          \
    static action_t state ## ExitTable[] =  \
    {

#undef  EXIT
#define EXIT(action)    action,             \
  
#undef  STATE_END
#define STATE_END       NO_ACTION           \
    };

#include STATECHART_FILE
    
#endif /* STATECHART_BUILD_TABLES */


#endif /*STATECHART_TABLE_EXIT_H_*/
