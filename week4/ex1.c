#include <stdio.h>
#include <sys/types.h>
#include  <unistd.h>

int main(){
	int n = fork();
	if(n == 0){
		printf("Hello from child [%i - %i]\n", n, 4);
	}
	else{
		printf("Hello from parent [%i - %i]\n", n, 4);
	} 
	return 0;
}
