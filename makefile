all: main.o stat.o
	gcc -o program main.o stat.o

main.o: main.c stat.c
	gcc -c main.c

stat.o: stat.c
	gcc -c stat.c
