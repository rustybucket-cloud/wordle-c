#include <stdbool.h>
#include <stdio.h>
#include <string.h>

bool is_word_in_list(char *input) {
	FILE *file;
	file = fopen("./words.txt", "r");
	if (file == NULL) {
		printf("Failed to open file\n");
		return false;
	}

	char line[256] = "";
	while (fgets(line, sizeof(line), file)) {
		line[strcspn(line, "\n")] = 0;
		if (strcmp(line, input) == 0) {
			return true;
		}
	}

	return false;
}

int get_user_input(char *input) {
	while (true) {
		fgets(input, sizeof(input), stdin);
		size_t len = strlen(input);
		if (len > 0 && input[len - 1] == '\n') {
			input[len - 1] = '\0';
		}

		if (strlen(input) != 5) {
			printf("Word must be 5 letters. Try again.\n");
			continue;
		}
		if (!is_word_in_list(input)) {
			printf("Word not in word list.Try again.\n");
			continue;
		}
		break;
	}
	return 0;
}

