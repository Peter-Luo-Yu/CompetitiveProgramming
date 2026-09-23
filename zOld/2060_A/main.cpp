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
        int a1, a2, a4, a5; cin >> a1 >> a2 >> a4 >> a5;

        int Ans = -1;
        for (int i = -200; i < 200; i++) {
            int a3 = i, ans = 0;

            if (a1 + a2 == a3) {
                ans++;
            } 
            if (a2 + a3 == a4) {
                ans++;
            }
            if (a3 + a4 == a5) {
                ans++;
            }

            Ans = max (Ans, ans);
        }

        cout << Ans << endl;
    }
    
    
    return 0;
}
