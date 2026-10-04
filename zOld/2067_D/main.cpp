#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

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

        vector<int> x (n); 
        set<int> st;

        for (int i = 0; i < n; i++) {
            cin >> x[i];
            st.insert(x[i]);
        }

        if (st.size() == n) {
            int idx1, idx2;
            for (int i = 0; i < n; i++) {
                if (x[i] == 1) {
                    idx1 = i + 1;
                } 
                if (x[i] == n) {
                    idx2 = i + 1;
                }
            }

            int ans1, ans2; 
            cout << "? " << idx1 << " " << idx2 << endl;
            cin >> ans1;
            cout << "? " << idx2 << " " << idx1 << endl;
            cin >> ans2;

            if (ans1 == ans2 && ans1 >= n - 1) {
                cout << "! B" << endl;
            } else {
                cout << "! A" << endl;
            }
        } else {
            int chosen;
            for (int i = 1; i <= n; i++) {
                if (st.count(i) == 0) {
                    chosen = i; 
                    break;
                }
            }

            int ans;
            int idx = 1; if (idx == chosen) idx = 2;

            cout << "? " << chosen << " " << idx << endl;
            cin >> ans;

            if (ans == 0) {
                cout << "! A" << endl;
            } else {
                cout << "! B" << endl;
            }
        }


        
    }


    return 0;
}
