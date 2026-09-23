#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define endl "\n"
#define print(arr) for (auto x : arr) cout << x << " "; cout << "\n";
#define print2d(arr) for (int i = 0; i < arr.size(); i++) {for (int j = 0; j < arr[i].size(); j++) {cout << arr[i][j] << " ";} cout << "\n";}
#define printG(adj) for (int i = 0; i < adj.size(); i++) {cout << "i: " << i << " | "; for (int j = 0; j < adj[i].size(); j++) {cout << adj[i][j] << " ";} cout << endl;}
#define printP(arr) for (auto x : arr) {cout << x.first << " " << x.second << "\n";}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> arr (n);
        for (int i = 0; i < n; i++) {cin >> arr[i];}    

        vector<int> temp = arr;
        sort (temp.begin(), temp.end());
        bool allzero = true;
        int mex = 0;
        for (int i = 0; i < n; i++) {
            if (temp[i] == mex) {
                mex++;
            }
            if (arr[i] != 0) {
                allzero = false;
            }
        }   

        if (allzero) {
            cout << 0 << endl;
            continue;
        }

        // check for only 1 operation
        //print(arr);
        bool failed = false;
        int startidx = -1;
        int endidx = -1;
        for (int i = 0; i < n; i++) {
            if (arr[i] != 0 && startidx == -1) {
                startidx = i;
                //cout << "first non 0: " << startidx << endl;
                continue;
            }   
            if (i > startidx && startidx != -1) {
                if (arr[i] == 0 && endidx == -1) {
                    endidx = i;
                    continue;
                }
                if (endidx != -1) {
                    if (arr[i] != 0) {
                        failed = true;
                    }
                }
            }
        }

        if (failed) {
            cout << 2 << endl;
        } else {
            cout << 1 << endl;
        }


    }
    
    return 0;
}
