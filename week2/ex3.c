#include <stdio.h>

int n;

char get(int x, int y){
	int cnt = (x * 2 + 1) / 2;
	if((y <= n - 1 && y + cnt >= n - 1) || (y > n - 1 && y - cnt <= n - 1)) return '*';
	return ' ';
}

int  main(){
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		int sz = n + n - 1;
		for(int j = 0; j < sz; j++){
			putchar(get(i, j));
		}
		putchar('\n');
	}
	return 0;
}

