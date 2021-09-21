#include<pthread.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>


pthread_t id_thread[100];

void * print(void * num){
        printf("Hello from thread %d\n",*(int *)num);
        printf("Terminating of thread %d\n", *(int *)num);
        pthread_exit(NULL);
}

int main(){
	int n;
	scanf("%d", &n);
        for(int i = 0;i < n;i++){
		int temp = i;
                printf("Creating thread %d\n", i);
                if(pthread_create(&id_thread[i], NULL, &print, &temp) != 0){
                        printf("Failed to create thread\n");
                }
		sleep(1);
        }
        pthread_exit(NULL);
}
