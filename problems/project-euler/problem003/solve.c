#include <stdlib.h>
#include <stdio.h>

long INPUT = 600851475143;

int main(int argc, char *argv[]){
    if(argc != 1){
        //ensure correct program usage
        printf("usage: solve\n");
        exit(1);
    }

    long _input, largest_factor;
    int i;
    
    _input = INPUT;
    largest_factor = 1;

    i = 2;
    while(i <= _input){
        if(_input%i == 0){
            if(i > largest_factor){
                largest_factor = i;
            }
            _input/=i;
        }
        else{
            i++;
        }
    }
    printf("%ld\n", largest_factor);
}

