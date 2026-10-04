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
        int n, k; cin >> n >> k;

        vector<ll> arr (n);
        for (int i = 0; i < n; i++) cin >> arr[i];

        
        ll ans = -1;
        if (k == 1) { // last can only be at the end of the arr -> 2 cases
            ll ans1 = arr[0];

            ll Max = -1;
            for (int i = 1; i < arr.size(); i++) {
                Max = max (Max, arr[i]);
            }
            ans1 += Max;

            ll ans2 = arr[arr.size() - 1];
            Max = -1;
            for (int i = 0; i < arr.size() - 1; i++) {
                Max = max (Max, arr[i]);
            }
            ans2 += Max;

            ans = max (ans1, ans2);
        }
        else { // do complete search for each possible pos of last

            for (int i = 0; i < arr.size(); i++) {
                ll cur = 0;
                vector<ll> temp, temp2;

                if (i == 0) {
                    cur += arr[0];

                    for (int j = 1; j < arr.size(); j++) {
                        temp.push_back(arr[j]);
                    }
                    sort (temp.begin(), temp.end());
                    reverse(temp.begin(), temp.end());
                    for (int j = 0; j < k; j++) {
                        cur += temp[j];
                    }
                    ans = max (ans, cur);
                } 
                else if (i == arr.size() - 1) {
                    cur += arr[arr.size() - 1];

                    for (int j = 0; j < arr.size() - 1; j++) {
                        temp.push_back(arr[j]);
                    }
                    sort (temp.begin(), temp.end());
                    reverse(temp.begin(), temp.end());
                    for (int j = 0; j < k; j++) {
                        cur += temp[j];
                    }
                    ans = max (ans, cur);
                } 
                else {
                    //cout << "on: " << arr[i] << endl;

                    cur += arr[i];

                    ll Max = -1;
                    ll idx1, idx2;

                    for (int j = 0; j < i; j++) {
                        if (arr[j] > Max) {
                            Max = arr[j];
                            idx1 = j;
                        }
                    }
                    cur += Max;

                    Max = -1;
                    for (int j = i + 1; j < arr.size(); j++) {
                        if (arr[j] > Max) {
                            Max = arr[j];
                            idx2 = j;
                        }
                    }
                    cur += Max;

                    //cout << "idx1: " << idx1 << " idx2: " << idx2 << " cur: " << cur << endl;

                    for (int j = 0; j < arr.size(); j++) {
                        if (j == i || j == idx1 || j == idx2) continue;
                        
                        temp.push_back(arr[j]);
                    }

                    sort (temp.begin(), temp.end());
                    reverse (temp.begin(), temp.end());

                    for (int j = 0; j < k - 2; j++) {
                        cur += temp[j];
                    }

                    ans = max (ans, cur);
                }
            }
        }

        cout << ans << endl;
    }


    return 0;
}
