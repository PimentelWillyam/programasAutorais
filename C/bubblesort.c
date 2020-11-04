#include <stdio.h>
#include <math.h>

void printArray(double arr[],int n)
{
    int i;
    for (i=0;i<n;i++){
            printf("%f ",arr[i]);
    }
}

void swap(double *a,double *b)
{
        double temp;
        temp = *a;
        *a = *b;
        *b = temp;
}

void bubbleSort(double arr[],int n)
{
        int i,j;
        for (i=0;i<n-1;i++){
                for (j=0;j<n-1;j++){
                        if (arr[j] < arr[j+1])
                                swap(&arr[j],&arr[j+1]);
                }
        }
}

int main (void)  
{       
        double arr[5] = {1,2,3,4,5};
        bubbleSort(arr,5);
        printArray(arr,5);
        return 0;
}