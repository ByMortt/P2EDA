#include "ordenamientos.h"
#include <stdio.h>
#include <stdlib.h>


void selectionSort(int arreglo[], int n,int *comparisons,int *assignments){
	int indiceMenor, i, j;
	for (i=0; i<n-1; i++){
		indiceMenor=i;
		for(j = i+1; j<n; j++){
			(*comparisons)++;
			if(arreglo[j]<arreglo[indiceMenor])
				indiceMenor=j;
		}
		if (i!=indiceMenor){
			swap(&arreglo[i],&arreglo[indiceMenor]);
			(*assignments)++;
		}

		printf("\nIteracion numero %d \n",i+1);
		printArray(arreglo,n);
	}
}


void insertionSort(int a[], int n){
	int i,j,k;
	int aux;
	int operations=0;

	for(i=1; i<n; i++){
		j=i;
		aux=a[i];
		while (j>0 && aux < a[j-1]){
			a[j] = a[j-1];
			j--;
			operations+=2;
		}
		a[j]=aux;
		operations++;


		printf("\nIteracion numero %d \n",i);
		printArray(a,n);
	}
	printf("\nTotal de operaciones: %d",operations);
}

int bubbleSort(int a[], int size) {
  int i, j, temp, swapped;
  int comparisons=0;
  int swaps=0;

  for (i = 0; i < size - 1; i++) {
    swapped = 0;
    for (j = 0; j < size - i - 1; j++) {
    	comparisons++;
    	if (a[j] > a[j+1]) {
        	temp = a[j];
        	a[j] = a[j+1];
        	a[j+1] = temp;
        	swaps++;
        	swapped = 1;
      }
    }
    if (swapped == 0) {
    	break;
    }
	printf("\nIteracion numero %d \n",i);
	printArray(a,size);  
  }
  return comparisons+swaps;
}

void quickSort(int arr[], int low, int high,int *comparisons,int *assignments)
{
    if (low < high)
    {
        int pi = partition(arr, low, high,comparisons,assignments);
        printSubArray(arr,low,pi-1);
		quickSort(arr, low, pi - 1,comparisons,assignments);
		printSubArray(arr,pi+1,high);
		quickSort(arr, pi + 1, high,comparisons,assignments);
    }
}

int heapSize;

void HeapSort(int* A, int size,int *assignments){
	BuildHeap(A,size);
  	int i;
  	for(i = size - 1; i > 0; i--){
    	swap(&A[0],&A[heapSize]);      
      	heapSize--;
      	(*assignments)+=3;
      	printf("Iteracion HS: \n");
  		printArray(A,size);
		Heapify(A, 0,size);
   }
}



void mergeSort(int arr[], int l, int r) {
	int swaps=0;
    if (l < r) {
        int m = l + (r - l) / 2;

        // Ordenar la primera mitad y mostrarla
        mergeSort(arr, l, m);
        printf("Sub array 1: ");
        int i=0;
        for (i = l; i <= m; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");

        // Ordenar la segunda mitad y mostrarla
        mergeSort(arr, m + 1, r);
        printf("Sub Array 2: ");
        int j=0;
        for (j = m + 1; j <= r; j++) {
            printf("%d ", arr[j]);
        }
        printf("\n");

        // Combinar las dos mitades ordenadas y mostrar el resultado
        merge(arr, l, m, r);
        swaps +=r-l+1;
        printf("Combinado de sub arrays: ");
        int k=0;
        for (k = l; k <= r; k++) {
            printf("%d ", arr[k]);
        }
        printf("\n\n");
    }
    printf("Intercambios: %d\n", swaps);
}

void countingSort(int arr[], int n, int k, int *comparisons, int *assignments) {
    int i, j;
    int *count = (int *) calloc(k, sizeof(int));
    int *output = (int *) malloc(n * sizeof(int));

    for (i = 0; i < n; i++) {
        count[arr[i]]++;
        (*assignments)++;
    }
    
     printf("Contador de numeros:\n");
    for (i = 0; i < k; i++) {
        printf("count[%d] = %d\n", i, count[i]);
    }
    printf("\n");

    for (i = 1; i < k; i++) {
        count[i] += count[i - 1];
        (*assignments)++;
    }
    
    printf("Indices para colocar  los numeros:\n");
    for (i = 0; i < k; i++) {
        printf("count[%d] = %d\n", i, count[i]);
    }
    printf("\n");

    for (i = n - 1; i >= 0; i--) {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
        (*comparisons)++;
        (*assignments)++;
        
        printf("Inserciones:\n");
        for (j = 0; j < n; j++) {
            printf("%d ", output[j]);
        }
        printf("\n");
    }

    for (i = 0; i < n; i++) {
        arr[i] = output[i];
        (*assignments)++;
    }
	
	printf("\nLista ordenada:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n\n");
	
    free(count);
    free(output);
}

void radixSort(int arr[], int n, int *comparisons, int *assignments) {
    int max = getMax(arr, n);
    int exp=0;
    for (exp = 1; max / exp > 0; exp *= 10) {
        countSort(arr, n, exp, comparisons, assignments);
    }
}


