#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define LEN 50

int main(){
 
    int shift_element(int* arr, int i){
        int n = *(arr+i);
        for (int j=i; j>0; j--){
            *(arr+j)=*(arr+j-1);
        }
        *arr=n;
        return 0;
    }

    int insertion_sort(int* arr, int len){
        int count = 0;
        for(int i=1; i<len; i++){
            for(int j=i-1; j>=0; j--)
            {
                int *ptr=arr+j;
                if(*ptr>*(arr+i)){
                    count++;
                    ptr --;
                    if(j==0){
                        shift_element((ptr+1),count);
                        count = 0;
                        break;
                    }
                }
                else{
                    shift_element((ptr+1),count);
                    count = 0;
                    break;
                }
            }
        }
        return 0;
    }

    //main

    int size = 0;
    int capacity = 10;
    int *numbers = malloc(capacity * sizeof(int));
    if (numbers == NULL) {
        fprintf(stderr, "Error: out of memory\n");
        exit(1);
    }

    while (scanf("%d", &numbers[size]) == 1 && ++size < LEN) {
        if (size == capacity) {
            capacity *= 2;
            numbers = realloc(numbers, capacity * sizeof(int));

            if (numbers == NULL) {
                fprintf(stderr, "Error: out of memory\n");
                exit(1);
            }
        }
    }

    insertion_sort(numbers,size);
    for(int j=0; j<size-1;j++)
    {
        printf("%d,",*(numbers+j));
    }
    printf("%d\n",*(numbers+size-1));
    for (int i=0; i<LEN; i++)
        free((numbers+i));
    free(numbers);
    return 0;
}
