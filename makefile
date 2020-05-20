all : build clean run

build : Source.c
	cl -nologo Source.c

run : Source.exe
	Source.exe

clean :
	del Source.obj