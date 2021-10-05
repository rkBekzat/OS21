#include <stdio.h>
#include <stdlib.h>


void *myrealloc(int* ptr, int size){
	if(ptr==NULL){
		if(size==0) return NULL;
		return malloc(size);
	}
	memcpy(malloc(size), ptr, size);
	free(ptr);
	return malloc(size);
}

int main(){
	int n;
	scanf("%d", &n);
	int *a = malloc(n*sizeof(int));
	for(int i = 0; i < n; i++){
		printf("%d ", a[i]);
	}
	
	int m ;
	scanf("%d", &m);
	a = myrealloc(a, m*sizeof(int));
	for(int i = 0; i < m; i++){
		printf("%d ", a[i]);
	}
	
}
