//2. Write a C program to find Euler Totient function value of any number.

#include <stdio.h>

int gcd(int n1, int n2) {
    int q, r1, r2, r;
    r1 = n1;
    r2 = n2;
    while (r2 > 0) {
        q = r1 / r2;
        r = r1 % r2;
        r1 = r2;
        r2 = r;
    }
    return r1;
}

int main() {
    int num, count, i;

    printf("Enter value of num to find totient function: ");
    scanf("%d", &num);

    count = 0;
    for (i = 1; i < num; i++) {
        if (gcd(num, i) == 1) {
            count++;
        }
    }

    printf("\nTotient value of %d = %d\n", num, count);

    return 0;
}