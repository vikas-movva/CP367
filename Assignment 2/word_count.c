#include <stdio.h>
#include <string.h>

void count_words(char *filename)
{
    FILE *file = fopen(filename, "r");
    if (file == NULL)
    {
        printf("\n%s cannot be opened\n\n", filename);
        return;
    }
    printf("\nContent of %s:\n", filename);
    printf("\n");
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

    printf("\n\nNumber of lines of file1: %d\n", lines);
    printf("Number of words of file1: %d\n", words);
    printf("Average number of words per line of file1: %.2f\n\n", (float)words / lines);

    fclose(file);
}

int main()
{
    char command[256];
    char filename[256];

    do
    {
        printf("Enter command (f: enter file name, q: quit): ");
        fgets(command, 256, stdin);          // read the entire line of input
        command[strcspn(command, "\n")] = 0; // remove the newline character at the end of the string

        if (strlen(command) == 0)
        {
            continue; // ignore empty commands
        }

        if (strcmp(command, "f") == 0)
        {
            printf("Enter file name: ");
            fgets(filename, 256, stdin);
            filename[strcspn(filename, "\n")] = 0; // remove the newline character at the end of the string
            count_words(filename);
        }
        else if (strcmp(command, "q") == 0)
        {
            printf("\nGood bye\n");
        }
        else
        {
            printf("Invalid command.\n");
        }
    } while (strcmp(command, "q") != 0);
    return 0;
}