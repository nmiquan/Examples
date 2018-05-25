// Print lines from file, replacing specified pattern
// Andrew Taylor - andrewt@cse.unsw.edu.au
// 4/4/17

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_LINE 10240
#define MAX_OUTPUT_LINE 32768

// copy string to new_string
// replacing all instances of target with replacement

void replace(char string[], char target[], char replacement[],
             char new_string[], int new_string_max_length)
{
    // replace all occurences of target by replacement
    // while copying string[] to new_string[]
}

int main(int argc, char *argv[])
{
    char line[MAX_INPUT_LINE];
    char changed_line[MAX_OUTPUT_LINE];
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

    i = 1;
    while (i < argc) {
        stream = fopen(argv[i], "r");
        if (stream == NULL) {
            perror(argv[i]);
            return 1;
        }

        while (fgets(line, MAX_INPUT_LINE, stream) != NULL) {
            replace(line, target_string, replacement_string,
                    changed_line, MAX_OUTPUT_LINE);
            printf("%s", changed_line);
        }

        i = i + 1;
    }
    return 0;
}
