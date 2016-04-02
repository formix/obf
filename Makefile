
CC=gcc
CFLAGS=-W -Wall -std=c11
LDFLAGS=
EXEC=obf


all: $(EXEC)

obf: obf.o main.o
	$(CC) -o obf obf.o main.o $(LSFLAGS)

obf.o: obf.c obf.h
	$(CC) -o obf.o -c obf.c $(CFLAGS)

main.o: main.c obf.h
	$(CC) -o main.o -c main.c $(CFLAGS)

clean:
	rm -rf *.o

mrproper: clean
	rm -rf $(EXEC)
