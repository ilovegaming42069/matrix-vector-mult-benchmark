#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "mylib/mylib.h"

#define LOWER 1
#define UPPER 5

int generateRandomInt(int lower, int upper){
    return (rand() % (upper-lower+1)) + lower;
}

void initMat(int* M, int N){
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            M[N*i+j] = generateRandomInt(LOWER,UPPER);
        }
    }
}

void initVec(int* v, int N){
    for(int i=0; i<N; i++){
        v[i] = generateRandomInt(LOWER,UPPER);
    }
}

int main (void) {

    srand(time(0));

    int N = 30000;
    int* M = (int *) malloc(N*N*sizeof(int));
    int* v = (int *) malloc(N*sizeof(int));
    int* b = (int *) malloc(N*sizeof(int));

    initMat(M, N);
    initVec(v, N);

    float startTime = (float)clock()/CLOCKS_PER_SEC;

        matVecMult(M,v,b,N);
    
    float endTime  = (float)clock()/CLOCKS_PER_SEC;

    printf("Time elapsed: %f s\n",endTime - startTime);

    return 0;
}