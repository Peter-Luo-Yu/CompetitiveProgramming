#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define endl "\n"
#define print(arr) for (auto x : arr) cout << x << " "; cout << "\n";
#define print2d(arr) for (int i = 0; i < arr.size(); i++) {for (int j = 0; j < arr[i].size(); j++) {cout << arr[i][j] << " ";} cout << "\n";}
#define printG(adj) for (int i = 0; i < adj.size(); i++) {cout << "i: " << i << " | "; for (int j = 0; j < adj[i].size(); j++) {cout << adj[i][j] << " ";} cout << endl;}
#define printP(arr) for (auto x : arr) {cout << x.first << " " << x.second << "\n";}
#define space cout << "---------" << endl;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n; cin >> n; // n is always even
    vector<int> arr (n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    // for k <= n, k even:
    // william at most has k/2 out of first k integers.
    // means robot has at least k/2 of the first k integers.

    // w r w r 
    // r r w w
    // illegal: w w r r

    // if robot has k/2 out of the first k integers, 
    // we just sack the smallest number out of the current pool of numbers for k (even)
    // how to find the smallest number efficiently => priority queue

    priority_queue<int, vector<int>, greater<int>> pq;

    for (int i = 0; i < n; i++) {
        pq.push(arr[i]);

        if (i % 2 == 1) {
            pq.pop();
        }
    }

    ll ans = 0;
    while (!pq.empty()) {
        ans += pq.top();
        pq.pop();
    }

    cout << ans << endl;

    return 0;
}
