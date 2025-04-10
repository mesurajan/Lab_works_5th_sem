//3. Write a c program to implement rail fence cipher
#include <stdio.h>
#include <string.h>

int main() {
    char text[100],ciphertext[100],decryptedtext[100];
    int rails, length, row, direction,k=0;

    printf("Enter the message to be encrypted: ");
    fgets(text, sizeof(text), stdin);
    
    // Remove newline character if present at the end of input
    text[strcspn(text, "\n")] = '\0';

    printf("Enter the number of rails: ");
    scanf("%d", &rails);

    length = strlen(text);
    
    // Creating a 2D array to simulate the rail matrix
    char rail[rails][length];
    
    // Initializing the rail matrix with blank spaces
    for (int i = 0; i < rails; i++) {
        for (int j = 0; j < length; j++) {
            rail[i][j] = ' ';
        }
    }
    row = 0;
    direction = 1;  // 1 means moving down, -1 means moving up

    // Placing the characters of the message into the rail matrix
    for (int i = 0; i < length; i++) {
        rail[row][i] = text[i];
        
        // If we are at the top or bottom rail, reverse the direction
        if (row == 0) {
            direction = 1;
        } else if (row == rails - 1) {
            direction = -1;
        }
        
        // Move to the next row
        row += direction;
    }

    // Printing the cipher text from the rail matrix row by row
    printf("-------------Encryption-----------\n");
    printf("Cipher text: ");
    for (int i = 0; i < rails; i++) {
        for (int j = 0; j < length; j++) {
            if (rail[i][j] != ' ') {
                printf("%c", rail[i][j]);
                ciphertext[k]=rail[i][j];
                k++;
            }
        }
    }
    printf("\n");
    ciphertext[k]='\0';

    //Decryption:
    for (int i = 0; i < rails; i++) {
        for (int j = 0; j < length; j++) {
            rail[i][j] = ' ';
        }
    }

    // Mark the positions where characters will be placed
    row = 0;
    direction = 1;
    for (int i = 0; i < length; i++) {
        rail[row][i] = '*'; // Mark the position
        if (row == 0) direction = 1;
        else if (row == rails - 1) direction = -1;
        row += direction;
    }

    // Place the characters from the cipher text into the rail matrix
    k = 0;
    for (int i = 0; i < rails; i++) {
        for (int j = 0; j < length; j++) {
            if (rail[i][j] == '*') {
                rail[i][j] = ciphertext[k++];
            }
        }
    }

    // Read the matrix in zigzag pattern to get the decrypted message
    row = 0;
    direction = 1;
    k = 0;
    for (int i = 0; i < length; i++) {
        decryptedtext[k++] = rail[row][i];
        if (row == 0) direction = 1;
        else if (row == rails - 1) direction = -1;
        row += direction;
    }
    decryptedtext[k] = '\0';  // Null-terminate the decrypted string
    printf("-------------Decryption-----------\n");
    printf("Decrypted message: %s\n", decryptedtext);
    return 0;
}
