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

    int n, k; cin >> n >> k;

    // n jury scores, k polycarp scores

    vector<ll> jury(n), guess(k);
    
    for (int i = 0; i < n; i++) cin >> jury[i];
    for (int i = 0; i < n; i++) cin >> guess[i];
    

    vector<ll> prefix (n + 1);
    for (int i = 0; i < n; i++) {
        prefix[i + 1] = prefix[i] + jury[i];
    }

    //print(prefix);

    set<ll> candidates;
    for (int i = 0; i <= n; i++) {
        candidates.insert(guess[0] - prefix[i]);
    }

    ll ans = 0;

    for (int s : candidates) {
        //cout << s << endl;

        set<ll> hit;

        ll cur = s;
        for (int i = 0; i < n; i++) {
            cur += jury[i];
            hit.insert(cur);
            //cout << "cur: " << cur << endl;
        }

        bool valid = true;
        for (int i = 0; i < guess.size(); i++) {
            if (!hit.count(guess[i])) {
                valid = false;
            }
        }

        if (valid) {
            ans++;
        }

    }

    cout << ans << endl;

    return 0;
}
