// Job Sequencing with Deadlines (Greedy)  
// Based on the greedy approach described in GeeksforGeeks :contentReference[oaicite:0]{index=0}

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

struct Job {
    string id;     // supports multi-character IDs like "J1"
    int deadline;
    int profit;
};

// Sort jobs by descending profit
bool cmp(const Job &a, const Job &b) {
    return a.profit > b.profit;
}

void jobSequencing(vector<Job> &jobs) {
    int n = jobs.size();
    // Find maximum deadline to size our slots
    int maxd = 0;
    for (int i = 0; i < n; i++)
        if (jobs[i].deadline > maxd)
            maxd = jobs[i].deadline;

    vector<bool> slot(maxd + 1, false);      // slot[i] = true if time i is occupied
    vector<string> result(maxd + 1, "-");    // result[i] = Job ID scheduled at time i
    int totalProfit = 0;

    // 1. Sort jobs by profit
    sort(jobs.begin(), jobs.end(), cmp);

    // 2. Greedily assign each job to the latest free slot ≤ its deadline
    for (int i = 0; i < n; i++) {
        for (int t = min(maxd, jobs[i].deadline); t > 0; t--) {
            if (!slot[t]) {
                slot[t] = true;
                result[t] = jobs[i].id;
                totalProfit += jobs[i].profit;
                break;
            }
        }
    }

    // 3. Output the scheduled sequence and total profit
    cout << "Scheduled sequence:\n";
    for (int t = 1; t <= maxd; t++) {
        if (result[t] != "-")
            cout << result[t] << " ";
    }
    cout << "\nTotal Profit = " << totalProfit << endl;
}

int main() {
    int n;
    cout << "Enter number of jobs: ";
    cin >> n;
    vector<Job> jobs(n);

    cout << "Enter JobID (string), Deadline (int), Profit (int):\n";
    for (int i = 0; i < n; i++) {
        cin >> jobs[i].id >> jobs[i].deadline >> jobs[i].profit;
    }

    jobSequencing(jobs);
    return 0;
}
