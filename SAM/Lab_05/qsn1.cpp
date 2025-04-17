//Lab-5 Implementation of markov process
//1. Implementation COKE vs PEPSI example for markov process
/*
    Given that persons last cola purchase was coke, there is 90% chance his next cola purchase will also be coke,
    If a person last cola purchasee was pepsi, there is 80% chance his next cola purchase will also be pepsi,

    t={0.9 0.1
       0.2 0.8}

    1.Given that a person currently a pepsi purchaser, what is the probability that he will purchase coke two purchase from now
        T2= [0.83 0.17
             0.34 0.66]
        
        Answer:0.34
    
    2. Given that a person is currently a coke purchaser, what is the probability that he will purchase pepsi three purchase from now?
        Ans: 0.219

    3. Suppose 60% of all people now drink coke, and 40% drink pepsi, what fraction of people will be drinking coke after three purchase from now?
        P0=[0.6, 0.4]
        Pn = P0*T^n
        P3=P0*t^3
        =(0.6438, 0.3562)
*/

/*
STEPS:
1. Take 2 by 2 matrix say t,
2. Ask for after how many times we need a prob of choice (say N)
3. Multpily the transition matrix upto n times (T^N)
4. Pick the required index to get answer
5. Display the answer

*/


#include <stdio.h>

// Function to multiply two 2x2 matrices
void multiplyMatrix(double a[2][2], double b[2][2], double result[2][2]) {
    double temp[2][2];
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            temp[i][j] = 0;
            for (int k = 0; k < 2; k++) {
                temp[i][j] += a[i][k] * b[k][j];
            }
        }
    }

    // Copy temp to result
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            result[i][j] = temp[i][j];
}

// Function to raise matrix to power n
void matrixPower(double base[2][2], int n, double result[2][2]) {
    // Initialize result as identity matrix
    result[0][0] = 1; result[0][1] = 0;
    result[1][0] = 0; result[1][1] = 1;

    double temp[2][2];
    while (n > 0) {
        if (n % 2 == 1) {
            multiplyMatrix(result, base, temp);
            for (int i = 0; i < 2; i++)
                for (int j = 0; j < 2; j++)
                    result[i][j] = temp[i][j];
        }
        multiplyMatrix(base, base, temp);
        for (int i = 0; i < 2; i++)
            for (int j = 0; j < 2; j++)
                base[i][j] = temp[i][j];
        n /= 2;
    }
}

int main() {
    double t[2][2] = {
        {0.9, 0.1},
        {0.2, 0.8}
    };

    int n;
    printf("Enter number of purchases ahead (N): ");
    scanf("%d", &n);

    double tn[2][2];
    matrixPower(t, n, tn);

    printf("\nTransition matrix after %d steps:\n", n);
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            printf("%.4f\t", tn[i][j]);
        }
        printf("\n");
    }

    // Lab example checks
    if (n == 2) {
        printf("\nExample 1: Starting from Pepsi, probability of Coke after 2 steps = %.3f\n", tn[1][0]);
    }

    if (n == 3) {
        printf("Example 2: Starting from Coke, probability of Pepsi after 3 steps = %.3f\n", tn[0][1]);

        // Example 3: Starting distribution [0.6, 0.4]
        double coke = 0.6 * tn[0][0] + 0.4 * tn[1][0];
        double pepsi = 0.6 * tn[0][1] + 0.4 * tn[1][1];
        printf("Example 3: Distribution after 3 steps:\n");
        printf("Coke: %.4f, Pepsi: %.4f\n", coke, pepsi);
    }

    return 0;
}