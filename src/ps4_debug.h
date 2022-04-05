#ifndef _PS4_DEBUG_H_
#define _PS4_DEBUG_H_

#ifdef PS4DEBUG

void init_ps4_debug(void);
void ps4_debug_printf(const char *__restrict, ...);

#define printf(fmt, ...) ps4_debug_printf(fmt, ##__VA_ARGS__)
#define fprintf(f, fmt, ...) ps4_debug_printf(fmt, ##__VA_ARGS__)

#endif

#endif
