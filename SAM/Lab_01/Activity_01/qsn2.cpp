#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

#define PI 3.14159265358979323846

double monte_carlo_pi(int iterations) {
    int inside_circle = 0;
    for (int i = 0; i < iterations; i++) {
        double x = (double)rand() / RAND_MAX;
        double y = (double)rand() / RAND_MAX;
        if (x*x + y*y <= 1.0) {
            inside_circle++;
        }
    }
    return 4.0 * inside_circle / iterations;
}

int main() {
    srand(time(NULL));

    int n;
    printf("Enter the number of different iteration values you want to try: ");
    scanf("%d", &n);

    int iterations[n];

    for (int i = 0; i < n; i++) {
        printf("Enter iteration value %d: ", i + 1);
        scanf("%d", &iterations[i]);
    }

    printf("\nS.N\tIterations\tEstimated Pi\tActual Pi\t%% Error\n");
    printf("---------------------------------------------------------------\n");

    for (int i = 0; i < n; i++) {
        double estimated_pi = monte_carlo_pi(iterations[i]);
        double error_percentage = fabs((estimated_pi - PI) / PI) * 100;

        printf("%d\t%d\t\t%.6f\t%.6f\t%.4f%%\n", 
               i + 1, iterations[i], estimated_pi, PI, error_percentage);
    }

    return 0;
}
