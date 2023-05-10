
#include "mycomp.h"



int main() {
    char line[LINE_LEN];
    initialize();
    multiLinesExecute(line);
    return 0;
}



void initialize() {
    read_comp(&A, 0, 0);
    read_comp(&B, 0, 0);
    read_comp(&C, 0, 0);
    read_comp(&D, 0, 0);
    read_comp(&E, 0, 0);
    read_comp(&F, 0, 0);
}

void multiLinesExecute(char line[]){
    while(1){
        get_line(line);
        processingLine(line);
    }
}

void get_line(char line[]) {
    printf("\nEnter Assembly command:\n");
    
    /* If there's no line (not even line break character) the
       program reached the end of the file before receiving stop command */
    if (fgets(line, LINE_LEN, stdin) == NULL) {
        printf("\nDidn't received command line!\n");
        exit(0);
    }
    
    printf("The line you entered is:\n");
    printf("%s", line);
}


void processingLine(char line[]){
    int i;
    char *p;
    char *secondNum;
    
    p = line;
    
    p = skipSpacesAndTabs(p);  /* remove spaces and tabs from the line*/
    
    
    if (p[0] == '\n') { /* check if the line is empty line */
        printf("blank line\n");
        return;
    }

    i = identifyWhichCommand(p); /* holds the command type*/
    if( i == -1){
        printf("Undefined command name\n");
        return;
    }
    
    /*skiping with pointer on the command name */
    p += strlen(commandNames[i]);
    
    /* cleaning from spaces and tabs*/
    removeSpacesAndTabs(p);
    
    if (p[0] == ',') {
        printf("Illegal comma\n");
        return;
    }
    
    /* the command is " stop" */
    if ( strcmp( p,"stop")== 0 ) {
        stop();
    }
    
    
    
    
    /* checking if the first number is complex then continue */
    if( p[0] < 'A' && p[0] > 'F' ){  /* if number is not complex */
        printf("Undefined complex variable\n");
        return;
    }

    /* If the command is print_comp then execute him.
        Need only complex name */
    if( i == PRINT_COMP){
        print_comp(whichComplex(p[0]));
        return;
    }
    
    /* If the command is abs_comp then execute him.
        Need only complex name */
    if( i == ABS_COMP){
        abs_comp(whichComplex(p[0]));
        return;
    }



    /* now we check for all others commands that need 2 complex names */
    
    
    /* if there has no COMMA then stop, else continue*/
    if (p[1] != ',') {
        printf("Missing comma\n");
        return;
    }
    
    if (i == ADD_COMP || i == SUB_COMP || i == MULT_COMP_COMP) {
        
        /* if number is not complex */
        if( p[2] < 'A' && p[2] > 'F' ){
            
            isMissParameter(p[2]);
            printf("Undefined complex variable\n");
            return;
        }

        /* if there has something after second complex number */
        isExtraneousText(p[3]);
        
    
        /* until now we have correct Assembly command */
        
        if( i == ADD_COMP)
            {
                add_comp(whichComplex(p[0]), whichComplex(p[2]));
                return;
            }
            else if( i == SUB_COMP)
            {    
                sub_comp(whichComplex(p[0]), whichComplex(p[2]));
                return;
            }
            else if( i == MULT_COMP_COMP)
            {
                mult_comp_comp(whichComplex(p[0]), whichComplex(p[2]));
            }
        return;
    }
    
    /* now we left for checking for:READ_COMP or MULT_COMP_REAL
       or MULT_COMP_IMG commands */
       
    if(!isdigit(p[2])){
        
        isMissParameter(p[2]);
        
        if( p[2] == ','){
            printf("Multiple consecutive commas\n");
            return;
        }
        
        /* checking if number is negative*/
        if( p[2] != '-' || !isdigit(p[3])){
            
            printf("Invalid parameter - not a number\n");
            return;
        }
    }
    
    if( i == READ_COMP){
        
        secondNum = skipNum(p+2);
        
        /* if there has no COMMA then stop, else continue*/
        if (secondNum[0] != ',') {
            printf("Missing comma\n");
            return;
        }
        
        secondNum +=1;
        
        if( !isdigit(secondNum[0])){
            
            isMissParameter(secondNum[0]);
            
            if( p[2] == ','){
            printf("Multiple consecutive commas\n");
            return;
            }
            
            /* cheking for negative number */
            if( secondNum[0] !='-' || !isdigit(secondNum[1]) ){
                
                printf("Invalid parameter - not a number\n");
                return;
            }
        }
        
        /* until now we have 2 numbers in the command */
        
        /* check for extraneous text after the second number*/
        isExtraneousText(*skipNum(secondNum));
        
        /* execute the command */
        read_comp( whichComplex(p[0]) , atof(p+2) , atof(secondNum) );
        
        
        return;
    }
    
    
    /* left 2 commad to check */
    
    isExtraneousText(*skipNum(p+2));
    
    if( i == MULT_COMP_REAL){
        mult_comp_real(whichComplex(p[0]), atof(p + 2));
    }
    else
    {
        mult_comp_img(whichComplex(p[0]), atof(p + 2));
    }
    
} /* END processingLine FUNCTION */ 










void isExtraneousText(char p){
    if (p) {
        printf("Extraneous text after end of command\n");
        }
}



void isMissParameter(char p){
    if( !p){ 
            printf("Missing parameter\n");
            }
}




int identifyWhichCommand(char *p){
    int commandLength = 0;
    int i=0;

    /* count the length of command without spaces and comma  */
    for(i = 0; p[i] && p[i] != ' ' && p[i] != '\t' && p[i] != ',' && p[i] != '\n'; i++) {
        commandLength++; 
    }

    for ( i = 0; i < NUM_FUNC; i++) {  /* checking each command*/
        /* comparing only the command name  */
        if ( !strncmp( commandNames[i], p, commandLength) && strlen(commandNames[i]) == commandLength) {
            return i;  /* found a match */
        }
    }
    return -1; /* there is no such command */
}



void removeSpacesAndTabs(char *str) {
    int i, j =0; /* j - follow on chars in the string*/
    for (i = 0; str[i]; i++) {
        if (str[i] != ' ' && str[i] != '\t' && str[i] != '\n') {
            str[j++] = str[i];
        }
    }
    str[j] = '\0';
}



char *skipSpacesAndTabs(char *s) {
    while (*s == ' ' || *s == '\t') { /* recognize space or tab */
        s++; /* skip the space or tab */
    }
    return s;
}




complex *whichComplex(char x) {
    
    switch(x) {
        case 'A':
            return &A;
        case 'B':
            return &B;
        case 'C':
            return &C;
        case 'D':
            return &D;
        case 'E':
            return &E;
        case 'F':
            return &F;
        default:
            return NULL;
    }
}



char *skipNum(char *s) {
    int i = 0;
    int hadPoint = 0;
    
    for (; isdigit(s[i]) || s[i] == '.'; i++) {
        if (s[i] == '.') {
            if (hadPoint || !isdigit(s[i + 1])) /* the point at the end of the number */
                return s + i;
            hadPoint = 1; /* only one point is allowed in the number */
        }
    }
    
    return s + i; /* return a pointer to the char after the number */
}
