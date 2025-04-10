// 3. Apply all  LCM(Additive, Mixed or Multiplicative ) based on the input values of a and c determine the type and generate 
//    the random numbers based on that. In this case you can provide a choice to user which method they want to chose. Based on the choice you should apply the respective formules
#include<stdio.h>

int main() {
    int choice, a, c, m, r[100], i = 0;

    printf("Choose the method:\n");
    printf("1. Additive\n");
    printf("2. Multiplicative\n");
    printf("3. Mixed\n");
    printf("Enter your choice (1/2/3): ");
    scanf("%d", &choice);

    printf("Enter R0: ");
    scanf("%d", &r[0]);

    printf("Enter value of m: ");
    scanf("%d", &m);

    if (choice == 1) {
        a = 1;
        printf("Enter value of c: ");
        scanf("%d", &c);
    } else if (choice == 2) {
        c = 0;
        printf("Enter value of a: ");
        scanf("%d", &a);
    } else if (choice == 3) {
        printf("Enter value of a: ");
        scanf("%d", &a);
        printf("Enter value of c: ");
        scanf("%d", &c);
    } else {
        printf("Invalid choice.\n");
        return 1;
    }

    do {
        r[i+1] = (r[i] * a + c) % m;
        i++;
    } while (r[i] != r[0] && i < 100);

    printf("Generated Random Numbers:\n{ ");
    for (int j = 0; j <= i; j++) {
        printf("%d ", r[j]);
    }
    printf("}\n");

    printf("Cycle length: %d\n", i);

    return 0;
}