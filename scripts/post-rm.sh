#!/bin/bash


## Make sure we are running as root

if [ ! "xʼid -uʼ" == "x0" ]; then

  echo "This script needs to be run as root user!" 1>&2

  exit 1

fi


## Make sure we don't run twice

if [ ! -f "/usr/bin/raspistill.vendor" ]; then

  echo "A file called \"raspistill.vendor\" does not exist!" 1>&2
  echo "This script should not be run multiple times." 1>&2

  exit 1

fi



## Remove 'Alternatives' for "raspistill"

update-alternatives --remove raspistill /usr/bin/raspistill.vendor
update-alternatives --remove raspistill /usr/bin/raspistill.emulator



## Prevent the 'Alternative' from being overwritten by upgrades

dpkg-divert --rename --remove /usr/bin/raspistill




exit 0
