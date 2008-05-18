#ifndef STATECHART_ENUM_TRANSITION_H_
#define STATECHART_ENUM_TRANSITION_H_


/* Statechart build pass 1: build an enum of all transitions */
#ifdef STATECHART_BUILD_ENUMS

#include "statechart_undef.h"   /* Ignore unused statechart macros */

#undef  TRANS
#define TRANS(type, trans, event, state, guard, action) TRANS_##trans,

typedef enum
{
    #include STATECHART_FILE
    TRANS_DUMMY
} transition_id_t;

#define TRANS_FIRST     (0)
#define TRANS_LAST      (TRANS_DUMMY - 1)
#define TRANS_TOTAL     (TRANS_LAST - TRANS_FIRST + 1)

#endif /* STATECHART_BUILD_ENUMS */
    

#endif /*STATECHART_ENUM_TRANSITION_H_*/
