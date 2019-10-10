#include <time.h>

int sleep_ms( unsigned long int milliseconds ) {

  struct timespec tv;
 
  tv.tv_nsec = ( milliseconds * 1e+6 );
  
  int rval = nanosleep( &tv, &tv );
  
  return rval;
  
}
