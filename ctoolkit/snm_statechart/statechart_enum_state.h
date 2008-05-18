#ifndef STATECHART_ENUM_STATE_H_
#define STATECHART_ENUM_STATE_H_


/* Statechart build pass 1: build an enum of all states */
#ifdef STATECHART_BUILD_ENUMS

#include "statechart_undef.h"   /* Ignore unused statechart macros */

#undef  STATE
#define STATE(type, state, parent)  STATE_##state,

typedef enum
{
    #include STATECHART_FILE
    STATE_DUMMY
} state_id_t;

#define STATE_FIRST     (0)
#define STATE_LAST      (STATE_DUMMY - 1)
#define STATE_TOTAL     (STATE_LAST - STATE_FIRST + 1)

#endif /* STATECHART_BUILD_ENUMS */


#endif /*STATECHART_ENUM_STATE_H_*/
