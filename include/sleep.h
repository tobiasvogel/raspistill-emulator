#ifndef SLEEP_H
#define SLEEP_H

#include <time.h>

int sleep_remaining( clock_t startTime, unsigned long int waitTime );

int sleep_ms( unsigned long int milliseconds );

#endif // SLEEP_H
