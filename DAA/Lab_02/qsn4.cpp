//4. Write a program to Implement Sequential Search.
#include <iostream>
using namespace std;
int sequentialSearch(int arr[], int n, int key) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == key) return i;
    }
    return -1;
}
int main() {
    int n, key;
    cout << "Enter number of elements: ";
    cin >> n;
    int arr[n];
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) cin >> arr[i];
    cout << "Enter key to search: ";
    cin >> key;
    int index = sequentialSearch(arr, n, key);
    if (index != -1) cout << "Element found at index " << index << endl;
    else cout << "Element not found" << endl;
    return 0;
}