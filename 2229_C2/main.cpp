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

    ll t; cin >> t;
    while (t--) {
        ll n; cin >> n;
        vector<ll> arr (n), pref (n + 1);

        for (int i = 0; i < n; i++) cin >> arr[i];
        for (int i = 0; i < n; i++) {
            if (arr[i] < 0) {
                pref[i + 1] = pref[i] + abs(arr[i]);
            } else {
                pref[i + 1] = pref[i];
            }
        }

        ll best = -1;
        ll bestidx = -1;
        for (int i = 0; i < n; i++) {
            if (arr[i] > 0) {
                if (pref[i] - arr[i] > 0 && pref[i] - arr[i] > best) {
                    best = pref[i] - arr[i];
                    bestidx = i;
                }
            }
        }


        //print(arr); print(pref);
        //cout << "idx: " << bestidx << endl;


        if (bestidx == -1) {
            cout << 0 << endl; cout << endl; 
            //space;
            continue;
        }


        ll numflip = 0;
        vector<ll> ans;
        for (int i = bestidx - 1; i >= 0; i--) {
            if (numflip % 2 == 0) {
                if (arr[i] > 0) {
                    numflip++;
                    ans.push_back(i + 1);
                }
            } else {
                if (arr[i] < 0) {
                    numflip++;
                    ans.push_back(i + 1);
                }
            }
        }

        cout << numflip + 1 << endl;

        ans.push_back(bestidx + 1);
        print(ans);

        //space;
    }
    


    return 0;
}
