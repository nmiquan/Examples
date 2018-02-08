#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE 1024
#define MAX_REPLACEMENT_LINE 32768

// copy string to new_string replacing all instances of target with replacement

void replace(char string[], char target[], char replacement[], char new_string[], int new_string_len) {
    int i = 0, j = 0;
    int target_length = strlen(target);
    int replacement_length = strlen(replacement);

    i = 0;
    j = 0;
    while (string[i] != '\0' && j < new_string_len - 1) {
        // if we have found the target string
        if (strncmp(target, &string[i], target_length) 	== 0) {
            // instead copy the replacement string to the new array
            strncpy(&new_string[j], replacement, replacement_length);
            i = i + target_length;
            j = j + replacement_length;
        } else {
            new_string[j] = string[i];
            i = i + 1;
            j = j + 1;
        }
    }
    new_string[j] = '\0';
}

int main(int argc, char *argv[]) {
    char line[MAX_LINE];
    char changed_line[MAX_REPLACEMENT_LINE];
    char *target_string;
    char *replacement_string;
    FILE *stream;
    int i;

    if (argc < 3) {
        fprintf(stderr, "Usage: %s <target> <replacement> <files>\n", argv[0]);
        exit(1);
    }
    target_string = argv[1];
    replacement_string = argv[2];
    
    i = 0;
    while (i < argc) {
        stream = fopen(argv[i], "r");
        if (stream == NULL) {
            perror(argv[i]);
            return 1;
        }

        while (fgets(line, MAX_LINE, stream) != NULL) {
            replace(line, target_string, replacement_string, changed_line, MAX_REPLACEMENT_LINE);
            printf("%s", changed_line);
        }
        i = i + 1;
    }
    return 0;
}
