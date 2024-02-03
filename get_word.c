#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

// Get a random word. To get a random word, you need to:
	// open the file
	// select a random number between 1 and the # of lines in the file
	// get the word at the line #define _GNU_SOURCE
		// get the number of lines
		// get the word

int get_target_line(char *line, int target_line) {
	FILE *file;
	file = fopen("./words.txt", "r");
	if (file == NULL) {
		return -1;
	}

	int current_line = 1;
	char buffer[256];	
	while (fgets(buffer, sizeof(buffer), file)) {
		if (current_line == target_line) {
			strcpy(line, buffer);
			break;
		}
		current_line++;
	}
	return 0;
}

int get_random_number(int numberOfLines) {
	srand(0);
	int random_number = rand() % numberOfLines;
	return random_number;
}

int get_number_of_lines_in_file(FILE *file, int *number_of_lines) {
	char character;
	while((character = fgetc(file)) != EOF) {
		if (character == '\n') {
			(*number_of_lines)++;
		}
	}
	return 0;
}

int get_random_word(char *random_word) {
	FILE *file;
	file = fopen("./words.txt", "r");
	if (file == NULL) {
		return -1;
	}

	int number_of_lines = 0;
	if ((get_number_of_lines_in_file(file, &number_of_lines)) != 0) {
		return -1;
	}

	int random_number = get_random_number(number_of_lines);
	
	if ((get_target_line(random_word, random_number)) != 0) {
		return -1;
	}
	return 0;
}
