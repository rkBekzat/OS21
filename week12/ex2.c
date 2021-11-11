#include <linux/input.h>
#include <stdlib.h>
#include <stdio.h>

static const char *const event_values[3] = {"RELEASED", "PRESSED", "REPEATED"};

int main() {
	FILE *file;
	FILE *fp;
	struct input_event event;
	char *str = (char*) malloc(100 * sizeof(char));
	
	fp = fopen("./ex2.txt", "w+");
	file = fopen("/dev/input/by-path/platform-i8042-serio-0-event-kbd", "r");
	if (file != NULL) {
		while(1==1) {
			fread(&event, sizeof(struct input_event), 1, file);
			if (event.type == EV_KEY) {
				sprintf(str,"\n%s 0x%04x (%d)\n", event_values[event.value], event.code, event.code);
				printf(str);
				fputs(str, fp);
				fflush(fp);
			}
		}
		fclose(file);
		fclose(fp);
	}
}
