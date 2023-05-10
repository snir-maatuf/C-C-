


#include "complex.h"



void read_comp(complex *a, double real, double image) {
    a->real = real;
    a->image = image;
}


/* Prints imaginary and real numbers as complex pattern*/
void print_comp(complex *a) {
    printf("%f", a->real);
    if (a->image >= 0)
        printf(" + (%f)i\n", a->image);
    else
        printf(" - (%f)i\n", -a->image);
    
}


void add_comp(complex *a, complex *b) {
    complex tmp;
    
    tmp.real = a->real + b->real;
    tmp.image = a->image + b->image;
    
    print_comp(&tmp);
    
}


void sub_comp(complex *a, complex *b) {
    complex tmp;
    
    tmp.real = a->real - b->real;
    tmp.image = a->image - b->image;
    
    print_comp(&tmp);
    
}


void mult_comp_real(complex *a, double num) {
    complex tmp;
    
    tmp.real = a->real * num;
    tmp.image = a->image * num;
    
    print_comp(&tmp);
}


void mult_comp_img(complex *a, double img) {
    complex tmp;
    
    tmp.real = -img * (a->image);
    tmp.image = img * a->real;
    
    print_comp(&tmp);
}


void mult_comp_comp(complex *a, complex *b) {
    complex tmp;
    
    tmp.real = (a->real * b->real) - (a->image * b->image);
    tmp.image = (a->real * b->image) + (a->image * b->real);
    
    print_comp(&tmp);
}


void abs_comp(complex *a) {
    printf("%f\n", sqrt(a->real * a->real + a->image * a->image));
}

void stop() {
    printf("\nThe program is END!");
    exit(0);
}



