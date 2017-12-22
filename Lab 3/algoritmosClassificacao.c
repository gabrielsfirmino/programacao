#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define TAM 50000

double insertion_Sort() {
    int i,a,b,aux,v[TAM];
    double tempo_t;
    time_t inicio, fim;
    for(i=0; i < TAM; i++){
        v[i] = (rand()%5000000);
    }
    inicio = clock();
    for (a = 1; a < TAM; a++){
        aux = v[a];
        b= a-1;
        while ((b>=0) && (aux<v[b])) {
            v[b+1] =v[b];
            b--;
        }
    v[b+1]=aux;
    }
    fim = clock();
    tempo_t = (double)(fim - inicio)/CLOCKS_PER_SEC;
    return tempo_t;
}

double selection_sort() {
    double tempo_t;
    time_t inicio, fim;
    int i,a,b,aux2,aux,v[TAM];
    for(i=0; i < TAM; i++){
        v[i] = (rand()%5000000);
    }
    inicio = clock();
    for(a = 0; a < (TAM-1); a++) {
        aux2=a;
        for(b=(a+1);b < TAM; b++) {
            if(v[b]<v[aux2]) {
                aux2=b;
            }
        }
        if (a!=aux2){
            aux=v[a];
            v[a]=v[aux2];
            v[aux2]=aux;
        }
    }
    fim = clock();
    tempo_t = (double)(fim - inicio)/CLOCKS_PER_SEC;
    return tempo_t;
}

double bubble_sort() {
    int i,a,b,aux,v[TAM];
    double tempo_t;
    time_t inicio, fim;
    for(i=0; i < TAM; i++){
        v[i] = (rand()%5000000);
    }
    inicio = clock();
    for(a=TAM-1; a>= 1; a--){
        for(b=0; b < a ; b++) {
            if(v[b]>v[b+1]) {
                 aux = v[b];
                 v[b] = v[b+1];
                 v[b+1] = aux;
            }
        }
    }
    fim = clock();
    tempo_t = (double)(fim - inicio)/CLOCKS_PER_SEC;
    return tempo_t;
}

int main(int narg,char *argv[]){
        int count;
        double bubble=0,insertion=0,selection=0;
        srand(time(NULL));
        for (count=0; count<50; count++) {
        	bubble = bubble+bubble_sort();
        	insertion = insertion+insertion_Sort();
        	selection = selection+selection_sort();
        }
        printf("Tempo do bubble sort: %f\n", bubble);
        printf("Tempo do insertion sort: %f\n", insertion);
        printf("Tempo do selection sort: %f\n", selection);
        if(bubble < insertion && bubble < selection)
            printf("O Bubble sort é o mais rapido.\n");
        if(insertion < bubble && insertion < selection)
            printf("O Insertion sort é o mais rapido.\n");
        if(selection < bubble && selection < insertion)
            printf("O Selection sort é o mais rapido.\n");
        return EXIT_SUCCESS;
}
