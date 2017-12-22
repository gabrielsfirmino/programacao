all: app

app: main.o listaencadeada.o
	gcc main.o listaencadeada.o -o app

main.o: main.c listaencadeada.h
	gcc -g -c main.c

listaencadeada.o: listaencadeada.c listaencadeada.h
	gcc -g -c listaencadeada.c

clean:
	rm -f *.o app