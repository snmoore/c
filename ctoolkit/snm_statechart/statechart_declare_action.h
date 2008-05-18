#ifndef STATECHART_DECLARE_ACTION_H_
#define STATECHART_DECLARE_ACTION_H_


/* Statechart build pass 2: declare all action functions */
#ifdef STATECHART_BUILD_DECLARATIONS

#include "statechart_undef.h"   /* Ignore unused statechart macros */

#undef  ACTION
#define ACTION(action)  static void action(unsigned int Qual);

#include STATECHART_FILE

#endif /* STATECHART_BUILD_DECLARATIONS */


#endif /*STATECHART_DECLARE_ACTION_H_*/
