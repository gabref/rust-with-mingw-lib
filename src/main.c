#include <stdio.h>
#include "../include/LibHeader.h"

int	main(void)
{
	printf("\n====================\n");
	printf("CONNECT: %d\n", EL_PRINTER_Connect(USB_INTERFACE, NULL, 0));
	printf("SCROLL: %d\n", EL_PRINTER_ScrollPaper(5));
	printf("====================\n");
	return (0);
}
