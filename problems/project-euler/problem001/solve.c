#include <iostream>
#include <stdlib.h> 

int main(int argc, char *argv[]){
    if(argc != 1){
        //ensure correct program usage
        std::cout << "usage: ./solve" << std::endl;
        exit(1);
    }
    
    int acc = 0;
    for(int i = 3; i < 1000; i++){
        if((i%3 == 0) || (i%5 == 0)){
            acc+=i;
        }        
    }
    
    std::cout << acc << std::endl;
}
