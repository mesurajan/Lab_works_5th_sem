#include <iostream>
using namespace std;

// Lomuto partition scheme
int partition(int arr[], int left, int right) {
    int pivot = arr[right];
    int i = left;
    for (int j = left; j < right; j++) {
        if (arr[j] < pivot) {
            swap(arr[i], arr[j]);
            i++;
        }
    }
    swap(arr[i], arr[right]);
    return i;
}

// Quick-Select to find k-th smallest (k is 1-based)
int quickSelect(int arr[], int left, int right, int k) {
    if (left == right) return arr[left];
    int pivotIndex = partition(arr, left, right);
    int count = pivotIndex - left + 1;  // number of elements ≤ pivot
    if (count == k) 
        return arr[pivotIndex];
    else if (k < count) 
        return quickSelect(arr, left, pivotIndex - 1, k);
    else 
        return quickSelect(arr, pivotIndex + 1, right, k - count);
}

int main() {
    int n, k;
    cout << "Enter number of elements: ";
    cin >> n;
    int arr[n];
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) cin >> arr[i];

    cout << "Enter k (1 ≤ k ≤ " << n << "): ";
    cin >> k;
    int result = quickSelect(arr, 0, n - 1, k);
    cout << k << "-th smallest element is: " << result << endl;
    return 0;
}
