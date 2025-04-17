#include <stdio.h>
#include <stdlib.h>
#include <math.h> // For fabs()

int main() {
    int j, count = 0, limit, i = 0, head, tail;
    float y, answer, h = 2.5;
    float theoretical_prob = 0.25; // Theoretical P(y < 2.5) for uniform(0, 10)

    printf("Enter the limit amount: ");
    scanf("%d", &limit);

    while (i < limit) {
        i++;
        head = 0;
        tail = 0;
        for (j = 0; j < 11; j++) {
            y = ((float)rand() / RAND_MAX) * 10; // Generate y between 0 and 10
            printf("%f\n", y);
            if (y < h) {
                head++;
            } else {
                tail++;
            }
        }
        if ((head == 3) || (head == 6) || (head == 9)) {
            count++;
        }
    }

    answer = (float)count / limit;
    float error_percentage = fabs(answer - theoretical_prob) / theoretical_prob * 100;

    printf("The limit is %d\n", limit);
    printf("The experimental probability is = %f\n", answer);
    printf("The theoretical probability is = %f\n", theoretical_prob);
    printf("The error percentage is = %.2f%%\n", error_percentage);

    return 0;
}
