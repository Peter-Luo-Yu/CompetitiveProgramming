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

    int n; cin >> n;
    vector<int> arr (n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    
    int N = 2 * 1e5 + 5;
    vector<int> spf (N);
    for (int i = 0; i < N; i++) {
        spf[i] = i;
    }
    for (int i = 2; i < N; i++) {
        if (spf[i] == i) {
            for (int j = i; j < N; j += i) {
                if (spf[j] == j) {
                    spf[j] = i;
                }
            }
        }
    }

    //print(spf);

    map<int, vector<int>> mp;

    for (int i = 0; i < n; i++) {
        int val = arr[i];

        while (val > 1) {
            int factor = spf[val];
            int exp = 0;

            while (val % factor == 0) {
                val /= factor;
                exp++;
            }

            mp[factor].push_back(exp);
        }
    }

    ll ans = 1;
    for (auto x : mp) {
        //cout << x.first << " | ";
        
        sort (x.second.begin(), x.second.end());
        
        //print(x.second);

        int exp = 0;
        if (x.second.size() == n) {
            exp = x.second[1];
        }
        else if (x.second.size() == n - 1) {
            exp = x.second[0];
        }
        else {
            exp = 0;
        }

        for (int i = 0; i < exp; i++) {
            ans *= x.first;
        }
    }

    cout << ans << endl;


    return 0;
}
