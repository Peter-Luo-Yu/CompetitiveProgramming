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
        int n; cin >> n;
        vector<int> a(n), arr(2*n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        vector<int> temp = a;
        sort (temp.begin(), temp.end());
        int big = temp[temp.size() - 2];
        for (int i = 0; i < n; i++) {
            if (a[i] > big) {
                a[i] = big;
            }
        }

        for (int i = 0; i < n; i++) {
            arr[i] = a[i];
            arr[i + n] = a[i];
        }
        
        //print(arr); space;

        for (int i = 0; i < n; i++) {
            vector<int> b (n);
            for (int j = 0; j < n; j++) {
                b[j] = arr[i + j];
            }
            
            //print(b);


            int idx1, idx2;

            for (int j = 0; j < n; j++) {
                if (b[j] == big) {
                    idx1 = j; break;
                }
            }
            for (int j = n - 1; j >= 0; j--) {
                if (b[j] == big) {
                    idx2 = j; break;
                }
            }

            //cout << idx1 << " " << idx2 << endl;

            vector<int> prefMax(n), sufMax(n);

            for (int i = 0; i < n; i++) {
                if (i - 1 >= 0) {
                    prefMax[i] = max (prefMax[i - 1], b[i]);
                } else {
                    prefMax[i] = b[i];
                }
            }

            for (int i = n - 1; i >= 0; i--) {
                if (i < n - 1) {
                    sufMax[i] = max (sufMax[i + 1], b[i]);
                } else {
                    sufMax[i] = b[i];
                }
            }

            //print(prefMax); print(sufMax);

            ll ans = 0;

            for (int i = 0; i < idx2; i++) {
                ans += prefMax[i];
            }
            for (int i = idx2 + 1; i < n; i++) {
                ans += sufMax[i];
            }

            cout << ans << " ";


            //space;
        }
        cout << endl;

        
    }


    return 0;
}
