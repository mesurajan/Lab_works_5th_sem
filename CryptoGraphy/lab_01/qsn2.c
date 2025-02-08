//2. write a c program to implement vernum cipher

#include <stdio.h>
#include <string.h>

int main() {
    char p[100], key[100], c[100], decrypted[100];

    // Get plaintext and key
    printf("Enter plaintext (lowercase): ");
    scanf("%s", p);
    printf("Enter key (same length as plaintext, lowercase): ");
    scanf("%s", key);

    // Check key length
    if (strlen(p) != strlen(key)) {
        printf("Error: Key length must match plaintext!\n");
        return 1;
    }

    // Encrypt
    for (int i = 0; p[i] != '\0'; i++) {
        c[i] = ((p[i] - 'a') + (key[i] - 'a')) % 26 + 'A'; // Map to uppercase
    }
    c[strlen(p)] = '\0'; // Null-terminate

    // Print encrypted text
    printf("Encrypted: %s\n", c);
    

    // Decrypt
    for (int i = 0; c[i] != '\0'; i++) {
        decrypted[i] = ((c[i] - 'A') - (key[i] - 'a') + 26) % 26 + 'a'; // Map back to lowercase
    }
    decrypted[strlen(c)] = '\0'; // Null-terminate

    // Print decrypted text
    printf("Decrypted: %s\n", decrypted);

    return 0;
}
