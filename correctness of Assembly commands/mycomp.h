


#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include "complex.h"


#define NUM_FUNC 9
#define LINE_LEN 100


enum names{
    READ_COMP,PRINT_COMP, ADD_COMP, SUB_COMP, MULT_COMP_REAL, MULT_COMP_IMG, MULT_COMP_COMP, ABS_COMP, STOP };

/* Initialize complex numbers */
complex A,B,C,D,E,F;

/* Command structure */
char *commandNames[NUM_FUNC] = {"read_comp", "print_comp", "add_comp", "sub_comp", "mult_comp_real","mult_comp_img", "mult_comp_comp", "abs_comp","stop"};

/* Initialize the complex variables to a value of 0 + 0i */
void initialize();

void multiLinesExecute(char line[]);

/* Get input from the user */
void get_line(char line[]);

/* Integrated the program */
void processingLine(char line[]);

/* Cheking if the pointer is pointing on extraneous char */
void isExtraneousText(char p);


/* Cheking if the pointer is pointing on NULL */
void isMissParameter(char p);


/* Identify Which Command we get from input and compare it to our commad stuct */
int identifyWhichCommand(char *p);

/* Removes all spaces and tabs in the string */
void removeSpacesAndTabs(char *str);

/* Skiping on the Tabs and spaces and return pointer */
char *skipSpacesAndTabs(char *s);

/* Return pointer to complex number as parameter reffered */
complex *whichComplex(char x);

/* Skiping on the number and return the last pointer after the number ends */
char *skipNum(char *s);
