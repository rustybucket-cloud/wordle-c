#include <string.h>

void create_result_string(char *result_string, char *random_word, char *input) {
	// compare each letter in the guess to the letter in the correct word
	for (int i = 0; i < strlen(random_word); i++) {
		// add the letter if it is correct
		if (random_word[i] == input[i]) {
			char res[] = { random_word[i], '\0' };
			strcat(result_string, res);
			continue;
		}
		
		// add Y if the letter is in the word, but not at the specified index
		char *result = strchr(random_word, input[i]);
		if (result != NULL) {
			strcat(result_string, "Y");
			continue;
		}

		// add X if the letter is not at the word
		strcat(result_string, "X");
	}
}
