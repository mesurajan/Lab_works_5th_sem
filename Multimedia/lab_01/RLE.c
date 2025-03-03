#include <stdio.h>
#include <string.h>

void runLengthEncode(char *str) {
    int n = strlen(str);
    for (int i = 0; i < n; i++) {
        int count = 1;
        while (i < n - 1 && str[i] == str[i + 1]) {
            count++;
            i++;
        }
        printf("%c@%d", str[i], count);
    }
    printf("\n");
}

int main() {
    char str[100];  // Assuming a maximum input length of 100 characters

    printf("Enter a string: ");
    scanf("%99s", str); // Reads input, limiting to 99 characters to prevent buffer overflow

    printf("Original String: %s\n", str);
    printf("RLE Compressed Output: ");
    runLengthEncode(str);

    return 0;
}
