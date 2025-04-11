//2. Write a c program to implement play fair cipher.
#include<stdio.h>
#include<string.h>
#include<ctype.h>

char keyMatrix[5][5];

void generateMatrix(char key[]) {
    int i, j, k = 0;
    int alpha[26] = {0};

    for(i = 0; i < strlen(key); i++) {
        if(key[i] == 'j') key[i] = 'i'; // j is treated as i
    }

    for(i = 0; i < strlen(key); i++) {
        if(alpha[key[i]-'a'] == 0) {
            keyMatrix[k/5][k%5] = key[i];
            alpha[key[i]-'a'] = 1;
            k++;
        }
    }

    for(i = 0; i < 26; i++) {
        if(i + 'a' == 'j') continue;
        if(alpha[i] == 0) {
            keyMatrix[k/5][k%5] = i + 'a';
            k++;
        }
    }
}

void displayMatrix() {
    printf("Key Matrix:\n");
    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 5; j++) {
            printf("%c ", keyMatrix[i][j]);
        }
        printf("\n");
    }
}

void search(char a, char b, int pos[]) {
    int i, j;
    for(i = 0; i < 5; i++) {
        for(j = 0; j < 5; j++) {
            if(keyMatrix[i][j] == a) {
                pos[0] = i;
                pos[1] = j;
            }
            if(keyMatrix[i][j] == b) {
                pos[2] = i;
                pos[3] = j;
            }
        }
    }
}

void encrypt(char pt[]) {
    int i, pos[4];
    int len = strlen(pt);

    printf("\nEncrypted Text: ");
    for(i = 0; i < len; i += 2) {
        char a = pt[i];
        char b = (i+1 < len) ? pt[i+1] : 'x';
        if(a == b) b = 'x';

        search(a, b, pos);

        if(pos[0] == pos[2]) {
            printf("%c%c", keyMatrix[pos[0]][(pos[1]+1)%5], keyMatrix[pos[2]][(pos[3]+1)%5]);
        } else if(pos[1] == pos[3]) {
            printf("%c%c", keyMatrix[(pos[0]+1)%5][pos[1]], keyMatrix[(pos[2]+1)%5][pos[3]]);
        } else {
            printf("%c%c", keyMatrix[pos[0]][pos[3]], keyMatrix[pos[2]][pos[1]]);
        }
    }
    printf("\n");
}

void decrypt(char ct[]) {
    int i, pos[4];
    int len = strlen(ct);

    printf("\nDecrypted Text: ");
    for(i = 0; i < len; i += 2) {
        char a = ct[i];
        char b = (i+1 < len) ? ct[i+1] : 'x';

        search(a, b, pos);

        if(pos[0] == pos[2]) {
            printf("%c%c", keyMatrix[pos[0]][(pos[1]+4)%5], keyMatrix[pos[2]][(pos[3]+4)%5]);
        } else if(pos[1] == pos[3]) {
            printf("%c%c", keyMatrix[(pos[0]+4)%5][pos[1]], keyMatrix[(pos[2]+4)%5][pos[3]]);
        } else {
            printf("%c%c", keyMatrix[pos[0]][pos[3]], keyMatrix[pos[2]][pos[1]]);
        }
    }
    printf("\n");
}

int main() {
    char key[50], pt[100], cleanPT[100], ct[100] = "";
    int i, j = 0;

    printf("Playfair Cipher:\n");
    printf("Enter key: ");
    scanf("%s", key);
    printf("Enter plaintext (lowercase only): ");
    scanf("%s", pt);

    // Preprocess plaintext
    for(i = 0; pt[i]; i++) {
        if(pt[i] == 'j') pt[i] = 'i';
        if(isalpha(pt[i])) cleanPT[j++] = pt[i];
    }
    cleanPT[j] = '\0';

    generateMatrix(key);
    displayMatrix();

    printf("\nOriginal Text: %s", cleanPT);

    printf("\n");
    encrypt(cleanPT);

    // Encrypt into ct for reuse in decryption
    j = 0;
    for(i = 0; i < strlen(cleanPT); i += 2) {
        char a = cleanPT[i];
        char b = (i+1 < strlen(cleanPT)) ? cleanPT[i+1] : 'x';
        if(a == b) b = 'x';

        int pos[4];
        search(a, b, pos);

        if(pos[0] == pos[2]) {
            ct[j++] = keyMatrix[pos[0]][(pos[1]+1)%5];
            ct[j++] = keyMatrix[pos[2]][(pos[3]+1)%5];
        } else if(pos[1] == pos[3]) {
            ct[j++] = keyMatrix[(pos[0]+1)%5][pos[1]];
            ct[j++] = keyMatrix[(pos[2]+1)%5][pos[3]];
        } else {
            ct[j++] = keyMatrix[pos[0]][pos[3]];
            ct[j++] = keyMatrix[pos[2]][pos[1]];
        }
    }
    ct[j] = '\0';

    decrypt(ct);

    return 0;
}

