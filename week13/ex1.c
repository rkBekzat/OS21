#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <linux/input.h>
#include <string.h>
#include <stdio.h>

int main(){
	int res=3, proc=5;
	int c[proc][res], r[proc][res];
	int resNum[res], avRes[res];
	int used[proc];

	FILE* input = fopen("input_ok.txt", "r");
	FILE* output = fopen("output.txt", "w");
	int cur;
	
	for(int i = 0; i < proc; i++){
		used[i] = 0;
	}

	for(int i = 0; i < res; i++){
		fscanf(input, "%d", &cur);
		resNum[i] = cur;
	}
	
	for(int i = 0; i < res; i++){
		fscanf(input, "%d", &cur);
		avRes[i] = cur;
	}
	for(int i = 0; i < proc; i++){
		for(int j = 0; j < res; j++){
			fscanf(input, "%d", &cur);
			c[i][j] = cur;
		}
	}

	for(int i = 0; i < proc; i++){
		for(int j = 0; j < res; j++){
			fscanf(input, "%d", &cur);
			r[i][j] = cur;
		}
	} 

	int ok = 1;
	while(ok == 1){
		ok = 0;
		for(int i = 0; i < proc; i++){
			int col = 0;
			for(int j = 0; j < res; j++){
				if(r[i][j] < avRes[j]){
					col++;
				}
			}
			if(col == res && used[i] == 0){
				for(int p = 0; p < res; p++){
					avRes[p] += c[i][p];
				}
				ok = 1;
				used[i] = 1;
			}
		}
	}
	int h = 1;
	for (int i = 0; i < proc; i++){
		if(used[i] == 0){
			h = 0;
			fprintf(output, "There has occured availables deadlock in process %d \n", i);
		}
	}
	if(h == 1){
		fprintf(output, "No deadlock detected");
	}
	return 0;
}
