#include <stdio.h>
#include <time.h>
#include "sleep.h"
#include "INIReader.h"
#include "optionparser.h"
#include "structs.h"


void print_usage() {

	printf( "-q, -quality\t\tSet jpeg quality <0 to 100>\n");
	printf( "-r, -raw\t\tAdd raw bayer data to jpeg metadata\n");
	printf( "-l, -latest\t\tLink latest complete image to filename <filename>\n");
	printf( "-t, -timeout\t\tTime (in ms) before takes picture and shuts down (if not specified, set to 5s)\n");
	printf( "-th, -thumb\t\tSet thumbnail parameters (x:y:quality) or none\n");
	printf( "-d, -demo\t\tRun a demo mode (cycle through range of camera options, no capture)\n");
	printf( "-e, -encoding\t\tEncoding to use for output file (jpg, bmp, gif, png)\n");
	printf( "-x, -exif\t\tEXIF tag to apply to captures (format as 'key=value') or none\n");
	printf( "-tl, -timelapse\t\tTimelapse mode. Takes a picture every <t>ms. \%d == frame number (Try: -o img_\%04d.jpg)\n");
	printf( "-fp, -fullpreview\t\tRun the preview using the still capture resolution (may reduce preview fps)\n");
	printf( "-k, -keypress\t\tWait between captures for a ENTER, X then ENTER to exit\n");
	printf( "-s, -signal\t\tWait between captures for a SIGUSR1 or SIGUSR2 from another process\n");
	printf( "-g, -gl\t\tDraw preview to texture instead of using video render component\n");
	printf( "-gc, -glcapture\t\tCapture the GL frame-buffer instead of the camera image\n");
	printf( "-bm, -burst\t\tEnable 'burst capture mode'\n");
	printf( "-dt, -datetime\t\tReplace output pattern (\%d) with DateTime (MonthDayHourMinSec)\n");
	printf( "-ts, -timestamp\t\tReplace output pattern (\%d) with unix timestamp (seconds since 1970)\n");
	printf( "-fs, -framestart\t\tStarting frame number in output pattern(\%d)\n");
	printf( "-rs, -restart\t\tJPEG Restart interval (default of 0 for none)\n");

	return;

}

int main(int argc, char *argv[]) {

  clock_t t = clock();

  unsigned long int timeout = 0;

  //print_usage();

  config_t configuration;


  if (timeout > 0) {
	  sleep_remaining(t, timeout);
  }

  return 0;

}
