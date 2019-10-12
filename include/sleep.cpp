#include <time.h>
#include <math.h>
#include "sleep.h"

int sleep_remaining( clock_t startTime, unsigned long int waitTime ) {

  clock_t timeLeft = clock() - startTime;

  float timeDifference = ( ( (float) timeLeft ) / CLOCKS_PER_SEC );

  signed long int remainingTime = waitTime - ( (long int) round( timeDifference * 1000 ) );

  if ( remainingTime <= 0 ) {
	  
    return 0;

  } else {

    int rval = sleep_ms( remainingTime );

    return rval;

  }

  return 1; // should never be reached

}

int sleep_ms( unsigned long int milliseconds ) {

  struct timespec tv;
 
  tv.tv_nsec = ( milliseconds * 1e+6 );
  
  int rval = nanosleep( &tv, &tv );
  
  return rval;
  
}
