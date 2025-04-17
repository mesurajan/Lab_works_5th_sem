//election process
//A population of vector are distribbuted between the democratic(D), Republican(R) and independent(I) parties
//each election the voting population p=[D,R,I] obeys the distribution
//in 2004 election, the voters were distributed according to the distribution vector
//p0=[0.48,0.51,0.1]
/*
Q:the next ecpected population outcome od the 2008 ekection??
A: p0*T2 -0.70*0.48+0.10*0.51+0.30*0.10=0.390
*/

#include <stdio.h>

// Multiply row vector p[3] by 3x3 matrix T to get new vector result[3]
void multiplyVectorMatrix(double p[3], double T[3][3], double result[3]) {
    for (int i = 0; i < 3; i++) {
        result[i] = 0;
        for (int j = 0; j < 3; j++) {
            result[i] += p[j] * T[j][i];  // Note: row vector * matrix
        }
    }
}

int main() {
    // Initial distribution in 2004: [D, R, I]
    double p0[3] = {0.48, 0.51, 0.10};

    // Transition matrix T (example - update with actual values if given)
    double T[3][3] = {
        {0.70, 0.20, 0.10},  // From Democrat to [D, R, I]
        {0.10, 0.80, 0.10},  // From Republican to [D, R, I]
        {0.30, 0.30, 0.40}   // From Independent to [D, R, I]
    };

    double p1[3];  // Resulting distribution in 2008

    multiplyVectorMatrix(p0, T, p1);

    printf("Expected voter distribution in 2008:\n");
    printf("Democrat:   %.3f\n", p1[0]);
    printf("Republican: %.3f\n", p1[1]);
    printf("Independent: %.3f\n", p1[2]);

    return 0;
}