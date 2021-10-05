#include <stdio.h>

int main(){
	char **s=malloc(sizeof(char*));
	char foo[] = "Hello World";
	*s = foo;
	printf("s is %p\n", s);
	s[0] = foo;
	printf("s[0] is %s\n", s[0]);
	return 0;
}
