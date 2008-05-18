#ifndef STATECHART_TABLE_GUARD_H_
#define STATECHART_TABLE_GUARD_H_


/* Statechart build pass 3: build a table of all guard functions */
#ifdef STATECHART_BUILD_TABLES
 
#include "statechart_undef.h"   /* Ignore unused statechart macros */

#undef  GUARD
#define GUARD(guard)    guard,

static guard_t Guards[GUARD_TOTAL] =
{
    #include STATECHART_FILE
};
    
#endif /* STATECHART_BUILD_TABLES */


#endif /*STATECHART_TABLE_GUARD_H_*/
