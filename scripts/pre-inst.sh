#!/bin/bash


## Make sure we are running as root

if [ ! "xʼid -uʼ" == "x0" ]; then

  echo "This script needs to be run as root user!" 1>&2

  exit 1

fi


## Make sure we don't run twice

if [ -f "/usr/bin/raspistill.vendor" ]; then

  echo "A file called \"raspistill.vendor\" already exists!" 1>&2
  echo "This script should not be run multiple times." 1>&2

  exit 1

fi


## Move the original raspistill-executable out of the way and
## prevent the change from being reverted by future updates

dpkg-divert --add --rename --divert /usr/bin/raspistill.vendor /usr/bin/raspistill


## Make sure the raspistill-executable has been moved away 

if [ -f /usr/bin/raspistill ]; then

  echo "Unexpected \"raspistill\" still present!" 1>&2
  echo "Something went wrong. Aborting" 1>&2

  exit 1

fi


## Install 'Alternative' for "raspistill"

update-alternatives --install /usr/bin/raspistill raspistill /usr/bin/raspistill.vendor 500
update-alternatives --install /usr/bin/raspistill raspistill /usr/bin/raspistill.emulator 1000

update-alternatives --set raspistill /usr/bin/raspistill.emulator



exit 0
