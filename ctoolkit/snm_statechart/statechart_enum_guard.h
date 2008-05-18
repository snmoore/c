#ifndef STATECHART_ENUM_GUARD_H_
#define STATECHART_ENUM_GUARD_H_


/* Statechart build pass 1: build an enum of all guards */
#ifdef STATECHART_BUILD_ENUMS

#include "statechart_undef.h"   /* Ignore unused statechart macros */

#undef  GUARD
#define GUARD(guard)    GUARD_##guard,

typedef enum
{
    #include STATECHART_FILE
    GUARD_DUMMY
} guard_id_t;

#define GUARD_FIRST     (0)
#define GUARD_LAST      (GUARD_DUMMY - 1)
#define GUARD_TOTAL     (GUARD_LAST - GUARD_FIRST + 1)

#endif /* STATECHART_BUILD_ENUMS */


#endif /*STATECHART_ENUM_GUARD_H_*/
