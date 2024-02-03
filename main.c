#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "get_word.h"
#include "get_user_input.h"

bool compare_input_and_word(char *input, char *random_word) {
	return strcmp(input, random_word) == 0;
}

void get_result_string(char *result_string, char *random_word, char *input) {
	for (int i = 0; i < 5; i++) {
		if (random_word[i] == input[i]) {
			char res[] = { random_word[i], '\0' };
			strcat(result_string, res);
		} else {
			strcat(result_string, "X");
		}
	}
}

int main() {
	printf("Welcome to Wordle!\n");
	char random_word[256] = "";
	if ((get_random_word(random_word)) != 0) {
		perror("Unable to get random word\n");
		return -1;
	}
	random_word[strcspn(random_word, "\n")] = 0;
	printf("random word: %s\n", random_word);
	printf("Enter a 5 letter word below\n");

	int guess_count = 0;
	while (guess_count < 5) {
		char input[100] = "";
		if ((get_user_input(input)) != 0) {
			perror("Unable to get user input: ");
			return -1;
		} 

		if (compare_input_and_word(input, random_word)) {
			printf("Correct!\n");
			break;
		} 

		char result_string[10] = "";
		get_result_string(result_string, random_word, input);

		printf("%s\n", result_string);
		guess_count++;
	}

	return 0;
}

