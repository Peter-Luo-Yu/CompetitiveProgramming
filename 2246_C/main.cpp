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

ll MOD = 1e9 + 7;

ll power (ll a, ll b) {
    ll res = 1;
    while (b > 0) {
        if (b & 1) {
            res = (res * a) % MOD;
        }
        a = (a * a) % MOD;
        b >>= 1;
    }
    return res;
}   

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> arr (n);
        map<int, int> freq;
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
            freq[arr[i]]++;
        }
        
        ll neg1poss = power(2, freq[-1] - 1);
        ll posans = 1;

        for (auto f : freq) {
            if (f.first > 0) {
                posans = (posans * power(2, f.second - 1)) % MOD;
            }
        }

        if (freq[-1] == 0) {
            cout << posans << endl; 
            //space;
            continue;
        }

        int adj = 0;
        for (int i = 0; i < n - 1; i++) {
            if (arr[i] > 0 && arr[i] + 1 == arr[i + 1]) {
                adj++;
            }
        }

        //cout << "neg1poss: " << neg1poss << " posans: " << posans << " adj: " << adj << endl;

        ll finalans = ((neg1poss * posans % MOD) + ((neg1poss * adj % MOD) * posans) % MOD) % MOD;

        cout << finalans << endl;
        //space;
    }
    

    return 0;
}
