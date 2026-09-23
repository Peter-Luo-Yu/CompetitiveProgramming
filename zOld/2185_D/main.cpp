#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define endl "\n"
#define print(arr) for (auto x : arr) cout << x << ' '; cout << '\n';
#define print2d(arr) for (int i = 0; i < arr.size(); i++) {for (int j = 0; j < arr[i].size(); j++) {cout << arr[i][j] << " ";} cout << "\n";}
#define printG(adj) for (int i = 0; i < adj.size(); i++) {cout << "i: " << i << " | "; for (int j = 0; j < adj[i].size(); j++) {cout << adj[i][j] << " ";} cout << endl;}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int t; cin >> t;
    while (t--) {
        int n, m, h; cin >> n >> m >> h;

        vector<int> arr (n);
        for (int i = 0; i < n; i++) {cin >> arr[i];}

        vector<int> temp = arr;
        bool reset = false;
        for (int i = 0; i < m; i++) {
            int a, b; cin >> a >> b; a--;

            if (temp[a] + b > h) {
                if (reset) {
                    
                } else {
                    temp = arr;
                    reset = true;
                }
                
            } else {
                temp[a] += b;
                reset = false;
            }
        }

        print(temp);
    }
    

    return 0;
}