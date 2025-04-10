#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    int i, j, count_inside, num_cases;

    printf("Enter the number of iterations you want to test: ");
    scanf("%d", &num_cases);

    int iterations[num_cases];

    for (i = 0; i < num_cases; i++) {
        printf("Enter iteration count for case %d: ", i + 1);
        scanf("%d", &iterations[i]);
    }

    const float actual_pi = 3.141592653589793;

    printf("\nS.N\tIterations\tEstimated Pi\tActual Pi\t%% Error\n");
    printf("---------------------------------------------------------------\n");

    for (i = 0; i < num_cases; i++) {
        count_inside = 0;

        for (j = 0; j < iterations[i]; j++) {
            float x = (float)rand() / RAND_MAX;
            float y = (float)rand() / RAND_MAX;

            if ((x * x + y * y) <= 1.0f) {
                count_inside++;
            }
        }

        float pi_estimate = 4.0f * count_inside / iterations[i];
        float error = fabs(pi_estimate - actual_pi) / actual_pi * 100;

        printf("%d\t%d\t\t%f\t%f\t%.2f%%\n",
               i + 1, iterations[i], pi_estimate, actual_pi, error);
    }

    return 0;
}
