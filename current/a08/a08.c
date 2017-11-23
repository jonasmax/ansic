#include <stdio.h>
#include <stdlib.h>

#define LEN 20

int findeMinimum(int * vector){
    int minIndex = 0;
    int index = 0;
    while(vector[index]){
        if(vector[index] < vector[minIndex]){
            minIndex = index;
        }
        index++;
    }
    return minIndex;
}


void tausche(int * vector, int minIndex){
    int a = vector[0];
    vector[0] = vector[minIndex];
    vector[minIndex] = a;
}


void vectorAusgeben(int * vector){
    int index = 0;
    while(vector[index]){
        printf("%d \n", vector[index]);
        index++;
    }
}


void sortierenDurchAuswahl(int * vector){
    int index = 0;
    while(vector[index]){
        int minIndex = findeMinimum(&vector[index]);
        tausche(&vector[index], minIndex);
        index++;
    }
}


int * intVektorLesen(){
    int * vector = malloc(LEN * sizeof(int));
    
    int index = 0;
    while(scanf("%d", &vector[index]) != EOF){
        index++;
    }
    
    return vector;
}



int main(void){
	int * s = malloc(LEN * sizeof(int));
    int * vector = intVektorLesen();
    
    sortierenDurchAuswahl(vector);
    vectorAusgeben(vector);
    free(vector);
    vector = NULL;
    
    return 0;
}
