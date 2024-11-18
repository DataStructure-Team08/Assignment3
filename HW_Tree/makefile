#
# makefile
#
CC = gcc -g
LIBS = -L "C:\msys64\ucrt64\lib\gcc\x86_64-w64-mingw32\13.2.0"

all: tree

tree: main.o searching.o huff.o
	$(CC) $(LIBS) -o tree main.o searching.o huff.o

searching.o: searching.c searching.h
	$(CC) -c searching.c -o searching.o

huff.o: huff.c huff.h
	$(CC) -c huff.c -o huff.o

clean:
	rm -f tree.exe
	rm -f *.o
