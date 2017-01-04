#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[]){
    if(argc != 1){
        //ensure correct program usage
        printf("usage: solve\n");
        exit(1);
    }
    
    int acc, prev, curr, temp;

    prev = 1;
    curr = 2;
    acc = prev + curr;
    while(curr < 4000000){
        temp = curr;
        curr+=prev;
        prev = temp;
        
        if(curr%2 == 0)
            acc+=curr;
    } 
 
    printf("%d\n", acc);
}
