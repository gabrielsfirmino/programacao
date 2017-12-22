#include <stdio.h>
#include <stdlib.h>

int dia,mes,ano,diaE,mesE,anoE,total,i,j ;

int main(int narg, char *argv[]) {
	printf("Entre com o dia do seu nascimento (Ex.: 1,2,3,...,31): \n") ;
	scanf("%d", &dia) ;
	printf("Entre com o mês do seu nascimento (Ex.: 1,2,3,...,12): \n") ;
	scanf("%d", &mes) ;
	printf("Entre com o ano do seu nascimento (Ex.: 1900,1955,2000,2015): \n") ;
	scanf("%d", &ano) ;
	
	printf("Entre com o dia em que estamos (Ex.: 1,2,3,...,31): \n") ;
	scanf("%d", &diaE) ;
	printf("Entre com o mês em que estamos (Ex.: 1,2,3,...,12): \n") ;
	scanf("%d", &mesE) ;
	printf("Entre com o ano em que estamos (Ex.: 1900,1955,2000,2015): \n") ;
	scanf("%d", &anoE) ;

	total=0 ;
	i=0 ;
	j=0 ;
	
	if (ano==anoE) {
		if (mes==mesE) {
			total=diaE-dia ;
			printf("A diferença, em dias, entre o seu nascimento e o dia de hoje é:%d \n", total) ;
			return EXIT_SUCCESS;
		}
		else {
			for(j=(mes+1); j<=mesE; j++) {
				if ((j==1) || (j==3) || (j==5) || (j==7) || (j==8) || (j==10) || (j==12)) {
					total=(total+31+(diaE-dia)) ;
				}
				if ((j==4) || (j==6) || (j==9) || (j==11)) {
					total=(total+30+(diaE-dia)) ;
				}
				if (j==2) {
					if (ano%400==0)
						total=(total+29+(diaE-dia)) ;
					if ((ano%4==0) && (ano%100!=0))
						total=(total+29+(diaE-dia)) ;
					else
						total=(total+28+(diaE-dia)) ;		
				}
			}
			printf("A diferença, em dias, entre o seu nascimento e o dia de hoje é:%d \n", total) ;
			return EXIT_SUCCESS;
		}
	}
	
	i=0 ;
	j=0 ;

	for (i=(ano+1); i<anoE; i++) {
		for (j=1; j<=12; j++) {
			if ((j==1) || (j==3) || (j==5) || (j==7) || (j==8) || (j==10) || (j==12)) {
				total=total+31 ;
			}
			if ((j==4) || (j==6) || (j==9) || (j==11)) {
				total=total+30 ;
			}
			if (j==2) {
				if (i%400==0)
					total=total+29 ;
				if ((i%4==0) && (i%100!=0))
					total=total+29 ;
				else
					total=total+28 ;		
			}
		}
	}

	i=0 ;
	j=0 ;

	for (j=(mes+1); j<=12; j++) {
		if ((j==1) || (j==3) || (j==5) || (j==7) || (j==8) || (j==10) || (j==12)) {
			total=total+31 ;
		}
		if ((j==4) || (j==6) || (j==9) || (j==11)) {
			total=total+30 ;
		}
		if (j==2) {
			if (ano%400==0)
				total=total+29 ;
			if ((ano%4==0) && (ano%100!=0))
				total=total+29 ;
			else
				total=total+28 ;		
		}
	}

	for (i=1; i<mesE; i++) {
		if ((i==1) || (i==3) || (i==5) || (i==7) || (i==8) || (i==10) || (i==12)) {
			total=total+31 ;
		}
		if ((i==4) || (i==6) || (i==9) || (i==11)) {
			total=total+30 ;
		}
		if (i==2) {
			if (anoE%400==0)
				total=total+29 ;
			if ((anoE%4==0) && (anoE%100!=0))
				total=total+29 ;
			else
				total=total+28 ;		
		}
	}

	if ((mes==1) || (mes==3) || (mes==5) || (mes==7) || (mes==8) || (mes==10) || (mes==12)) {
		total=total+(31-dia) ;
	}
	if ((mes==4) || (mes==6) || (mes==9) || (mes==11)) {
		total=total+(30-dia) ;
	}
	if (mes==2) {
		if (ano%400==0)
			total=total+(29-dia) ;
		if ((ano%4==0) && (ano%100!=0))
			total=total+(29-dia) ;
		else
			total=total+(28-dia) ;		
	}

	if ((mesE==1) || (mesE==3) || (mesE==5) || (mesE==7) || (mesE==8) || (mesE==10) || (mesE==12)) {
		total=total+diaE ;
	}
	if ((mesE==4) || (mesE==6) || (mesE==9) || (mesE==11)) {
		total=total+diaE ;
	}
	if (mesE==2) {
		if (anoE%400==0)
			total=total+diaE ;
		if ((anoE%4==0) && (anoE%100!=0))
			total=total+diaE ;
		else
			total=total+diaE ;		
	}

	printf("A diferença, em dias, entre o seu nascimento e o dia de hoje é:%d \n", total) ;
	return EXIT_SUCCESS ;
}
