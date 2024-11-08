#
# makefile
#
CC = gcc -g
LIBS = -L "C:\msys64\ucrt64\lib\gcc\x86_64-w64-mingw32\13.2.0"

all: poly

poly: main.o common.o cal.o
	$(CC) $(LIBS) -o poly main.o common.o cal.o

common.o: common.c common.h
	$(CC) -c common.c -o common.o

cal.o: cal.c cal.h
	$(CC) -c cal.c -o cal.o

clean:
	rm -f poly.exe
	rm -f *.o
