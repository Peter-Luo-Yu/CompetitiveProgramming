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
    cin.tie(0);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int t; cin >> t;
    
    while (t--) {
        int n; cin >> n;

        vector<int> a (n), b (n, -1);

        for (int i = 0; i < n; i++) cin >> a[i];

        vector<bool> taken (n, false);

        for (int i = 0; i < n; i++) {
            if (!taken[a[i] - 1]) {
                b[i] = a[i];
                taken[a[i] - 1] = true;
            }
        }
        
        int idx = 0;
        for (int i = 0; i < n; i++) {
            if (b[i] == -1) {
                while (taken[idx]) {
                    idx++;
                }

                b[i] = idx + 1;
                taken[idx] = true;
            }
        }

        print(b);
        
        /*
        vector<int> block, blockLen;
        int prev = -1, len = 0;
        for (int i = 0; i < n - 1; i++) {
            if (prev == -1) {
                prev = a[i]; len++;
                block.push_back(a[i]); 
            }
            if (a[i] == a[i + 1]) {
                len++;
            } else {
                blockLen.push_back(len);

                prev = a[i];
                block.push_back(a[i + 1]);
                len = 1;
            }
        }
        //block.push_back(a[a.size() - 1]);
        blockLen.push_back(len);

        print(block); print(blockLen);

        // 4 5 5 5 5 1 1 2 1
        // block: 4, 5, 1, 2, 1     (have each number appear equal number of times)
        // len:   1, 4, 2, 1, 1
        4 5 5 5 1 1 2 1
        
        */




    }

    return 0;
}