
#include <internal/time.h>
#include <stdlib.h>

unsigned int sleep(unsigned int seconds)
{
    struct timespec req = {seconds, 0};
    return nanosleep(&req, NULL);
}