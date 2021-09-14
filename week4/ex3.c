#include <stdio.h>
#include <stdlib.h>

int main(){
	char command[1001];
	while(1){
		printf(">: ");
		scanf("%s", command);
		system(command);
	}
}
