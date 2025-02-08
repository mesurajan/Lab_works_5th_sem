//1. write a c program to impelment ceaser and shift cipher
#include <stdio.h>

int main() {
    char plaintext[100], ciphertext[100], decrypted[100];
    int key, i;

    printf("Enter plain text in small caps: ");
    scanf("%s", plaintext);

    printf("Enter the shift key: ");
    scanf("%d", &key);

    // Encryption
    for (i = 0; plaintext[i] != '\0'; i++) {
        ciphertext[i] = ((plaintext[i] - 'a' + key) % 26) + 'A';
    }
    ciphertext[i] = '\0';

    printf("Encrypted Text: %s\n", ciphertext);

    // Decryption
    for (i = 0; ciphertext[i] != '\0'; i++) {
        decrypted[i] = ((ciphertext[i] - 'A' - key + 26) % 26) + 'a';
    }
    decrypted[i] = '\0';

    printf("Decrypted Text: %s\n", decrypted);

    return 0;
}
