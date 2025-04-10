//2. Write C program to generate function of S-Box in DES
#include <stdio.h>
#include <string.h>

int S_BOX[4][16] =
{
    {14, 4, 13, 1, 2, 15, 11, 8, 3, 10, 6, 12, 5, 9, 0, 7},
    {0, 15, 7, 4, 14, 2, 13, 1, 10, 6, 12, 11, 9, 5, 3, 8},
    {4, 1, 14, 8, 13, 6, 2, 11, 15, 12, 9, 7, 3, 10, 5, 0},
    {15, 12, 8, 2, 4, 9, 1, 7, 5, 11, 3, 14, 10, 0, 6, 13}
};

int binaryToDecimal(const char *binary, int length)
{
    int value = 0;
    while (length--)
    {
        value = value * 2 + (*binary++ - '0');
    }
    return value;
}

void decimalToBinary(int number, char *binary)
{
    for (int i = 3; i >= 0; i--)
    {
        binary[3 - i] = (number & (1 << i)) ? '1' : '0';
    }
    binary[4] = '\0';
}

int main()
{
    char input[49];
    printf("Enter a 48-bit binary input: ");
    scanf("%48s", input);

    if (strlen(input) != 48)
    {
        printf("Error: Input must be exactly 48 bits!\n");
        return 1;
    }

    printf("\nS-Box Results:\n");

    for (int i = 0; i < 8; i++)
    {
        int row = (input[i * 6] - '0') * 2 + (input[i * 6 + 5] - '0');
        int col = binaryToDecimal(input + i * 6 + 1, 4);
        int output = S_BOX[row][col];

        char binaryOutput[5];
        decimalToBinary(output, binaryOutput);

        printf("S-Box %d: Decimal = %d, Binary = %s\n", i + 1, output, binaryOutput);
    }
    return 0;
}