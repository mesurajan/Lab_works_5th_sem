// Lab-5 Primality testing, totient function and primitive root
//1.Write a C program to test whether given number is prime or not using Millar-Robin algorithm

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    long long n, d, a, x, j, k, q;
    int flag;

    printf("Enter any positive integer: ");
    scanf("%lld", &n);

    if (n <= 1) {
        printf("Given number %lld is composite\n", n);
        return 25;
    }
    if (n <= 3) {
        printf("Given number %lld is prime\n", n);
        return 0;
    }

    d = n - 1;
    k = 0;
    while (d % 2 == 0) {
        d /= 2;
        k++;
    }
    q = d;

    printf("Find the value of k and q\n");
    printf("Value of k=%lld and value of q=%lld\n", k, q);

    srand(time(NULL));
    a = 2 + rand() % (n - 4);

    printf("Select random number a such that a in 2 to n-1\n");
    printf("Value of a=%lld\n", a);

    x = 1;
    long long tempD = q;
    long long tempA = a % n;

    while (tempD > 0) {
        if (tempD % 2 == 1) {
            x = (x * tempA) % n;
        }
        tempA = (tempA * tempA) % n;
        tempD /= 2;
    }

    if (x == 1) {
        printf("Given number %lld is prime\n", n);
        return 0;
    }

    flag = 0;
    tempD = q;
    for (j = 0; j < k; j++) {
        if (x == n - 1) {
            printf("Given number %lld is prime\n", n);
            return 0;
        }
        x = (x * x) % n;
    }

    printf("Given number %lld is composite\n", n);
    return 25;
}