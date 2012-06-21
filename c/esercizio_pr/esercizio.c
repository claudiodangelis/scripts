// Gli usuali programmi di compressione utilizzano diverse tecniche per valutare se e come un file è comprimibile.
// Alcune di queste tecniche si basano sulla frequenza dei caratteri e sono le seguenti:
// 
// a) Per un carattere calcolo la sua frequenza.
// b) Per ogni carattere calcolo quante volte il prossimo carattere è di ordine successivo a quello letto [se leggo a incontro dopo b - h incontro i ]
// c) Per ogni carattere calcolo quante sequenze almeno lunghe 2 ci sono [per la z ho una sequenza lunga 2 in "mezzo" - aaaab -> 1 sequenza di a (non importa quante volte ripetute basta che sia una sequenza)
// 
// Scrivere un programma:
// 
// Dato un file di ingresso contenente esclusivamente i caratteri A…Z e a….z da 0…9 
// in questo ordine ABCD…Zabcd…z012….9
// 
// 
// fornire le frequente assolute e relative e percentuali.
#include <stdlib.h>
#include <stdio.h>

int nextIntChar,currentIntChar,freq[123],seq[123],next[123],i,searchSeq;
double relFreq,percFreq,allChar;
char nextChar,currentChar;


int main(){
	printf("Contenuto del file:\n");
	FILE* file;
	file=fopen("testo","r");
	while(!feof(file)){
		
		if(fread(&nextChar,sizeof(nextChar),1,file)){
			printf("%c",nextChar);
			nextIntChar=nextChar;
			currentIntChar=currentChar;
			
			freq[nextIntChar]++;
			
			//cerca prossimo
			if(nextIntChar==(currentIntChar + 1)){
				next[currentIntChar]++;
			}
			
			//cerca seq.
			if(searchSeq==0){
				if(nextChar==currentChar){
					searchSeq=1;
				}
			}
			else{
				if(nextChar!=currentChar){
					currentIntChar=currentChar;
					seq[currentIntChar]++;
					searchSeq=0;
				}
			}
			
			currentChar=nextChar;
			allChar++;
			
			}
		
		else{
			break;
			}
	}
	
	if(searchSeq==1){seq[currentIntChar]++;}
	
	fclose(file);
	printf("\n");
	//Stampa
	for ( i = 48; i < 123; i++ ) {
		if(freq[i]!=0){
			relFreq=freq[i]/allChar;
			percFreq=(freq[i]*100)/allChar;
			printf("%c\n",i);
			printf("Freq. Assoluta: %d\n",freq[i]);
			printf("Freq. Relativa: %.2f\n",relFreq);
			printf("Freq. Percentuale: %.2f %%\n",percFreq);
			printf("Sequenza/e %d\n",seq[i]);
			printf("Prossimo: %d\n\n",next[i]);
		}
	}
	return 1;
}