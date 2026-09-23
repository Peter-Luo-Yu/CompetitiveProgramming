#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define endl "\n"
#define print(arr) for (auto x : arr) cout << x << ' '; cout << '\n';

int main() {

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int t; cin >> t;
    while (t--) {
        int n, k; cin >> n >> k;

        map<int, int> freq;
        for (int i = 0; i < n; ++i) {
            int val; cin >> val;
            freq[val]++;
        }

        vector<pair<int, int>> arr(freq.begin(), freq.end()); // (value, count)

        int l = 0, r = 0, total = 0, max_cards = 0;

        while (r < arr.size()) {
            if (l == r || arr[r].first == arr[r - 1].first + 1) {
                total += arr[r].second;

                if (r - l + 1 > k) {
                    total -= arr[l].second;
                    l++;
                }

                max_cards = max(max_cards, total);
                r++;
            } else {
                total = 0;
                l = r;
            }
        }

        cout << max_cards << '\n';
    }

    return 0;
}