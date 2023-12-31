#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <signal.h>
#include "draw.h"

int generateAsciiChar() {
	return 126 - (rand() % 94);
}

int generateColor() {
	return 37 - (rand() % 7);
}

void fillScreen() {

	for (int x = 1; x <= COLUMN_NUM; x++) {
		for (int y = 1; y <= ROW_NUM; y++) {
			int ascii = generateAsciiChar(); //ASCII 33-126 we want so a random number from 0-93 then subracting will give us a num in range 33-126
			setCursorPosition(x,y);
			setColor(generateColor());
			putchar(ascii);
		}
	}

}

void runCipher() {

	for (int i = 0; i < (ROW_NUM * COLUMN_NUM); i++) {		
		int x = COLUMN_NUM - (rand() % COLUMN_NUM); //COLUMN_NUM(263) subracted by a random number from 0-262 will get random x position
		int y = ROW_NUM - (rand() % ROW_NUM); 		//Same process as x coord
		int ascii = generateAsciiChar();

		setCursorPosition(x,y); //Sets cursor to target position
		setColor(generateColor()); //Set color to randomly generated one	
		putchar(ascii);
	}

}

void sigtint_handler(int sig) {
	endProgram();
	exit(0);
}	

void main() {

	//Set up rand() with a random seed based on time
	time_t t;
	srand((unsigned) time(&t));

	signal(SIGINT, sigtint_handler);
	clear();
	fillScreen();

	while (1) {
		runCipher();
		sleep(.25);
	}

	endProgram();

}
