#include <stdlib.h>
#include <stdio.h>

int is_palindrome(int number);

int main(int argc, char *argv[]){
    if(argc != 1){
        //ensure correct program usage
        printf("usage: solve\n");
        exit(1);
    }

    int product, largest_palindrome, i, j;

    largest_palindrome = -1; 
    for(i = 100; i < 1000; i++){
        for(j = 100; j < 1000; j++){
            product = i * j;
            if (is_palindrome(product) && product > largest_palindrome){
                largest_palindrome = product;
            }
        }
    }
    printf("%d\n", largest_palindrome);
}

int is_palindrome(int number){    
    int length, _is_palindrome, i;

    length = snprintf(NULL, 0, "%d", number);
    char num_string[length+1];
    snprintf(num_string, length+1, "%d", number);

    _is_palindrome = 1;
    for(i = 0; i < length/2; i++){
        if (num_string[i] != num_string[length-1-i]){
            _is_palindrome = 0;
            break;
        }
    }
    return _is_palindrome;
}
