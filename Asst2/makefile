all: main

mymalloc.o: mymalloc.c mymalloc.h
	gcc -c mymalloc.c

main: main.c mymalloc.o
	gcc -o main main.c mymalloc.o

mysat: mysaturate.c mymalloc.o
	gcc -o mysat mysaturate.c mymalloc.o

clean:
	rm -rf *.o main sat
