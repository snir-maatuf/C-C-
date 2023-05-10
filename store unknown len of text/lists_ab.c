#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char dynamicStoreString(char* string);

int main()
{
    char* input = " ";
    return dynamicStoreString(input);
    
}

char dynamicStoreString(char* string){
    int j, i=0 , totalChars = 0, alphnumeric = 0;
    char c;
    printf("Typing instructions: enter a string of chars and i will\nfind place in computer to store it.\n");
    string = (char*)malloc(sizeof(char));
    for(j = 0; (c = getchar()) != EOF; j++ ){
        string[j] = (char)c;/*insert char to array*/
        ++totalChars;
        alphnumeric += (isalnum(string[j]))? 1: 0;
        string[j+1] = '\0';
	/* rellocating the memory*/
        if(j == strlen(string)){
            char* new_string = (char*)realloc(string,strlen(string)*sizeof(char) *2);
            if (new_string == NULL)
		        printf("/nThe realloc doesnt worked");
		        exit(0);
        }
    }
    /*prints the chars in good shape */
    printf("\n---------Your string----------\n");
    for(i=0; i < strlen(string); i++){
        if((i % 30 == 0 && i !=0)){
            putchar(string[i]);
            printf("\n");
        }
        else{
            putchar(string[i]);
        }
    }
    printf("\n\nAlphnumeric chars in string: %d",alphnumeric);
    printf("\nTotal chars in string: %d\n",totalChars);
    return 0;
}

