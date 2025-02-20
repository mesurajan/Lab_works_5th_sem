#include <stdio.h>
#include <string.h>

#define MOD 26
#define SIZE 3  // Defines a 3x3 matrix

// Function to find the modular inverse of a number under MOD 26
int mod_inverse(int a) {
    for (int i = 1; i < MOD; i++) {
        if ((a * i) % MOD == 1) {
            return i;
        }
    }
    return -1;
}

// Function to find the determinant of a 3x3 matrix
int determinant(int key[SIZE][SIZE]) {
    return (key[0][0] * (key[1][1] * key[2][2] - key[1][2] * key[2][1]) -
            key[0][1] * (key[1][0] * key[2][2] - key[1][2] * key[2][0]) +
            key[0][2] * (key[1][0] * key[2][1] - key[1][1] * key[2][0])) % MOD;
}

// Function to find the adjugate of a 3x3 matrix
void adjugate(int key[SIZE][SIZE], int adj[SIZE][SIZE]) {
    adj[0][0] = (key[1][1] * key[2][2] - key[1][2] * key[2][1]) % MOD;
    adj[0][1] = (key[0][2] * key[2][1] - key[0][1] * key[2][2]) % MOD;
    adj[0][2] = (key[0][1] * key[1][2] - key[0][2] * key[1][1]) % MOD;
    adj[1][0] = (key[1][2] * key[2][0] - key[1][0] * key[2][2]) % MOD;
    adj[1][1] = (key[0][0] * key[2][2] - key[0][2] * key[2][0]) % MOD;
    adj[1][2] = (key[0][2] * key[1][0] - key[0][0] * key[1][2]) % MOD;
    adj[2][0] = (key[1][0] * key[2][1] - key[1][1] * key[2][0]) % MOD;
    adj[2][1] = (key[0][1] * key[2][0] - key[0][0] * key[2][1]) % MOD;
    adj[2][2] = (key[0][0] * key[1][1] - key[0][1] * key[1][0]) % MOD;
}

// Function to find the inverse of a 3x3 matrix modulo 26
int inverse_key(int key[SIZE][SIZE], int inverse[SIZE][SIZE]) {
    int det = determinant(key);
    if (det < 0) det += MOD;
    int det_inv = mod_inverse(det);
    if (det_inv == -1) {
        printf("Inverse does not exist for the given key matrix.\n");
        return 0;
    }
    int adj[SIZE][SIZE];
    adjugate(key, adj);
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            inverse[i][j] = (adj[i][j] * det_inv) % MOD;
            if (inverse[i][j] < 0) inverse[i][j] += MOD;
        }
    }
    return 1;
}

void encrypt(char plaintext[], int key[SIZE][SIZE]) {
    int length = strlen(plaintext);

    while (length % SIZE != 0) {
        strcat(plaintext, "x");
        length++;
    }

    printf("Encrypted Text: ");
    for (int i = 0; i < length; i += SIZE) {
        int plain_vector[SIZE];
        int cipher_vector[SIZE] = {0};

        for (int j = 0; j < SIZE; j++) {
            plain_vector[j] = plaintext[i + j] - 'a';
        }

        for (int row = 0; row < SIZE; row++) {
            for (int col = 0; col < SIZE; col++) {
                cipher_vector[row] += key[row][col] * plain_vector[col];
            }
            cipher_vector[row] %= MOD;
        }

        for (int j = 0; j < SIZE; j++) {
            printf("%c", cipher_vector[j] + 'A');
        }
    }
    printf("\n");
}

void decrypt(char ciphertext[], int inverse_key[SIZE][SIZE]) {
    int length = strlen(ciphertext);
    printf("Decrypted Text: ");
    for (int i = 0; i < length; i += SIZE) {
        int cipher_vector[SIZE];
        int plain_vector[SIZE] = {0};

        for (int j = 0; j < SIZE; j++) {
            cipher_vector[j] = ciphertext[i + j] - 'A';
        }

        for (int row = 0; row < SIZE; row++) {
            for (int col = 0; col < SIZE; col++) {
                plain_vector[row] += inverse_key[row][col] * cipher_vector[col];
            }
            plain_vector[row] %= MOD;
        }

        for (int j = 0; j < SIZE; j++) {
            printf("%c", plain_vector[j] + 'a');
        }
    }
    printf("\n");
}

int main() {
    char plaintext[100], ciphertext[100];
    int key[SIZE][SIZE], inverse[SIZE][SIZE];

    printf("Enter the 3x3 key matrix (row-wise):\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            scanf("%d", &key[i][j]);
        }
    }

    printf("Enter plaintext in small caps: ");
    scanf("%s", plaintext);

    encrypt(plaintext, key);
    printf("\nEnter the encrypted text: ");
    scanf("%s", ciphertext);

    if (inverse_key(key, inverse)) {
        decrypt(ciphertext, inverse);
    }

    return 0;
}
