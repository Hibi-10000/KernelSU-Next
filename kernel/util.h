#ifndef __KSU_UTIL_H
#define __KSU_UTIL_H

#include "include/util.h"

#include <linux/types.h>
#include <linux/version.h>
#include <linux/syscalls.h>
#include <linux/fdtable.h>

#ifndef preempt_enable_no_resched_notrace
#define preempt_enable_no_resched_notrace()                                    \
    do {                                                                       \
        barrier();                                                             \
        __preempt_count_dec();                                                 \
    } while (0)
#endif

#ifndef preempt_disable_notrace
#define preempt_disable_notrace()                                              \
    do {                                                                       \
        __preempt_count_inc();                                                 \
        barrier();                                                             \
    } while (0)
#endif

bool try_set_access_flag(unsigned long addr);

#endif
