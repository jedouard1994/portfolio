#include <stdlib.h>
#include <stdio.h>

int NUM_LIMIT = 2000000;

int *primes;

int main(int argc, char *argv[]){
    if(argc != 1){
        //ensure correct program usage
        printf("usage: ./solve\n");
        exit(1);
    }
    
    int i, j;
    long sum; 

    primes = (int*)malloc(NUM_LIMIT * sizeof(int));

    primes[0] = 0;
    for(i = 1; i < NUM_LIMIT; i++){
        primes[i] = 1;
    }

    for(i = 1; i < NUM_LIMIT; i++){
        if(i){
            int _i = i+1;
            for(j = 2*_i - 1; j < NUM_LIMIT; j+=_i){
                primes[j] = 0;
            }
        }
    }
    
    sum = 0;
    for(i = 0; i < NUM_LIMIT; i++){
        if(primes[i])
            sum+=(i+1);
    }

    printf("%ld\n", sum);

    free(primes);
}
