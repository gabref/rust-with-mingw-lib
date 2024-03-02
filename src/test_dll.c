#include <stdio.h>

extern int init();
extern int scroll();

int main() {
	printf("\nHello from test_dll.c\n");
	init();
	scroll();
	printf("\nBye from test_dll.c\n");
	return 0;
}
