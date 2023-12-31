/*
 * While conio.h library exists, I will develop my own library for the sake of learning the console codes for ASCII text handling
 *
 * Type "man console_codes" or visit webpage for comprehensive details on printf commands used
 * "\033" is ASCII escape character used as a control character for the console codes 
 * H code takes ROW;COLUMN format
 *
 * Future developments:
 * 	- Take into account terminal size and terminalk resizes
 *
 */

#include <stdio.h>

#define COLUMN_NUM 237 //Number of columns in default linux terminal
#define ROW_NUM 63    //Number of rows in default linux terminal

void clear() {
	printf("\033[2J");
}

void setCursorPosition(int x, int y) { //H command is in y;x format
	printf("\033[%d;%dH", y, x);
}

void setCursorCenter() {
	int centerRow = ROW_NUM / 2;
	int centerColumn = COLUMN_NUM / 2;
	printf("\033[%d;%dH", centerRow, centerColumn);
}

void setColor(int color) {
	printf("\033[%dm", color);
}

void endProgram() {
	clear();
	setCursorPosition(1,1);
}
