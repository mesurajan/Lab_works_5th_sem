//Lab-4 Implementation of testing of uniformity of random numbers using chi-square test.
/*
Algorithm:
    1. Fix the number of intervals 'n' of equal length in [0,1]
    2. Compute E = N/n, where E is expected number in each interval, N is total sample size
    3. Compute the observed Oi in the interval for i=1,2,...
    4. Compute chi-square = SUM((Oi-Ei)^2)/Ei for i = 1 to n
    Where Oi is the observed number in the ith class.
          Ei is the expected number in the ith class
          n is the number of classes
    5. Determine the critical value Chi-square(t) from the chi-square table for the specified alpha and n-1 degree of freedom 
    6. If chi+squate > chi-square table the nnumbers are uniformily distributed else not.
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <conio.h>

#define SEED 35791246

int main()
{
    int N, n;  // N = total sample size, n = number of intervals
    printf("Enter total number of random numbers (sample size): ");
    scanf("%d", &N);

    printf("Enter the number of intervals: ");
    scanf("%d", &n);

    double expected = (double)N / n; // Expected frequency in each interval
    int* observed = (int*)calloc(n, sizeof(int)); // Array to store observed frequency
    double rand_num;

    srand(SEED); // Set seed for random number generator

    // Generate N random numbers and count their occurrences in intervals
    for (int i = 0; i < N; i++)
    {
        rand_num = (double)rand() / RAND_MAX;  // Random number in [0,1)
        int index = (int)(rand_num * n);       // Find the interval index
        if (index == n) index = n - 1;         // Ensure within bounds
        observed[index]++;
    }

    // Calculate Chi-square statistic
    double chi_square = 0.0;
    for (int i = 0; i < n; i++)
    {
        double diff = observed[i] - expected;
        chi_square += (diff * diff) / expected;
    }

    // Output results
    printf("\nExpected frequency in each interval: %.2f\n", expected);
    printf("Observed frequencies:\n");
    for (int i = 0; i < n; i++)
    {
        printf("Interval %d: %d\n", i + 1, observed[i]);
    }

    printf("\nChi-square statistic value = %.4f\n", chi_square);

    printf("\nCompare this value with chi-square table value for %d degrees of freedom.\n", n - 1);
    printf("If chi-square statistic > table value => Random numbers are NOT uniformly distributed.\n");
    printf("Else => Random numbers ARE uniformly distributed.\n");

    free(observed);
    getch();
    return 0;
}
