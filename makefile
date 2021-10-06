all: main.o str_funcs.o
	gcc -o main main.o str_funcs.o

main.o: main.c str_funcs.h
	gcc -c main.c

str_funcs.o: str_funcs.c
	gcc -c str_funcs.c

