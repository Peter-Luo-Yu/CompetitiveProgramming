#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Optimized function to check if conditions are satisfied
bool check(vector<int>& height, vector<int>& cond, int n) {
    vector<pair<int, int>> plants(n);  // {height, original index}
    for (int i = 0; i < n; i++) {
        plants[i] = {height[i], i};
    }

    // Sort plants by height
    sort(plants.begin(), plants.end());

    // Compute the number of taller plants for each plant
    vector<int> taller_count(n, 0);
    for (int i = 0; i < n; i++) {
        int idx = plants[i].second;
        taller_count[idx] = n - i - 1;  // Plants taller than current
    }

    // Verify if all conditions are met
    for (int i = 0; i < n; i++) {
        if (taller_count[i] != cond[i]) {
            return false;
        }
    }
    return true;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int t;
    cin >> t;

    for (int a = 0; a < t; a++) {
        int n;
        cin >> n;  // Number of plants

        vector<int> height(n), growth(n), cond(n);

        for (int i = 0; i < n; i++) cin >> height[i];
        for (int i = 0; i < n; i++) cin >> growth[i];
        for (int i = 0; i < n; i++) cin >> cond[i];

        // Simulate plant growth
        int day = 0;
        bool stopped = false;

        // Simulate up to a reasonable maximum number of days
        for (int iteration = 0; iteration <= n * 100; iteration++) {
            if (check(height, cond, n)) {
                stopped = true;
                break;
            }

            // Update heights based on growth rates
            for (int i = 0; i < n; i++) {
                height[i] += growth[i];
            }
            day++;
        }

        if (stopped) {
            cout << day << "\n";
        } else {
            cout << "-1\n";  // Impossible to meet conditions
        }
    }

    return 0;
}