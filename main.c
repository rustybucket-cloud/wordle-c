#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "get_word.h"

// to play wordle, you need to:
	// Get a random word. To get a random word, you need to:
	// Repeat 5 times or until user gets it correct
		// Get a user's guess
		// Give the user feedback

int get_user_input(char *input) {
	scanf("%s", input);
	return 0;
}

bool compare_input_and_word(char *input, char *random_word) {
	if (strcmp(input, random_word) == 0) {
		return true;
	} else {
		return false;
	}
}

void get_result_string(char *result_string, char *random_word, char *input, int index) {
	if (random_word[index] == input[index]) {
		char res[] = { random_word[index], '\0' };
		strcat(result_string, res);
	} else {
		strcat(result_string, "X");
	}
}

int main() {
	printf("Welcome to Wordle!\n");
	char random_word[256] = "";
	if ((get_random_word(random_word)) != 0) {
		perror("Unable to get random word\n");
		return -1;
	}
	printf("random word: %s\n", random_word);

	int guess_count = 0;
	while (guess_count < 5) {
		char input[100] = "";
		get_user_input(input);

		if (compare_input_and_word(input, random_word)) {
			printf("Correct!\n");
			break;
		} else {
			char result_string[10] = "";
			for (int i = 0; i < 5; i++) {
				get_result_string(result_string, random_word, input, i);
			}
			printf("%s\n", result_string);
		}
		guess_count++;
	}

	return 0;
}

