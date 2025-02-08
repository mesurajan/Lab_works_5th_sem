//3. write a c program to implement hill cipher with key is 2*2 .
#include <stdio.h>
#include <string.h>

#define MOD 26

void encrypt(char plaintext[], int key[2][2]) {
    int length = strlen(plaintext);

    // Ensure plaintext length is even, if odd, add 'x' as padding
    if (length % 2 != 0) {
        strcat(plaintext, "x");
        length++;
    }

    printf("Encrypted Text: ");

    for (int i = 0; i < length; i += 2) {
        int a = plaintext[i] - 'a';      // Convert to number (0-25)
        int b = plaintext[i + 1] - 'a';  // Convert to number (0-25)

        int c1 = (key[0][0] * a + key[0][1] * b) % MOD;
        int c2 = (key[1][0] * a + key[1][1] * b) % MOD;

        printf("%c%c", c1 + 'A', c2 + 'A');  // Convert back to uppercase letters
    }

    printf("\n");
}

int main() {
    char plaintext[100];  // Supports longer plaintext
    int key[2][2];

    // Taking user input for the 2x2 key matrix
    printf("Enter the 2x2 key matrix (row-wise):\n");
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            scanf("%d", &key[i][j]);
        }
    }

    // Taking user input for the plaintext
    printf("Enter plaintext in small caps: ");
    scanf("%s", plaintext);

    encrypt(plaintext, key);

    return 0;
}

