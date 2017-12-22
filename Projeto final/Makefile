all: app

app: main.o biblioteca.o
	gcc main.o biblioteca.o -o app

main.o: main.c biblioteca.h
	gcc -g -c main.c

biblioteca.o: biblioteca.c biblioteca.h
	gcc -g -c biblioteca.c

clean:
	rm -f *.o app
