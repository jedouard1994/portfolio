#include <stdlib.h>
#include <stdio.h>

int NUM_LIMIT = 100;

int main(int argc, char *argv[]){
    if(argc != 1){
        //ensure correct program usage
        printf("usage: ./solve\n");
        exit(1);
    }

    long square_sum, diff;
    int sum, sum_squares, i;

    sum = 0;
    sum_squares = 0;
    for(i = 1; i <= NUM_LIMIT; i++){
        sum+=i;
        sum_squares+=(i*i);
    } 
    square_sum = sum*sum;
    diff = square_sum - sum_squares;
    
    printf("%ld\n", diff);
}

