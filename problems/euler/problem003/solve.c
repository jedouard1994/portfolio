#include <stdlib.h>
#include <stdio.h>

long INPUT = 600851475143;

int main(int argc, char *argv[]){
    if(argc != 1){
        //ensure correct program usage
        printf("usage: solve\n");
        exit(1);
    }

    long i, j, factor;    
    for(i = INPUT/2; i > 0; i--){
        if(INPUT%i == 0){
            factor = i;
            break;
        }
    }
    printf("%ld\n", factor);
}

