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

int nextIntChar,currentIntChar,freq[256],seq[256],i;
double relFreq,percFreq,allChar;
char nextChar,currentChar;
void printFreq();


int main(){
	FILE* file;
	file=fopen("testo","r");
	while(!feof(file)){
		
		if(fread(&nextChar,sizeof(nextChar),1,file)){
			allChar++;
			
			nextIntChar=nextChar;
			freq[nextIntChar]++;
		}
		else{
			break;
			}
	}
	fclose(file);
	printFreq();
	return 1;
}

void printFreq(){
	printf("### Frequences ###\n");
	for ( i = 48; i < 123; i++ ) {
		if(freq[i]!=0){
			relFreq=freq[i]/allChar;
			percFreq=(freq[i]*100)/allChar;
			printf("%c\n",i);
			printf("Absolute freq: %d\n",freq[i]);
			printf("Relative freq: %.2f\n",relFreq);
			printf("Percentage freq: %.2f %%\n\n",percFreq);
		}
	}

}
