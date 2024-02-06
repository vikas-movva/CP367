#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int count_words(char *filename)
{
    FILE *file = fopen(filename, "r");
    if (file == NULL)
    {
        printf("Cannot open file %s\n", filename);
        return 1;
    }

    int ch, prev_ch = '\0', lines = 0, words = 0, chars = 0;
    while ((ch = fgetc(file)) != EOF)
    {
        putchar(ch);
        chars++;
        if (ch == '\n')
        {
            lines++;
            if (prev_ch != ' ' && prev_ch != '\n' && prev_ch != '\0')
            {
                words++;
            }
        }
        else if (ch == ' ' && prev_ch != ' ' && prev_ch != '\n' && prev_ch != '\0')
        {
            words++;
        }
        prev_ch = ch;
    }

    if (chars > 0 && prev_ch != ' ' && prev_ch != '\n')
    {
        words++;
        lines++;
    }

    printf("\nLines: %d\n", lines);
    printf("Words: %d\n", words);
    printf("Average words per line: %.2f\n", (float)words / lines);

    fclose(file);
    return 0;
}

int main()
{
    char command[256];
    char filename[256];

    do
    {
        printf("Enter command (f: enter file name, q: quit): ");
        fgets(command, 256, stdin);
        if (strlen(command) == 2)
        {

            switch (command[0])
            {
            case 'f':
                printf("Enter file name: ");
                scanf("%s", filename);
                count_words(filename);
                if (count_words(filename) == 1)
                {
                    break;
                }
            case 'q':
                printf("Quitting program.\n");
                break;
            default:
                printf("Invalid command.\n");
            }
        }
        else
        {
            printf("Invalid command.\n");
        }

    } while (*command != 'q');

    return 0;
}
