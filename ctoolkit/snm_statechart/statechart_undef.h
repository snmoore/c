/* No multiple include protection - this file is parsed multiple times */

/* Undefine all macros so that they can be ignored without error */
#undef  EVENT
#define EVENT(event)

#undef  STATE
#define STATE(type, state, parent)

#undef  ACTION
#define ACTION(action)

#undef  GUARD
#define GUARD(guard)

#undef  ENTRY
#define ENTRY(action)

#undef  TRANS
#define TRANS(type, trans, event, state, guard, action)

#undef  EXIT
#define EXIT(action)

#undef  STATE_END
#define STATE_END
