#include <stdio.h>
#include <limits.h>
#include <float.h>

int main(){
	int a = INT_MAX;
	float b = FLT_MAX ;
	double c = DBL_MAX;
	printf("Size of integer is %ld and value is %d\n", sizeof(a), a);
	printf("Size of float is %ld and value is %f\n", sizeof(b), b);
	printf("Size of double is %ld and value is %f \n" , sizeof(c), c);
	return 0;
}
