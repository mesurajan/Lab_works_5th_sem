//calculate the value of pi using monte carlo method
#include<stdio.h>
#include<math.h>
#include<conio.h>

#define SEED 35791246
#define PI 3.14159265358979323846

main()
{
    int N=0;
    double x,y;
    int i ,n=0;
    double z;
    double pi;
    double error_percentage;
    printf("Enter the number of iterations used to estimate pi: ");
    scanf("%d",&N);
    srand(SEED);
    n=0;

    for(i=0;i<N;i++)
    {
        x = (double) rand() / RAND_MAX;
        y = (double) rand() / RAND_MAX;
        z=x*x+y*y;
        if (z<=1) 
            n++;
    }
    pi = (double) n / N * 4;
    error_percentage = fabs((pi - PI) / PI) * 100;
    printf("# of trials = %d, estimate of pi is %g\n", N, pi);
    printf("Error percentage: %.2f%%\n", error_percentage);

    getch();
}