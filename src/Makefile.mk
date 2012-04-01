CFLAGS= /D_WIN32_

all: Main.exe ParBegin.dll

Main.exe: Main.obj ParBegin.lib
	cl /Fe$(@) Main.obj ParBegin.lib

ParBegin.dll: ParBeginThread.obj
	LINK /DLL /OUT:$(@) /EXPORT:ParBeginThread ParBeginThread.obj

ParBeginThread.obj: ParBeginThread.c ParBeginThread.h