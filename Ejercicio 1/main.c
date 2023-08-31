#include <stdio.h>
#include <stdlib.h>
#include "utilidades.h"
#include "ordenamientos.h"


int main(){
	int d, r, list[50], num;
	num=sizeof(list)/sizeof(list[0]);
	llenarArreglo(list, num);
	printf("La lista generada es:\n");
	printArray(list,num);
	
	inicio: 
	
	printf("\nSelecciona una de las siguientes opciones\n1) Insertion Sort\n2) Selection Sort\n3) Bubble Sort\n4) Quick Sort\n5) Heap Sort\n6) Merge Sort\n7) Counting Sort\n8) Radix Sort\n9) Crear nueva lista\n");
	scanf("%d",&d);
	switch(d){
		int comparisons=0;
		int assignments=0;
		case 1:
			printf("\tInsertion Sort\n");
			printArray(list, num);
			insertionSort(list, num);
		break;
		case 2:
			printf("\tSelection Sort\n");
			printArray(list, num);
			selectionSort(list, num,&comparisons,&assignments);
			printf("Comparaciones: %d\n", comparisons);
    		printf("Asignaciones: %d\n", assignments);
		break;
		case 3:
			printf("\tBubble Sort\n");
			printArray(list, num);
			bubbleSort(list, num);
			int totalDeOperaciones= bubbleSort(list,num);
    		printf("Total de operaciones: %d\n", totalDeOperaciones);
		break;
		case 4:
			printf("\tQuick Sort\n");
			printArray(list, num);
			quickSort(list,0,num,&comparisons,&assignments);
			printf("La lista queda como:\n");
			printArray(list,num);
			printf("Comparaciones: %d\n", comparisons);
    		printf("Asignaciones: %d\n", assignments);
		break;
		case 5:
			printf("\tHeap Sort\n");
			printArray(list, num);
			int *arr;
			arr=list;
			HeapSort(list,num, &assignments);
			printf("Asignaciones: %d\n", assignments);
		break;
		case 6:
			printf("\tMerge Sort\n");
			printArray(list, num);
			mergeSort(list,0,num-1);
			printf("La lista queda como:\n");
			printArray(list,num);
		break;
		case 7:
			printf("\tCounting  Sort\n");
			printArray(list, num);
			countingSort(list,num,100,&comparisons,&assignments);
			printf("La lista queda como:\n");
			printArray(list,num);
			printf("Comparaciones: %d\n", comparisons);
    		printf("Asignaciones: %d\n", assignments);
		break;
		case 8:
			printf("\tRadix Sort\n");
			printArray(list,num);
			radixSort(list, num,&comparisons,&assignments);
			printf("La lista queda como:\n");
			printArray(list,num);
			printf("Comparaciones: %d\n", comparisons);
    		printf("Asignaciones: %d\n", assignments);
		break;
		case 9:
			llenarArreglo(list, num);
			printf("La lista generada es:\n");
			printArray(list,num);
		break;
		
		default:
		break;
			
	}
	printf("\nVa a realizar otra accion?\nSi=introduzca 1\nNo= Introduzca 0\n");
	scanf("%d",&r);
	if(r==1){
		goto inicio;
	}
	
}
