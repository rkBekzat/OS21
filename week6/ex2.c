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
	int temp = table[0].arrival_t + table[0].brust_t;
	double avwt = 0, avtat = 0;
	int ct = temp;
	int tat = ct - table[0].arrival_t;
	int wt = tat - table[0].brust_t;
	avwt += wt;
	avtat += tat;
	printf("P%-7d%-8d%-8d%-8d%-8d%-8d\n", 1, table[0].arrival_t, table[0].brust_t, ct, tat, wt);
	for(int i = 1; i < size; i++){
		int j = i, pos = i, brust = table[i].brust_t;
		while(j < size && table[j].arrival_t <= temp){
			if(brust > table[j].brust_t){
				pos = j;
				brust = table[j].brust_t;
			}
			j++;
		}
		if(i != pos){
			time temp = table[i];
			table[i] = table[pos];
			table[pos] = temp;
		}
		if(temp < table[i].arrival_t)
			temp = table[i].arrival_t;
		temp += table[i].brust_t;
		ct = temp;
		tat = ct - table[i].arrival_t;
		wt = tat - table[i].brust_t;
		avwt += wt;
		avtat += tat;
		printf("P%-7d%-8d%-8d%-8d%-8d%-8d\n", i+1, table[i].arrival_t, table[i].brust_t, ct, tat, wt);
	}
	free(table);
	printf("Average Turnaround Time = %f\n", avtat / size );
	printf("Avarage Waiting Time = %f\n", avwt / size);
}
