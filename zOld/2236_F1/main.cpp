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

    int N = 5 * 1e5 + 5;
    vector<int> div(N);
    for (int i = 0; i < N; i++) div[i] = i;
    for (int i = 2; i < N; i++) {
        for (int j = 2 * i; j < N; j += i) {
            if (div[j] == j) {
                div[j] = i;
            }
        }
    }
    //print(div);


    int t; cin >> t;
    while (t--) {
        int n, x; cin >> n >> x;
        vector<int> arr (n);
        for (int i = 0; i < n; i++) cin >> arr[i];

        map<int, int> cnt; // prime - cnt;

        for (int i = 0; i < n; i++) {
            int val = arr[i];
            
            while (val > 1) {
                int prime = div[val];
                int exp = 0;
                while (val % prime == 0) {
                    val /= prime;
                    exp++;
                }
                cnt[prime] += exp; 
            }
        }

        //printP(cnt);

        ll ans = 1;
        ll MOD = 1e9 + 7;
        for (auto x : cnt) {
            ans = (ans * (x.second + 1)) % MOD;
        }

        cout << ans << endl;

        //space;
    }


    return 0;
}
