all:	main	

main:	main.o biblioteca.o
	gcc main.o biblioteca.o -o main

main.o:	main.c 
	gcc -g -c main.c

biblioteca.o:	biblioteca.c	biblioteca.h
	gcc -g -c biblioteca.c

clean:
	rm -f *.o *~ main