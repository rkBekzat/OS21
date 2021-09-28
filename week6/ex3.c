#include <stdio.h>
#include <stdlib.h>


typedef struct process{
	int arrival_t,  brust_t;
} time;

int size = 0;

time * parseCsv(const char *filename){
	FILE *fp = fopen(filename, "r");
	if(!fp){
		printf("File doesn't exist");
		exit(1);
	}
	char line[512];
	while(fgets(line, 512, fp)){
		size++;
	}
	freopen(filename, "r", fp);
	time *table = malloc(size * sizeof(time));
	for(int i = 0; i < size; i++){
		fscanf(fp, "%d,%d", &table[i].arrival_t, &table[i].brust_t);
	}
	fclose(fp);
	return table;
}


int compare(time *a, time * b){
	return a->arrival_t - b->arrival_t;
}


int main(){
	time *table = parseCsv("new_input.csv");
	qsort(table, size, sizeof(time), compare);
	printf("#p      AT      BT      CT      TAT      WT\n");
	int temp = 0;
	double  avwt = 0, avtat = 0;
	for(int i = 0; i < size; i++){
		if(temp < table[i].arrival_t)
			temp = table[i].arrival_t;
		temp += table[i].brust_t;
		int ct = temp;
		int tat = ct - table[i].arrival_t;
		int wt = tat - table[i].brust_t;
		avwt += wt;
		avtat += tat;
		printf("P%-7d%-8d%-8d%-8d%-8d%-8d\n", i+1, table[i].arrival_t, table[i].brust_t, ct, tat, wt);
	}
	printf("Average Turnaround Time  = %f\n", (double)avtat / size);
	printf("Average Waiting Time = %f\n", (double)avwt / size);
	free(table);
}


