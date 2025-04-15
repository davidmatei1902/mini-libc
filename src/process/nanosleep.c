#include <internal/syscall.h>
#include <internal/time.h>
#include <errno.h>
#include <stdlib.h>

int nanosleep(struct timespec *wait, struct timespec *rem)
{
    int ret = syscall(__NR_nanosleep, wait, rem);
    if (ret < 0)
    {
        errno = -ret;
        return -1;
    }
    return ret;
}