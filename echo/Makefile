CC = gcc
CFLAGS = -O2 -Wall -I .

# This flag includes the Pthreads library on a Linux box.
# Others systems will probably require something different.
LIB = -lpthread

all: echoclient echoserveri hostinfo 

echoclient: echoclient.c csapp.o
	$(CC) $(CFLAGS) -o echoclient echoclient.c csapp.o $(LIB)

echoserveri: echoserveri.c csapp.o
	$(CC) $(CFLAGS) -o echoserveri echoserveri.c csapp.o $(LIB)

hostinfo: hostinfo.c csapp.o
	$(CC) $(CFLAGS) -o hostinfo hostinfo.c csapp.o $(LIB)

csapp.o: csapp.c
	$(CC) $(CFLAGS) -c csapp.c

clean:
	rm -f *.o

