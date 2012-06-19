	//Gli usuali programmi di compressione utilizzano diverse tecniche per valutare se e come un file è comprimibile.
	//Alcune di queste tecniche si basano sulla frequenza dei caratteri e sono le seguenti:
	//
	//a) Per un carattere calcolo la sua frequenza.
	//b) Per ogni carattere calcolo quante volte il prossimo carattere è di ordine successivo a quello letto [se leggo a incontro dopo b - h incontro i ]
	//c) Per ogni carattere calcolo quante sequenze almeno lunghe 2 ci sono [per la z ho una sequenza lunga 2 in "mezzo" - aaaab -> 1 sequenza di a (non importa quante volte ripetute basta che sia una sequenza)
	//
	//Scrivere un programma:
	//
	//Dato un file di ingresso contenente esclusivamente i caratteri A…Z e a….z da 0…9 
	//in questo ordine ABCD…Zabcd…z012….9
	//
	//calcolare a,b,c
	//
	//fornire le frequente assolute e relative e percentuali.

#include <stdlib.h>
#include <stdio.h>

int nextIntChar,currentIntChar,freq[122],seq[122],i,allChar;
double relFreq,percFreq;
char nextChar,currentChar;
void printFreq();


int main(){
	FILE* file;
	file=fopen("testo","r");
	while(!feof(file)){
		fread(&nextChar,sizeof(nextChar),1,file);
		nextIntChar=nextChar;
		freq[nextIntChar]++;
		allChar++;
		printf("%d %c\n",nextIntChar,nextChar);
	}

	fclose(file);
	printf("%d\n",allChar);
	printFreq();
	return 1;
}

void printFreq(){
	printf("### Frequences ###\n");
	for ( i = 48; i < 58; i++ ) {
		if(freq[i]!=0){
			printf("%c = %d\n",i,freq[i]);
		}
	}

	for ( i = 65; i < 91; i++ ) {
		if(freq[i]!=0){
			printf("%c = %d\n",i,freq[i]);
		}
	}

	for ( i = 97; i < 123; i++ ) {
		if(freq[i]!=0){
			printf("%c = %d\n",i,freq[i]);
		}
	}
}
