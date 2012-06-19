#include <stdlib.h>
#include <stdio.h>

int nextIntChar,currentIntChar,freq[256],seq[256],next[256],i,searchSeq;
double relFreq,percFreq,allChar;
char nextChar,currentChar;

void printFreq();
void printSeq();
void printNext();

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
	printf("\n\n");
	printFreq();
	printSeq();
	printNext();
	return 1;
}

void printFreq(){
	printf("### Frequenze: ###\n");
	for ( i = 48; i < 123; i++ ) {
		if(freq[i]!=0){
			relFreq=freq[i]/allChar;
			percFreq=(freq[i]*100)/allChar;
			printf("%c\n",i);
			printf("Assoluta: %d\n",freq[i]);
			printf("Relativa: %.2f\n",relFreq);
			printf("Percentuale: %.2f %%\n\n",percFreq);
		}
	}

}

void printSeq(){
	printf("### Sequenze ###\n");
	for(i=48;i<123;i++){
		if(seq[i]!=0){
			
			printf("%c ha %d sequenza/e \n",i,seq[i]);
			
		}
	}
	printf("\n");
}

void printNext(){
	printf("### Prossimo ###\n");
	for(i=48;i<123;i++){
		if(next[i]!=0){
			
			printf("%c ha %d volta/e un prossimo\n",i,next[i]);
			
		}
	}
}