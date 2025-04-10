//2. Finding the cycle length modify the above program (1) and find the cycle length.
// Once you identify there is present of same random number as given in seed, you have to terminate the program.
#include<stdio.h>
int main() {
    int a, c, m, r[100], i = 0,n;
    printf("Enter how manu numbers(iteration):");
    scanf("%d",&n);

    printf("Enter R0: ");
    scanf("%d", &r[0]);

    printf("Enter value of a: ");
    scanf("%d", &a);

    printf("Enter value of c: ");
    scanf("%d", &c);

    printf("Enter value of m: ");
    scanf("%d", &m);

    do {
        r[i+1] = (r[i] * a + c) % m;
        i++;
    } while (r[i] != r[0] && i < 100);

    printf("Answer:\n{ ");
    for (int j = 0; j <= i; j++) {
        printf("%d ", r[j]);
    }
    printf("}\n");

    printf("Cycle length: %d\n", i);

    return 0;
}