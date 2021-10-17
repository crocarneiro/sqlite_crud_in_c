all: clean database.o alunos_dao.o main.o
	gcc main.o database.o alunos_dao.o -o a.out -lsqlite3
database.o:
	gcc -c database.c -o database.o -std=c99 -Wall -pedantic
alunos_dao.o:
	gcc -c alunos/alunos_dao.c -o alunos_dao.o -std=c99 -Wall -pedantic
main.o:
	gcc -c main.c -o main.o -std=c99 -Wall -pedantic
clean:
	- rm *.o
	- rm a.out
