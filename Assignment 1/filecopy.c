#include <stdio.h>

int main(int argc, char *argv[]) {
    FILE *source, *destination;
    char ch;

    // Check if the file names are provided
    if(argc != 3) {
        printf("Please provide the source and destination file names.\n");
        return 1;
    }

    // Open the source file
    source = fopen(argv[1], "r");
    if (source == NULL) {
        printf("Unable to open the source file.\n");
        return 1;
    }

    // Open the destination file
    destination = fopen(argv[2], "w");
    if (destination == NULL) {
        printf("Unable to open the destination file.\n");
        fclose(source);
        return 1;
    }

    // Read from the source file and write to the destination file
    while ((ch = fgetc(source)) != EOF) {
        fputc(ch, destination);
    }

    printf("File copied successfully.\n");

    // Close the files
    fclose(source);
    fclose(destination);

    return 0;
}
