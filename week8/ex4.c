#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/resource.h>
#include <sys/time.h>

int main(){

	struct rusage usage;
	for(int i=0; i<10;i++){
		int *a = malloc(10*1024*1024);
		memset(a, 0, 10*1024*1024);
		getrusage(RUSAGE_SELF, &usage);
		printf("%ld\n", usage.ru_maxrss);
		sleep(1);
	}
}
