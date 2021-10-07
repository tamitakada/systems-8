all: main.o str_funcs.o test.o
	gcc -o main main.o str_funcs.o test.o

test: test_main.o str_funcs.o test.o
	gcc -o test test_main.o str_funcs.o test.o

main.o: main.c str_funcs.h
	gcc -c main.c

str_funcs.o: str_funcs.c
	gcc -c str_funcs.c

test.o: test.c str_funcs.h
	gcc -c test.c

test_main.o: test_main.c test.h
	gcc -c test_main.c


