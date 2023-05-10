#include "header.h"



/* Get numbers from file and store into array, print the input and send the
   array to other function to delete duplicates numbers */
int *get_set(int *pSize) {

    int *nums = (int *) calloc(ENLARGE_SIZE, sizeof(int));
    int *q = NULL;
    int num = 0; /* Single number that get from file*/
    int i = 0;
    	
    
    FILE *fp;
    
    fp = fopen("input2.txt", "r");
    
    if( fp == NULL) {
        printf(" ERROR! could not open the file");
        return NULL;
    }

    while (fscanf(fp, "%d", &num) != EOF && i < MAX_SIZE) {
        if(i % ENLARGE_SIZE == 0){
            q = (int *) realloc(nums, (i + ENLARGE_SIZE) * sizeof(int));
            nums =q;
        }
        if (nums == NULL) {
            printf("\nERROR! Memory allocation failed");
            exit(0);
        }
        nums[i] = num;
        i++;
    }

    print_set(nums,i);
    nums = remove_duplicates(q, i, pSize);
    fclose(fp);
    
    return nums;
}



/* Print the array from some pointer and size of the array */
void print_set(int *a, int size) {
    int i;
    for (i = 0; i < size; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}


/* Get array (and his size) and create a new array without the 
   duplicates numbers */
int *remove_duplicates(int *arr, int size, int *new_size){
    int i, j, newArrIndex = 0;
    int *newArr = (int*) malloc(size * sizeof(int));
    int newSize = 0; /*Count the different numbers*/

    if(newArr == NULL){
        printf("\nERROR! Memory allocation failed");
        exit(0);
    }

    for(i=0; i<size; i++){
        for(j=0; j<i; j++){
            if(arr[i]==arr[j]){ /*Check for each number a dublicate number */
                break;
            }
        }
        if(i == j){ /*The number does have duplicate, so we add it to new array */
            newArr[newArrIndex] = arr[i];
            newArrIndex++;
            newSize++;
        }
    }

    *new_size = newSize; /* update the new size of the new array*/
    return newArr;
}


int main()
{
    int *nums;
    int numSize = 0;

    printf("User input is: ");
    nums = get_set(&numSize);

    printf("Array without duplicates numbers: ");
    print_set( nums , numSize);

    free(nums);
    return 0;
}


