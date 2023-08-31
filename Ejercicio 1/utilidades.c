#include "utilidades.h"
#include <time.h>
#include <stdio.h>
#include <stdlib.h>

void swap(int* a, int* b){
    int t = *a;
    *a = *b;
    *b = t;
}

void printArray(int arr[],int size){
	int i;
  	for (i=0; i < size; i++)
       	printf("%d ", arr[i]);
    	printf("\n");
}

void printSubArray(int arr[],int low, int high){
    int i;
    printf("Sub array :  ");
	for (i=low; i <= high; i++)
       printf("%d ", arr[i]);
    printf("\n");
}

void llenarArreglo(int arr[], int n){
    int i;
    srand(time(NULL));
    for(i=0; i<n; i++){
        arr[i]=rand()%100;
    }
}

int partition (int arr[], int low, int high,int *comparisons,int *assignments){
   	int pivot = arr[high];    
	printf("Pivote: %d   \n ",pivot);
	int j,i = (low - 1);  
   	for (j = low; j <= high- 1; j++){
   		(*comparisons)++;
       	if (arr[j] <= pivot){
            		i++;    
            		swap(&arr[i], &arr[j]);
            		(*assignments)++;
        	}
    	}
    	swap(&arr[i + 1], &arr[high]);
    	(*assignments)+=3;
	return (i + 1);
}

int heapSize;

void Heapify(int* A, int i, int size,int *assignments)
{
	int l = 2 * i + 1;
	int r = 2 * i + 2;
	int largest;

	if(l <= heapSize && A[l] > A[i])
    	largest = l;
  	else
    	largest = i;
  	if(r <= heapSize && A[r] > A[largest])
    	largest = r;
  	if(largest != i){
    	swap(&A[i],&A[largest]);
    	(*assignments)+=3;
    	printArray(A,size);
    	Heapify(A, largest,size, &assignments);
     }
      
}

void BuildHeap(int* A, int size, int *assignments){
	heapSize = size - 1;
  	int i;
  	for(i = (size - 1) / 2; i >= 0; i--){
		Heapify(A, i,size, &assignments);
  	}
	printf("Termin%c de construir el HEAP \n",162);
}



void merge(int arr[], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
    int comparisons=0;
    int inserts=0;

    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2) {
    	
    	comparisons++;
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
        inserts++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
        inserts++;
    }
    printf("Comparaciones: %d\n", comparisons);
    printf("Inserciones: %d\n", inserts);
}

int getMax(int arr[], int n) {
    int max = arr[0];
    int i=0;
    for (i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

void countSort(int arr[], int n, int exp, int *comparisons, int *assignments) {
    int i, j;
    int count[10] = {0};
    int *output = (int *) malloc(n * sizeof(int));

    for (i = 0; i < n; i++) {
        count[(arr[i] / exp) % 10]++;
        (*assignments)++;
    }

    printf("Iteración 1:\n");
    for (i = 0; i < 10; i++) {
        printf("count[%d] = %d\n", i, count[i]);
    }
    printf("\n");

    for (i = 1; i < 10; i++) {
        count[i] += count[i - 1];
        (*assignments)++;
    }

    printf("Iteración 2:\n");
    for (i = 0; i < 10; i++) {
        printf("count[%d] = %d\n", i, count[i]);
    }
    printf("\n");

    for (i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
        (*comparisons)++;
        (*assignments)++;

        printf("Iteración 3:\n");
        for (j = 0; j < n; j++) {
            printf("%d ", output[j]);
        }
        printf("\n");
    }

    for (i = 0; i < n; i++) {
        arr[i] = output[i];
        (*assignments)++;
    }

    printf("\nIteración 4:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n\n");

    free(output);
}



