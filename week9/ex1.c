#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>

struct page{
	int id;
	int counter;
};

int main(){
	int n;
	scanf("%d", &n);
	FILE *file = fopen("Lab 09 input.txt", "r");
	struct page pages[n];

	for(int i = 0; i < n; i++){
		pages[i].id = -1;
		pages[i].counter = 0;
	}
	int miss=0, hit=0;
	int pageId;
	while(fcsanf(file, "%d", &pageId) == 1){
		int found = 0;
		for(int i = 0; i < n; i++){
			if(pages[i].id == pageId){
				found=1;
				break;
			}
		}
		if(found == 0){
			int free = 0;
			for(int i = 0; i < n; i++){
				if(pages[i].id == -1){
					pages[i].id = pageId;
					pages[i].counter = 0;
					free = 1;
					break;
				}
			}
			if(free) continue;
			int minCnt = pages[0].counter;
			int index = 0;
			for(int i = 1; i < n; i++){
				if(minCnt > pages[i].counter){
					minCnt = pages[i].counter;
					index = i;
				}
			}
			pages[index].id = pageId;
			pages[index].counter = 0;
		}
		for(int i = 0; i < n; i++){
			pages[i].counter /= 2;
			if(found && pageId == pages[i].id) pages[i].counter |= (1<<31);
		}
		if(found) hit++;
		else miss++;
	}
	printf("Hit: %d, Miss: %d Ratio: %f\n", hit, miss, (float)hit/(float)miss);
	fclose(file);
	return 0;
}
