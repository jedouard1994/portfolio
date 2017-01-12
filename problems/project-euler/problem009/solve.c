#include <stdlib.h>
#include <stdio.h>

int NUM_LIMIT = 1000;

int main(int argc, char *argv[]){
    if(argc != 1){
        //ensure correct program usage
        printf("usage: ./solve\n");
        exit(1);
    }
    
    int i, j, k, product;
    
    for(i = 0; i < NUM_LIMIT; i++){
        for(j = i; j < NUM_LIMIT; j++){
            for(k = j; k < NUM_LIMIT; k++){
                if((i + j + k == 1000) && (i*i + j*j == k*k)){
                    product = i*j*k;
                    break;       
                }
            }
        }
    }

    printf("%d\n", product);
}
