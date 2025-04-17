#include <iostream>
#include <vector>
using namespace std;

int matrixChainOrder(const vector<int>& p) {
    int n = p.size() - 1;
    // m[i][j] = min cost to multiply A_i...A_j
    vector<vector<long long>> m(n+1, vector<long long>(n+1, 0));

    // l = chain length
    for (int l = 2; l <= n; ++l) {
        for (int i = 1; i <= n - l + 1; ++i) {
            int j = i + l - 1;
            m[i][j] = LLONG_MAX;
            for (int k = i; k < j; ++k) {
                long long cost = m[i][k] + m[k+1][j]
                    + (long long)p[i-1] * p[k] * p[j];
                if (cost < m[i][j])
                    m[i][j] = cost;
            }
        }
    }
    return m[1][n];
}

int main() {
    int n;
    cout << "Enter number of matrices: ";
    cin >> n;
    vector<int> dims(n + 1);
    cout << "Enter dimensions p0 through p" << n << ":\n";
    for (int i = 0; i <= n; ++i)
        cin >> dims[i];

    long long minCost = matrixChainOrder(dims);
    cout << "Minimum number of multiplications = " << minCost << endl;
    return 0;
}
