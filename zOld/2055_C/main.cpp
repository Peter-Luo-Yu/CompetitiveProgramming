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
        int n, m; cin >> n >> m;
        string s; cin >> s;

        vector<vector<ll>> arr (n, vector<ll> (m));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> arr[i][j];
            }
        }

        vector<ll> rowS(n), colS(m);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                rowS[i] += arr[i][j];
            }
        }
        
        for (int j = 0; j < m; j++) {
            for (int i = 0; i < n; i++) {
                colS[j] += arr[i][j];
            }
        }

        //cout << "row: "; print(rowS); cout << "col: "; print(colS);

        int r = 0, c = 0;

        for (int i = 0; i < s.size(); i++) {
            //cout << "r: " << r << " c: " << c << endl; 
            //if (r >= n || c >= m) break;
            if (s[i] == 'D') {  // leaving a row
                arr[r][c] = -rowS[r];
                rowS[r] = 0;
                colS[c] += arr[r][c];
                r++;
            } else {
                arr[r][c] = -colS[c];
                colS[c] = 0;
                rowS[r] += arr[r][c];
                c++; 
            } 
        }

        // actually have to take care of the final 0
        arr[r][c] = -rowS[r];


        print2d(arr); 
    }
    
    
    return 0;
}
