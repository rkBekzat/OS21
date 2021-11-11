#include <linux/input.h>
#include <stdlib.h>
#include <stdio.h>


static int queue[5];

void push(int value) {
	for (int i = 1; i < 5; ++i) {
		queue[i - 1] = queue[i];
	}
	queue[4] = value;
}

int main() {
	FILE *file;
	FILE *fp;
	struct input_event event;
	int state = 0;
	short P_PRESSED = 0, E_PRESSED = 0, A_PRESSED = 0, C_PRESSED = 0, K_PRESSED = 0;
	
	fp = fopen("./ex3.txt", "w+");
	file = fopen("/dev/input/by-path/platform-i8042-serio-0-event-kbd", "r");
	if (file != NULL) {
		fflush(fp);
		while(1) {
			fread(&event, sizeof(struct input_event), 1, file);
			if (event.type == EV_KEY && event.value == 1) {
				push(event.code);
				if(queue[4] == KEY_E && queue[3] == KEY_P){
					
					printf("I passed the Exam!\n");
					fputs("I passed the Exam!\n", fp);
				}
				if(queue[4] == KEY_P && queue[3] == KEY_A && queue[2] == KEY_C){
					printf("Get some cappuccino!\n");
					fputs("Get some cappuccino!\n", fp);
				}
				if(queue[4] == KEY_K && queue[3] == KEY_O){
					printf("HELLO!\n");
					fputs("HELLO!\n", fp);	
				}
				fflush(fp);
			}
		}
		fclose(file);
		fclose(fp);
	}
}
