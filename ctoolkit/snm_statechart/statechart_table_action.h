#ifndef STATECHART_TABLE_ACTION_H_
#define STATECHART_TABLE_ACTION_H_


/* Statechart build pass 3: build a table of all action functions */
#ifdef STATECHART_BUILD_TABLES
 
#include "statechart_undef.h"   /* Ignore unused statechart macros */

#undef  ACTION
#define ACTION(action)  action,

static action_t Actions[ACTION_TOTAL] =
{
    #include STATECHART_FILE
};
    
#endif /* STATECHART_BUILD_TABLES */


#endif /*STATECHART_TABLE_ACTION_H_*/
