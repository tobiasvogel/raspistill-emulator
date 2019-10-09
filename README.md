# raspistill-emulator
Emulator simulating a Camera Module interfaced via the "raspistill" utility.

### What is it?
A small utility that is supposed to simulate a Camera module connected to a Raspberry Pi Computer by acting like the original "raspistill" utility.

### Who needs it? 
If you are actually asking yourself this very question, then you probably don't =)

The raspistill-emulator is targeted at developers and intended to be used as a drop-in-replacement in a Virtual Machine environment for example.

### What does it actually do?
It serves Images from a folder as if they were coming from a actual camera, while retaining the limitations of the configured camera it is emulating.

### Features that it one day (hopefully) will incorporate
 - Random selection of images from folder as configured [WIP]
 - Maintain delay as specified by the "--timeout" option [WIP]
 - Outputting in the image (compression) format as specified by the "--encoding" option [WIP]
 - Relaying any arbitrary input stream as if coming from the camera [PLANNED]
 - Honoring exposure/brightness/contrast/iso/shutter settings [PLANNED]
 - ...
 - ...
 - Additionally provide a "raspivid" equivalent [MAYBE ONE DAY]
