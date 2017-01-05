#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void strip_char(char **array, int *array_size, char victim);

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
        strip_char(&input, &input_filesize, '\n');
      
        //process input
        int i, j, char_num; 
        long current_product, max_product;

        max_product = 0;
        for(i = 0; i < input_filesize - SEQUENCE_SIZE; i++){
            current_product = 1;
            for(j = i; j < i + SEQUENCE_SIZE; j++){
                char_num = input[j] - '0';
                current_product*=char_num;
            }           
            if(current_product > max_product){
                max_product = current_product;
            }
        }

        printf("%ld\n", max_product);

        //cleanup  
        free(input);
        fclose(input_file);
        return 0;
    }

    //failed to open necessary input file
    perror("<fopen() failed unexpectedly>");
    return 1;
}

void strip_char(char **array, int *array_size, char victim){
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
}
