#include <stdlib.h>
#include <stdio.h>

int NUM_LIMIT = 20;
int *factors_union;

int main(int argc, char *argv[]){
    if(argc != 1){
        //ensure correct program usage
        printf("usage: ./solve\n");
        exit(1);
    }

    long smallest_number;
    int i;

    smallest_number = 1;

    factors_union = malloc(NUM_LIMIT * sizeof(int));
    for(i = 0; i < NUM_LIMIT; i++){
        factors_union[i] = 0;
    }

    for(i = 2; i <= NUM_LIMIT; i++){
        int *factors, _i, j;

        factors = malloc(i * sizeof(int));
        for(j = 0; j < i; j++){
            factors[j] = 0;
        }
      
        _i = i;
        j = 2;
        while(j <= _i){
            if(_i%j == 0){
                factors[j-1]++;
                _i/=j;
            }
            else{
                j++;
            }
        } 
  
        for(j = 0; j < i; j++){
            if(factors[j] > factors_union[j]){
                factors_union[j] = factors[j];
            }
        }

        free(factors);
    }

    for(i = 2; i <= NUM_LIMIT; i++){
        int count;

        for(count = factors_union[i-1]; count > 0; count--){
            smallest_number*=i;
        }
    }

    printf("%ld\n", smallest_number);

    free(factors_union);   
}

