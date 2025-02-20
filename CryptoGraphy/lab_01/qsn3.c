#include <stdio.h>
#include <string.h>

#define MOD 26

// Function to compute modular inverse of a number under MOD 26
int modInverse(int a) {
    for (int i = 1; i < MOD; i++) {
        if ((a * i) % MOD == 1)
            return i;
    }
    return -1;
}

// Function to find the inverse of a 2x2 matrix under modulo 26
void inverseKey(int key[2][2], int inverse[2][2]) {
    int det = (key[0][0] * key[1][1] - key[0][1] * key[1][0]) % MOD;
    if (det < 0)
        det += MOD;
    int detInv = modInverse(det);
    
    if (detInv == -1) {
        printf("Key matrix is not invertible under mod 26!\n");
        return;
    }
    
    inverse[0][0] = (key[1][1] * detInv) % MOD;
    inverse[0][1] = (-key[0][1] * detInv) % MOD;
    inverse[1][0] = (-key[1][0] * detInv) % MOD;
    inverse[1][1] = (key[0][0] * detInv) % MOD;
    
    if (inverse[0][1] < 0) inverse[0][1] += MOD;
    if (inverse[1][0] < 0) inverse[1][0] += MOD;
}

// Function to encrypt the plaintext
void encrypt(char text[], int key[2][2]) {
    int length = strlen(text);
    if (length % 2 != 0) {
        strcat(text, "x");
        length++;
    }
    printf("Encrypted Text: ");
    for (int i = 0; i < length; i += 2) {
        int a = text[i] - 'a';
        int b = text[i + 1] - 'a';
        int c1 = (key[0][0] * a + key[0][1] * b) % MOD;
        int c2 = (key[1][0] * a + key[1][1] * b) % MOD;
        printf("%c%c", c1 + 'A', c2 + 'A');
        text[i] = c1 + 'A';
        text[i + 1] = c2 + 'A';
    }
    printf("\n");
}

// Function to decrypt the ciphertext
void decrypt(char text[], int inverse[2][2]) {
    int length = strlen(text);
    printf("Decrypted Text: ");
    for (int i = 0; i < length; i += 2) {
        int a = text[i] - 'A';
        int b = text[i + 1] - 'A';
        int c1 = (inverse[0][0] * a + inverse[0][1] * b) % MOD;
        int c2 = (inverse[1][0] * a + inverse[1][1] * b) % MOD;
        printf("%c%c", c1 + 'a', c2 + 'a');
    }
    printf("\n");
}

int main() {
    char text[100];
    int key[2][2], inverse[2][2];
    
    // Input key matrix
    printf("Enter the 2x2 key matrix (row-wise):\n");
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            scanf("%d", &key[i][j]);
        }
    }
    
    // Compute inverse key matrix
    inverseKey(key, inverse);
    
    // Input plaintext
    printf("Enter plaintext in small caps: ");
    scanf("%s", text);
    
    // Encrypt
    encrypt(text, key);
    
    // Decrypt
    decrypt(text, inverse);
    
    return 0;
}
