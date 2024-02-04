#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "get_word.h"
#include "get_user_input.h"
#include "create_result_string.h"

int main() {
	printf("Welcome to Wordle!\n");
	char random_word[256] = "";
	if ((get_random_word(random_word)) != 0) {
		perror("Unable to get random word\n");
		return -1;
	}
	random_word[strcspn(random_word, "\n")] = 0;
	printf("Enter a 5 letter word below\n");

	int guess_count = 0;
	while (guess_count < 5) {
		char input[100] = "";
		if ((get_user_input(input)) != 0) {
			perror("Unable to get user input: ");
			return -1;
		} 

		if (strcmp(input, random_word) == 0) {
			printf("Correct!\n");
			break;
		} 

		char result_string[10] = "";
		create_result_string(result_string, random_word, input);

		printf("%s\n", result_string);
		guess_count++;
	}

	return 0;
}

