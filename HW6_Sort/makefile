#
# makefile
#
CC = gcc -g
LIBS = -L "C:\msys64\ucrt64\lib\gcc\x86_64-w64-mingw32\13.2.0"

all: sort

sort: main.o common.o sorting.o
	$(CC) $(LIBS) -o sort main.o common.o sorting.o

common.o: common.c common.h
	$(CC) -c common.c -o common.o

sorting.o: sorting.c sorting.h
	$(CC) -c sorting.c -o sorting.o

clean:
	rm -f sort.exe
	rm -f *.o
