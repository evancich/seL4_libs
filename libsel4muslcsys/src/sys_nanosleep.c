
#include <autoconf.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <time.h>

#include <sel4/sel4.h>

long sys_nanosleep(va_list ap) {
    const struct timespec *req = va_arg(ap, const struct timespec *);
    struct timespec *rem = va_arg(ap, struct timespec *);
    
    if(!req) return -1; /* TODO need to set errno */
    
   seL4_Sleep(req->tv_sec * 1000 + req->tv_nsec / (1000 * 1000)); /* TODO this may not follow the posix standard */

    if(rem) {
        rem->tv_sec = 0;
        rem->tv_nsec = 0;
    }

    return 0;

}

