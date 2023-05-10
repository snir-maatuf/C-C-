
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* the complex number struct */
typedef struct complex {
    double real;
    double image;
} complex;

/*A function that places values in a complex variable*/
void read_comp(complex* a, double real, double image);

/*A function that prints a complex number*/
void print_comp(complex *a);

/*A function that receives two complex numbers as parameters, sums them and prints the result*/
void add_comp(complex* a, complex* b);

/*A function that receives two complex numbers as parameters, subtracts them and prints the result*/
void sub_comp(complex *a, complex *b);

/*A function that calculates the multiplication of a complex number and a real number received as parameters and prints the result*/
void mult_comp_real(complex *a, double num);

/*A function that calculates the multiplication of a complex number and an imaginary number received as parameters and prints the result*/
void mult_comp_img(complex *a, double img);

/*A function that calculates the multiplication of two complex numbers received as parameters and prints the result*/
void mult_comp_comp(complex *a, complex *b);

/*A function that calculates the absolute value of the complex number received as a parameter and prints it*/
void abs_comp(complex *a);

/* A function that ends the program with message on it */
void stop();

