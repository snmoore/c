#ifndef STATE_H_
#define STATE_H_

#include "fsm_event_id.h"  /* For event_id_t */

/* Structure for each state */
typedef struct
{
    char       *Name;
    event_id_t  EventId[5];
} state_t;

/* Public table of all states */
extern state_t *StateTable[];

#endif /*STATE_H_*/
