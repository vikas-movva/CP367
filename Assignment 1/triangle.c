#include <stdio.h>

int main()
{
    int num_rows = 1;
    int count = 1;
    int k = 1;
    printf("Enter the number of rows in Pascal's triangle: ");
    while (scanf("%d", &num_rows) != 1 || num_rows < 1 || num_rows > 15)
    {
        printf("Invalid input! Please enter a positive integer less than 15: ");
        while (getchar() != '\n');
    }
    int pascal[num_rows][num_rows];
    for (int i = 0; i < num_rows; i++)
    {
        for (int j = 0; j < num_rows; j++)
        {
            pascal[i][j] = 0;
        }
    }
    for (count = 0; count < num_rows; count++)
    {
        for (k = 0; k <= count; k++)
        {
            if (k == 0 || count == 0)
                pascal[count][k] = 1;
            else
                pascal[count][k] = pascal[count - 1][k - 1] + pascal[count - 1][k];
        }
    }
    for (count = 0; count < num_rows; count++)
    {
        for (k = 0; k <= count; k++)
            printf("%5d ", pascal[count][k]);
        printf("\n");
    }
    return 0;
}
