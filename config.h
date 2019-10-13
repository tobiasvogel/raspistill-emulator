#ifndef CONFIG_H
#define CONFIG_H

#ifdef SYSCONF_DIR
  #define _SYSCONFDIR_ SYSCONF_DIR
#else
  #define _SYSCONFDIR_ "/etc"
#endif

#ifdef DATA_DIR
  #define _DATADIR_ DATA_DIR
#else
  #define _DATADIR "/usr/share/raspistill-emulator"
#endif

#ifdef VARDATA_DIR
  #define _VARDATADIR_ VARDATA_DIR
#else
  #define _VARDATADIR_ "/var/lib/raspistill-emulator"
#endif

#endif // CONFIG_H
