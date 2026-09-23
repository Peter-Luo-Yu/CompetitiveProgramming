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

    int N = 1e5 + 5;

    vector<int> phi (N);

    for (int i = 0; i < N; i++) {
        phi[i] = i;
    }
    for (int i = 2; i < N; i++) {
        if (phi[i] == i) {
            for (int j = i; j < N; j += i) {
                phi[j] -= phi[j] / i;
            }
        }
    }

    //print(phi);

    vector<ll> prefix (N + 1);

    for (int i = 1; i < N; i++) {
        prefix[i] = prefix[i - 1] + (i - phi[i]); 
    }

    //print(prefix);

    int t; cin >> t;
    for (int i = 1; i <= t; i++) {
        int n; cin >> n;

        cout << "Case " << i << ": " << prefix[n] << endl;
    }


    return 0;
}
