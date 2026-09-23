#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define endl "\n"
#define print(arr) for (auto x : arr) cout << x << " "; cout << "\n";
#define print2d(arr) for (int i = 0; i < arr.size(); i++) {for (int j = 0; j < arr[i].size(); j++) {cout << arr[i][j] << " ";} cout << "\n";}
#define printG(adj) for (int i = 0; i < adj.size(); i++) {cout << "i: " << i << " | "; for (int j = 0; j < adj[i].size(); j++) {cout << adj[i][j] << " ";} cout << endl;}
#define printP(arr) for (auto x : arr) {cout << x.first << " " << x.second << "\n";}
#define space cout << "----------" << endl;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int t; cin >> t;

    while (t--) {
        ll n, x, k; cin >> n >> x >> k;

        string s; cin >> s;

        ll idx = 0; ll t1 = 0;

        bool hitzero = false;

        for (int i = 0; i < n; i++) {
            if (x == 0) {
                hitzero = true;
                break;
            }
            if (s[i] == 'L') {
                x--;
            } else {
                x++;
            }
            idx++; t1++;
        }
        if (x == 0) {
            hitzero = true;
        }

        //cout << "idx: " << idx << " hitzero: " << hitzero << endl;

        if (!hitzero) {
            cout << 0 << endl;
            //space;
            continue;
        }
        
        ll t = 0; hitzero = false;
        idx = 0;
        for (int i = 0; i < n; i++) {
            if (s[idx % s.size()] == 'L') {
                x--;
            } else {
                x++;
            }
            idx++; t++;

            if (x == 0) {
                hitzero = true;
                break;
            }
        }
        if (x == 0) {
            hitzero = true;
        }

        //cout << "time: " << t << " hitzero: " << hitzero << endl;

        if (!hitzero) {
            cout << 1 << endl;
        } else {
            ll ans = (k - t1)/t + 1;
            cout << ans << endl;
        }



        //space;
    }

    
    return 0;
}
