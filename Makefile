CC=g++

all: perm

perm: perm.cpp
	$(CC) -Wall -o perm perm.cpp -Ofast -fexpensive-optimizations

clean:
	rm -rf perm
