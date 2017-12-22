#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char aleatorio() {
	char c;
	int r;
	r = rand()%52;
	
	if (r <= 25)	
		r = r + 65;
	else
		r = r + 97 - 26;
	
	c = (char)r;
	return c;
}

int comparar(int x, int y){
	int r=0;
	if (x>y) 
		r=1;
	return r;	
}

int main (int narg, char *argv[]) {
	srand(time(NULL));
	char matriz[1000][40],auxC1,auxC2;
	int i,j,cont=0,auxI1,auxI2,ret,var;
	
	for (i=0; i<1000; i++) {
		for(j=0; j<39; j++) {
			matriz[i][j]=aleatorio();
		}
		matriz[i][40]='\0';
	}
	
	for (i=0; i<1000; i++) {
		for(j=i+1; j<1000; j++) {
			auxC1=matriz[i][cont];
			auxC2=matriz[j][cont];
			auxI1=(int)auxC1;
			auxI2=(int)auxC2;
			while (auxI1==auxI2) {
				cont=cont+1;
				auxC1=matriz[i][cont];
				auxC2=matriz[j][cont];
				auxI1=(int)auxC1;
				auxI2=(int)auxC2;
			}
			ret=comparar(auxI1,auxI2);
			if (ret==1) {
				var=matriz[i][cont];
				matriz[i][cont]=matriz[j][cont];
				matriz[j][cont]=var;
			}				
			cont=0;
		}
	} 
	
	for (i=0; i<1000; i++) {
		for(j=0; j<39; j++) {
			printf("%c", matriz[i][j]);
		}
		printf("\n");
	}
	
	return EXIT_SUCCESS ;
}
