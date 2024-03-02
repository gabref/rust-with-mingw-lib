# include "../include/LibHeader.h"
# include <stdio.h>

EL_e_Ret EL_PRINTER_Connect(EL_PRINTER_Interface connect_interface, ...) {
	printf("called EL_PRINTER_Connect\n");
	return EL_RET_OK;
}

EL_e_Ret EL_PRINTER_ScrollPaper(int lines) {
	printf("called EL_PRINTER_ScrollPaper\n");
	printf("lines: %d\n", lines);
	return EL_RET_OK;
}

EL_e_Ret EL_PRINTER_PrintSimpleText(String text) {
	printf("called EL_PRINTER_PrintSimpleText\n");
	printf("text: %s\n", text);
	return EL_RET_OK;
}

EL_e_Ret EL_PRINTER_PrintText(EL_PRINTER_TextFormat format, String text) {
	printf("called EL_PRINTER_PrintText\n");
	printf("format fontSize: %d\n", format.fontSize);
	printf("text: %s\n", text);
	return EL_RET_OK;
}

EL_e_Ret EL_PRINTER_GetStatus(EL_PRINTER_Status *status) {
	printf("called EL_PRINTER_GetStatus\n");
	return EL_RET_OK;
}

EL_e_Ret EL_PRINTER_GetCustomStatus(EL_PRINTER_CustomStatus *status) {
	printf("called EL_PRINTER_GetCustomStatus\n");
	return EL_RET_OK;
}
