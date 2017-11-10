#include <stdio.h>

#define BINAER_LENGTH 9

int potenz_calculate(int basis, int potenz){
	int result = 1;
	int index;
	for(index = 0; index < potenz; index++){
		if(index != 0){
			result *= basis;
		}	
	}
	return result;
}

int binaerToInteger(char binaer[]){
	int integer;
	int potenz = 0;
	int counter = BINAER_LENGTH -1;
	while(counter != 0){
		if(binaer[counter] == '1'){
			integer += potenz_calculate(2, potenz);
		}
		potenz++;
		counter--;
	}
	return integer;
}

void bitoperation(int a, int b){
	printf("a = %d \n", a);
	printf("b = %d \n", b);
	printf("a & b = %d ", a & b);
}

int main(void){
	char a_vector[BINAER_LENGTH];
	char b_vector[BINAER_LENGTH];
	int a;
	int b;
	
	printf("A eingeben: ");
	scanf("%s", a_vector);
	a_vector[8] = '\0';
	printf("B eingeben: ");
	scanf("%s", b_vector);
	b_vector[8] = '\0';
	
	a = binaerToInteger(a_vector);
	b = binaerToInteger(b_vector);
	
	bitoperation(a, b);
	return 0;
}
