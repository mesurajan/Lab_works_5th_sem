//2. Write an iterative function to generate Fibonacci sequences up to the nth term. 
#include <iostream>
using namespace std;
void fibonacci(int n){
   int a = 0, b = 1, next;
    cout << "Fibonacci Sequence: ";
    for (int i = 0; i < n; i++) {
        cout << a << " ";
        next = a + b;
        a = b;
        b = next;
    }
    cout << endl;
}
int main() {
    int n;
    cout << "Enter number of terms: ";
    cin >> n;
    fibonacci(n);
    return 0;
}