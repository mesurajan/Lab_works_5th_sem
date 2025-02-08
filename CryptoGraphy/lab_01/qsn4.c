//4. write a c program to implement hill cipher with  key is 3*3.
#include <stdio.h>
#include <string.h>

#define MOD 26

void encrypt(char plaintext[], int key[3][3]) {
    int length = strlen(plaintext);

    // Ensure plaintext length is a multiple of 3, if not, add 'x' as padding
    while (length % 3 != 0) {
        strcat(plaintext, "x");
        length++;
    }

    printf("Encrypted Text: ");

    for (int i = 0; i < length; i += 3) {
        int a = plaintext[i] - 'a';
        int b = plaintext[i + 1] - 'a';
        int c = plaintext[i + 2] - 'a';

        int c1 = (key[0][0] * a + key[0][1] * b + key[0][2] * c) % MOD;
        int c2 = (key[1][0] * a + key[1][1] * b + key[1][2] * c) % MOD;
        int c3 = (key[2][0] * a + key[2][1] * b + key[2][2] * c) % MOD;

        printf("%c%c%c", c1 + 'A', c2 + 'A', c3 + 'A');  // Convert back to uppercase
    }

    printf("\n");
}

int main() {
    char plaintext[100];  // Supports longer plaintext
    int key[3][3];

    // Taking user input for the 3x3 key matrix
    printf("Enter the 3x3 key matrix (row-wise):\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            scanf("%d", &key[i][j]);
        }
    }

    // Taking user input for the plaintext
    printf("Enter plaintext in small caps: ");
    scanf("%s", plaintext);

    encrypt(plaintext, key);

    return 0;
}
