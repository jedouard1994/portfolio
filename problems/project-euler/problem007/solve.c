#include <stdlib.h>
#include <stdio.h>

int TARGET_VALUE = 10001;

int is_prime(int number);

int main(int argc, char *argv[]){
    if(argc != 1){
        //ensure correct program usage
        printf("usage: ./solve\n");
        exit(1);
    }

    int counter, i, j;

    counter = 0;
    i = 1;
    while(counter < TARGET_VALUE){
        i++;
        if(is_prime(i))
            counter++;
    }

    printf("%d\n", i);
}

int is_prime(int number){
    int _is_prime, i;

    _is_prime = 1;
    for(i = 2; i < number; i++){
        if(number%i == 0){
            _is_prime = 0;
            break;
        }
    }
    return _is_prime;
}

