#ifndef MY_TIME_H
#define MY_TIME_H

typedef long my_time_t;

struct timespec
{
    my_time_t tv_sec;
    long tv_nsec;
};

int nanosleep(struct timespec *wait, struct timespec *rem);
unsigned int sleep(unsigned int seconds);

#endif