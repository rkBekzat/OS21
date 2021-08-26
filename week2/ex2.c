#include <stdio.h>

void f(){
	char c = getchar();
	if(c == '\n') return ;
	f();
	putchar(c);
}

int main(){
	f();
	return 0;
}
