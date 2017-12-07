#include <stdio.h>

#ifdef DE
	#define SPRUCH "DE ohne liebe ist alles nichts"
#elif defined NL
	#define SPRUCH "NL ohne liebe ist alles nichts"
#elif defined SE
	#define SPRUCH "SE ohne liebe ist alles nichts"
#elif defined IT
	#define SPRUCH "IT ohne liebe ist alles nichts"
#elif defined CN
	#define SPRUCH "CN ohne liebe ist alles nichts"
#else
	#define SPRUCH "FI ohne liebe ist alles nichts"
#endif

#if !defined SIZE
	#define SIZE 3
#endif

void ausgabe(char spruch[], int len, int abstand){
	len = len + 2; // Stern links und rechts
	len = len + abstand;
	int count;
	int count2;
	
	count = 0;
	// AUSGABE STERNE OBEN
	while(count <= len){
		putchar('*');
		count++;
	}
	
	count = 0;
	while(count < abstand){
		count2 = 0;
		putchar('\n');
		while(count2 <= len){
			if(count2 == 0 || count2 == len){
				putchar('*');
			}else{
				putchar(' ');
			}
			count2++;
		}
		count++;
	}
	
	putchar('\n');
	
	
	count = 0;
	// AUSGABE SPRUCH MITTE
	while(count <= len){
		if(count == 0 || count == len){
			putchar('*');
		}else if((len - count) >= (len-(abstand)) || count >= (len-abstand)){
			putchar(' ');
		}else{
			putchar(spruch[count-1 -(abstand)]);
		}
		count++;
	}
	
	count = 0;
	while(count < abstand){
		count2 = 0;
		putchar('\n');
		while(count2 <= len){
			if(count2 == 0 || count2 == len){
				putchar('*');
			}else{
				putchar(' ');
			}
			count2++;
		}
		count++;
	}
	
	putchar('\n');

	count = 0;
	// AUSGABE STERNE UNTEN
	while(count <= len){
		putchar('*');
		count++;
	}
}

int main(void){
	char spruch[] = SPRUCH;
	int abstand = SIZE;
	
	int len = 0;
	while(spruch[len] != 0){
		len++;
	}
	
	ausgabe(spruch, len, abstand);
	putchar('\n');
	return 0;
}
