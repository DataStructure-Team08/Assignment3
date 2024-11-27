#
# makefile
#
CC = gcc -g
LIBS = -L "C:\msys64\ucrt64\lib\gcc\x86_64-w64-mingw32\13.2.0"

all: graph

graph: main.o search.o minspantree.o
	$(CC) $(LIBS) -o graph main.o search.o minspantree.o

search.o: search.c search.h
	$(CC) -c search.c -o search.o

minspantree.o: minspantree.c minspantree.h
	$(CC) -c minspantree.c -o minspantree.o

clean:
	rm -f graph.exe
	rm -f *.o
