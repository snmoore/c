#ifndef EVENT_H_
#define EVENT_H_

#include <stddef.h> /* For size_t */

/* Structure for each event */
typedef struct
{
    char *Name;
} event_t;

/* Public table of all events */
extern event_t *EventTable[];

#endif /*EVENT_H_*/
