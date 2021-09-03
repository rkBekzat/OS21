#include <stdio.h>
#include <stdlib.h>

#define ARR_SIZE(x) (sizeof(x)/sizeof((x)[0]))

void swap(int* a, int* b){
	int c = *a;
	a = b;
	*b = c;
}

void BubbleSort(int arr[], int arr_len){
	for(int i = 0; i < arr_len; i++){
		for(int j = 0; j + 1 < arr_len; j++){
			if(arr[j] > arr[j+1]){
				swap(&arr[j], &arr[j+1]);
			}
		}
	}
}



void print_array(int arr[], int arr_size){
	for(int i = 0; i < arr_size; i++){
		printf("%d ", arr[i]);
	}
}



int main(){
	int a[] = {2, 3, 4, 1, 2, 1, 10, 21, 1, 2};
	printf("Initial array:\n");
	print_array(a, ARR_SIZE(a));
	printf("\n");
	BubbleSort(a, ARR_SIZE(a));
	printf("Array after bubble sort\n");
	print_array(a, ARR_SIZE(a));
	return 0;
}
