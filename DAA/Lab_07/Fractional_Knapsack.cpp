#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Item {
    int weight;
    int profit;
    double ratio;
};

// Comparator to sort by ratio descending
bool cmp(const Item &a, const Item &b) {
    return a.ratio > b.ratio;
}

double fractionalKnapsack(int W, vector<Item> &items) {
    sort(items.begin(), items.end(), cmp);
    double totalProfit = 0.0;
    int remaining = W;

    for (auto &it : items) {
        if (it.weight <= remaining) {
            remaining -= it.weight;
            totalProfit += it.profit;
        } else {
            totalProfit += it.ratio * remaining;
            break;
        }
    }
    return totalProfit;
}

int main() {
    int n, W;
    cout << "Enter number of items: ";
    cin >> n;
    vector<Item> items(n);
    cout << "Enter weight and profit of each item:\n";
    for (int i = 0; i < n; i++) {
        cin >> items[i].weight >> items[i].profit;
        items[i].ratio = (double)items[i].profit / items[i].weight;
    }
    cout << "Enter knapsack capacity: ";
    cin >> W;

    double maxProfit = fractionalKnapsack(W, items);
    cout << "Maximum profit = " << maxProfit << endl;
    return 0;
}
