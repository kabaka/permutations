CC=g++

all: perm

perm: perm.o
	$(CC) -Wall -o perm perm.o -Ofast -fexpensive-optimizations -L/usr/lib

perm.o: perm.cpp
	$(CC) -c perm.cpp -Wall -Ofast -fexpensive-optimizations

clean:
	rm -rf *.o perm
