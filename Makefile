CC = gcc
CXX = g++

CFLAGS = 
CXXFLAGS = -Wall

pkgname = raspistill-emulator

sysconfdir = /etc
datadir = /usr/share/$(pkgname)
vardatadir = /var/lib/$(pkgname)

SUBDIRS = 3rd-party/inih/cpp 3rd-party/inih 3rd-party/optionparser include src

HEADERS = 3rd-party/inih/ini.h \
	  3rd-party/inih/cpp/INIReader.h \
	  3rd-party/optionparser/optionparser.h \
	  $(wildcard include/*.h) \
	  $(wildcard src/*.h)

OBJECTS = 3rd-party/inih/inih.o \
	  3rd-party/inih/cpp/INIReader.o \
	  $(patsubst %.cpp,%.o,$(wildcard include/*.cpp)) \
	  $(patsubst %.cpp,%.o,$(wildcard src/*.cpp))

LIBS =


CFLAGS += $(patsubst %,-I%,$(SUBDIRS))

CXXFLAGS +=  $(patsubst %,-I%,$(SUBDIRS))

CPPFLAGS += -DSYSCONF_DIR=$(sysconfdir) \
	    -DDATA_DIR=$(datadir) \
	    -DVARDATA_DIR=$(vardatadir)

raspistill-emulator:
	$(foreach SUBDIR, $(SUBDIRS), CXXFLAGS="$(subst -I,-I../,$(CXXFLAGS))" CPPFLAGS="$(CPPFLAGS)" $(MAKE) -C $(SUBDIR) all ; ) 
	$(CXX) $(CXXFLAGS) -o raspistill.emulator $(OBJECTS) $(LIBS)


all: raspistill-emulator

.PHONY: clean

clean:
	-rm -f $(OBJECTS)
	-rm -f raspistill.emulator
