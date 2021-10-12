#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(){
	for(int i = 0; i < 30; i++){
		int *a = malloc( 1024*1024*1024);
		memset(a, 0, 1024*1024*1024);
		sleep(1);
	}
}
