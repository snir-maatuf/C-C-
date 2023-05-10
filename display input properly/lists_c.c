/*
 ============================================================================
 Name        : lists_c.c
 Author      : Snir Maatuf
 Version     : 01/06/2022
 Description : A program that stores text input in linked list and prints its content.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "lists_h.h" /* Constants and Node */

void printText(Node* head);
int readText(Node* head,FILE* file);


int main(int argc, char * argv[]) {
    int status; /* Error status */
    FILE *file;
    const char *filename = argv[1];
    Node* node;

    if( argc <= 1 ){
        printf("Error! didn't receive 1 file");
        exit(1);
    }
    if( argv[0] == NULL ) { printf("Error! Missing file name");}

    /* initialize first node of list */
    node  = (Node*)calloc(1,sizeof(Node));
    node->next = NULL;
    /* open file */
    file = fopen(filename , "r" );
    if( file == NULL ){
        printf("Error! Can't open file\n");
        exit(0);
    }

    status = readText(node,file);
    printf("Text in file:");
    printText(node);
    printf("\n");
    if (status == ERROR)
        printf("\nOut of memory error\n");
    return 0;
}

int readText(Node* head,FILE* file){
    Node* curr = head;
    int c,i=0;

    while((c=fgetc(file)) != EOF){
        if(i==LENGTH){ /* add node if filled buffer */
            i=0;
            curr->next = (Node*)calloc(1,sizeof(Node));
            if (curr->next == NULL)  /* return error if no memory */
                return ERROR;
            curr = curr->next;
            curr->next = NULL;
        }

        if (c != '\n') { /* add if not \n */
            curr->buff[i] = (char) c;
            i++;
        }
    }
    /* add \0 to end of buffer, unless buffer is full */
    if (i != LENGTH)
        curr->buff[i] = EOF;
    fclose(file);
    return 0;
}

void printText(Node* head){
    Node* temp;
    int i=0,count = 0;

    while (head != NULL)
    {
        while(i < LENGTH && head->buff[i] != EOF) {
            if (count%LENGTH==0)
                printf("\n"); /* make new line after LENGTH characters */
            printf("%c", head->buff[i]);
            i++;
            count++;
        }

        temp = head;
        head = head->next;
        free(temp);
        i = 0;
    }
}
