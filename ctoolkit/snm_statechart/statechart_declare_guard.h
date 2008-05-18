#ifndef STATECHART_DECLARE_GUARD_H_
#define STATECHART_DECLARE_GUARD_H_


/* Statechart build pass 2: declare all guard functions */
#ifdef STATECHART_BUILD_DECLARATIONS

#include "statechart_undef.h"   /* Ignore unused statechart macros */

#undef  GUARD
#define GUARD(guard)    static void guard(unsigned int Qual);

#include STATECHART_FILE

#endif /* STATECHART_BUILD_DECLARATIONS */


#endif /*STATECHART_DECLARE_GUARD_H_*/
