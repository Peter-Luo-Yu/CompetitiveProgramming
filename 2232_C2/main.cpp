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
        ll n, x, s;
        cin >> n >> x >> s; // x = tables, s = seats;

        string str; cin >> str;
        
        // want to track l (min tables) for the introverts, and r (max tables) for the extroverts
        ll l = 0, r = 0, ans = 0;

        for (int i = 0; i < n; i++) {
            // must increase min tables
            if (str[i] == 'I') {

                if (l < x) {
                    l++; 
                    r = min(x, r + 1);
                    ans++;
                }
            }
            // 
            else if (str[i] == 'E') {
                if (ans < r * s) {
                    ans++;

                    if (ans > l * s) {
                        l++;
                    }
                } 

            } else {
                if (ans < x * s) {
                    ans++;

                    if (ans > l * s) l++;
                    r = min(x, r + 1);
                }
            }
        }

        cout << ans << endl;

    }


    return 0;
}
