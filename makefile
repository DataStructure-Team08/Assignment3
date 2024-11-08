#
# makefile
#
CC = gcc -g
LIBS = -L "C:\msys64\ucrt64\lib\gcc\x86_64-w64-mingw32\13.2.0"

all: sort

sort: main.o common.o sort.o
	$(CC) $(LIBS) -o sort main.o common.o sort.o

common.o: common.c common.h
	$(CC) -c common.c -o common.o

sort.o: sort.c sort.h
	$(CC) -c sort.c -o sort.o

clean:
	rm -f sort.exe
	rm -f *.o
