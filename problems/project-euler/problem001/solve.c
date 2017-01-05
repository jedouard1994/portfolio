#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[]){
    if(argc != 1){
        //ensure correct program usage
        printf("usage: ./solve\n");
        exit(1);
    }
    
    int acc, i;

    acc = 0;
    for(i = 3; i < 1000; i++){
        if((i%3 == 0) || (i%5 == 0)){
            acc+=i;
        }        
    }
    
    printf("%d\n", acc);
}
