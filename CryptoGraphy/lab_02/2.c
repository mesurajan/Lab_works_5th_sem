//2. Write a c program to implement play fair cipher.
#include <stdio.h>
#include <string.h>

#define SIZE 5

int main() {
    char key[100], plaintext[100], ciphertext[100],dplaintext[100];
    char matrix[SIZE][SIZE];
    int visited[26] = {0}; // To track visited letters
    int i, j, k = 0, length, row1, col1, row2, col2;
    char pair[2];

    // Input the key and the plaintext
    printf("Enter the key: ");
    fgets(key, sizeof(key), stdin);
    key[strcspn(key, "\n")] = '\0';  // Remove newline character

    printf("Enter the plaintext: ");
    fgets(plaintext, sizeof(plaintext), stdin);
    plaintext[strcspn(plaintext, "\n")] = '\0';  // Remove newline character

    // Step 1: Preprocess the key and remove duplicates
    char key_modified[strlen(key) + 1];
    for (i = 0; key[i] != '\0'; i++) {
        // Manually convert to uppercase
        if (key[i] >= 'a' && key[i] <= 'z') {
            key_modified[i] = key[i] - 'a' + 'A';
        } else {
            key_modified[i] = key[i];
        }
    }
    key_modified[i] = '\0';

    // Step 2: Fill the matrix with the key letters first
    
    k = 0;
    for (i = 0; i < strlen(key_modified); i++) {
        if (key_modified[i] != 'J' && !visited[key_modified[i] - 'A']) {
            visited[key_modified[i] - 'A'] = 1;
            matrix[k / SIZE][k % SIZE] = key_modified[i];
            k++;
        }
    }

    // Step 3: Fill the remaining spots with the rest of the alphabet
    for (i = 0; i < 26; i++) {
        if (i != 'J' - 'A' && !visited[i]) {
            matrix[k / SIZE][k % SIZE] = 'A' + i;
            k++;
        }
    }

    // Step 4: Preprocess the plaintext (convert to uppercase and handle duplicate letters)
    length = strlen(plaintext);
    for (i = 0; i < length; i++) {
        // Manually convert to uppercase
        if (plaintext[i] >= 'a' && plaintext[i] <= 'z') {
            plaintext[i] = plaintext[i] - 'a' + 'A';
        }
    }

    // Handle duplicate letters in plaintext
    for (i = 0; i < length - 1; i++) {
        if (plaintext[i] == plaintext[i + 1]) {
            for (j = length; j > i + 1; j--) {
                plaintext[j] = plaintext[j - 1];
            }
            plaintext[i + 1] = 'X';  // Insert 'X' between duplicate letters
            length++;
        }
    }

    // If the length of plaintext is odd, append 'X'
    if (length % 2 != 0) {
        plaintext[length] = 'X';  // Add 'X' if length is odd
        plaintext[length + 1] = '\0';
        length++;
    }

    // Step 5: Encrypt the message
    k = 0;
    for (i = 0; i < length; i += 2) {
        pair[0] = plaintext[i];
        pair[1] = plaintext[i + 1];

        // Find positions of the pair letters in the matrix
        for (int row = 0; row < SIZE; row++) {
            for (int col = 0; col < SIZE; col++) {
                if (matrix[row][col] == pair[0]) {
                    row1 = row;
                    col1 = col;
                }
                if (matrix[row][col] == pair[1]) {
                    row2 = row;
                    col2 = col;
                }
            }
        }

        // Apply Playfair cipher rules
        if (row1 == row2) {
            // Same row: Move to the right
            col1 = (col1 + 1) % SIZE;
            col2 = (col2 + 1) % SIZE;
        } else if (col1 == col2) {
            // Same column: Move down
            row1 = (row1 + 1) % SIZE;
            row2 = (row2 + 1) % SIZE;
        } else {
            // Rectangle: Swap the corners
            int temp = col1;
            col1 = col2;
            col2 = temp;
        }

        // Store the result pair in the ciphertext
        ciphertext[k++] = matrix[row1][col1];
        ciphertext[k++] = matrix[row2][col2];
    }
    ciphertext[k] = '\0';

    // Print the Playfair matrix
    printf("\nPlayfair Matrix:\n");
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            printf("%c ", matrix[i][j]);
        }
        printf("\n");
    }

    
// Step 6: Decrypt the message
    k = 0;
    for (i = 0; i < length; i += 2) {
        pair[0] = ciphertext[i];
        pair[1] = ciphertext[i + 1];

        // Find positions of the pair letters in the matrix
        for (int row = 0; row < SIZE; row++) {
            for (int col = 0; col < SIZE; col++) {
                if (matrix[row][col] == pair[0]) {
                    row1 = row;
                    col1 = col;
                }
                if (matrix[row][col] == pair[1]) {
                    row2 = row;
                    col2 = col;
                }
            }
        }

        // Apply Playfair cipher rules
        if (row1 == row2) {
            // Same row: Move to the left
            col1 = (col1 - 1) % SIZE;
            col2 = (col2 - 1) % SIZE;
        } else if (col1 == col2) {
            // Same column: Move up
            row1 = (row1 - 1) % SIZE;
            row2 = (row2 - 1) % SIZE;
        } else {
            // Rectangle: Swap the corners
            int temp = col1;
            col1 = col2;
            col2 = temp;
        }

        // Store the result pair in the ciphertext
        dplaintext[k++] = matrix[row1][col1];
        dplaintext[k++] = matrix[row2][col2];
    }
    dplaintext[k] = '\0';


    // Output the ciphertext
    printf("-------------Encryption-----------");

    printf("\nCiphertext: %s\n", ciphertext);
    //plaintext output
    printf("-------------Decryption-----------");
    printf("\nPlaintext: %s\n",dplaintext);

    return 0;
}
