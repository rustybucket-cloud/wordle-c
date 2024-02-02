#include <stdio.h>
#include "get_word.h"

// to play wordle, you need to:
	// Get a random word. To get a random word, you need to:
	// Repeat 5 times or until user gets it correct
		// Get a user's guess
		// Give the user feedback

int main() {
	printf("Welcome to Wordle!\n");
	char random_word[256] = "";
	if ((get_random_word(random_word)) != 0) {
		perror("Unable to get random word\n");
		return -1;
	}
	printf("%s\n", random_word);
	return 0;
}

