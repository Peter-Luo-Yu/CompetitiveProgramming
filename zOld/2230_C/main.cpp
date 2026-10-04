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

    int t; cin >> t;
    while (t--) {
        ll n; cin >> n;
        vector<ll> arr (n);
        for (int i = 0; i < n; i++) cin >> arr[i];

        ll ones = 0;
        vector<ll> freq;

        for (int i = 0; i < n; i++) {
            if (arr[i] == 1) ones++;
            else freq.push_back(arr[i]);
        }

        //cout << "ones: " << ones << endl;
        //print(freq);
        
        ll ans = 0;
        if (freq.size() == 1) {
            ll slots = freq[0] / 2;
            ans = freq[0] + min(slots, ones);
        }
        else {
            ll slots = 0;
            for (int i = 0; i < freq.size(); i++) {
                slots += ((freq[i] / 2) - 1);
                ans += freq[i];
            }

            ans += min(slots, ones);
        }

        if (ans >= 3) {
            cout << ans << endl;
        } else {
            cout << 0 << endl;
        }

        //space;

    }


    return 0;
}
