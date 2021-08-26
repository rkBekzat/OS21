#include <stdio.h>

void change(int *a, int *b){
	int c = *a;
	*a = *b;
	*b = c;
}


int main(){
	int a, b;
	scanf("%d%d", &a, &b);
	change(&a, &b);
	printf("The value of a: %d\n", a);
	printf("The value of b: %d\n", b);
}
