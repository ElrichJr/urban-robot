all : build clean run

build : main5.c
	cl -nologo main5.c

run : main5.exe
	main5.exe

clean :
	del main5.obj