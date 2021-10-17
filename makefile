all: clean database.o main.o
	gcc main.o database.o -o a.out -lsqlite3
database.o:
	gcc -c database.c -o database.o -std=c99 -Wall -pedantic
main.o:
	gcc -c main.c -o main.o -std=c99 -Wall -pedantic
clean:
	- rm *.o
	- rm a.out