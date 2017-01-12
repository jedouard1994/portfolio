#include <stdlib.h>
#include <stdio.h>
#include <string.h>

//void replace_char(char **array, int *array_size, char old, char new);

int SEQUENCE_SIZE = 13;

char *input_filename;
FILE *input_file;
char *input;

int main(int argc, char *argv[]){
    if(argc != 2){
        //ensure correct program usage
        printf("usage: ./solve <input_file>\n");
        exit(1);
    }

    input_filename = argv[1];
    if(input_file = fopen(input_filename, "r")){ 
        int input_filesize;

        //determine size of input file
        if(fseeko(input_file, 0L, SEEK_END) == -1){
            perror("<fseek() failed unexpectedly");
            exit(1);
        }

        input_filesize = ftello(input_file);
        if(input_filesize == -1){
            perror("<ftello() failed unexpectedly>");
            exit(1);
        }

        if(fseeko(input_file, 0L, SEEK_SET) == -1){
            perror("<fseek() failed unexpectedly>");
            exit(1);
        };
   
        //allocate space for input
        input = (char*)malloc(input_filesize*sizeof(char)+1);
        if(input == NULL){
            perror("<malloc() failed unexpectedly>");
            exit(1);
        }
 
        //read-in input
        int nread;
 
        nread = fread(input, sizeof(char), input_filesize, input_file);
        if(nread != input_filesize){
            perror("<fread() failed unexpectedly>");
            exit(1);
        }       
        input[input_filesize]='\0';     

        //process input
        char *token;
        char *trunksave;

        int num_cities; 
        int num_paths;
 
        char *token_2;
        char *branchsave;

        int source;
        int destination;
        int cost;

        token = strtok_r(input, "\n", &trunksave);

        token2 = strtok_r(input, " ", &branchsave);

        while(token2 = strtok_r(input, " ", &branchsave)){
            
        }  



        num_cities = strtol(token, NULL, 10);       

        int index;
        int graph[num_cities][num_cities];
        num_paths = num_cities*num_cities;
        for(index = 0; index < num_paths; index++){
            token = strtok_r(NULL, "\n", &trunksave);

            token_2 = strtok_r(token, " ", &branchsave);


        free(input);
        fclose(input_file);
        return 0;
    }
    perror("<fopen failed unexpectedly>");
    return 1;
}

/*void replace_char(char **array, int *array_size, char old, char new){
    int i, j;
    int _array_size;
    char *temp_array;

    i = 0;
    while(i < (*array_size)){
        if( (*array)[i] == victim ){
            _array_size = (*array_size);
            for(j = i; j < _array_size-1; j++){
                (*array)[j] = (*array)[j+1];
            }
            (*array_size)--;           
        }
        else{
            i++;
        }
    }
    
    temp_array = (char*)malloc((*array_size)*sizeof(char)+1);
    for(i = 0; i < (*array_size); i++){
        temp_array[i] = (*array)[i];
    }

    free((*array));
    (*array) = temp_array;
}*/
