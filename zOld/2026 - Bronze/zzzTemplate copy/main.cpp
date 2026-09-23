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

    int t, k; cin >> t >> k;

    while (t--) {
        int n; cin >> n;
        string s; cin >> s;
        vector<char> arr (n);
        for (int i = 0 ; i < n; i++) {
            arr[i] = s[i];
        }

        int count = 0;
        vector<int> flips (n, 0);
        vector<bool> fixed (n, false);
        int curO = -1;  // if O then 1, M then 0 
        for (int i = n - 1; i >= 0; i--) {
            if (curO == -1) {
                if (arr[i] == 'O') {
                    curO = 1;
                    count++;
                    flips[i] = count;
                    fixed[i] = true;
                }
            }
            else {
                if (arr[i] == 'O' && curO == 0) {   
                    curO = 1;
                    count++;
                    flips[i] = count;
                    fixed[i] = true;
                }
                else if (arr[i] == 'M' && curO == 1) {
                    curO = 0;
                    count++;
                    flips[i] = count;
                    fixed[i] = true;
                } else {
                    flips[i] = count;

                }
            }
        }

        //print(arr);
        //print(flips);
        //print(fixed);

        vector<char> ans (n);

        if (k == 0) {
            cout << "YES" << endl;
        } else {
            for (int i = 0; i < n; i++) {
                if (fixed[i]) {
                    ans[i] = 'O';
                }
                else {
                    if (arr[i] == 'O') {
                        if (flips[i] % 2 == 1) {
                            ans[i] = 'M';
                        } else {
                            ans[i] = 'O';
                        }
                    } else {
                        if (flips[i] % 2 == 1) {
                            ans[i] = 'O';
                        } else {
                            ans[i] = 'M';
                        }
                        
                    }
                }
            }

            // print ans
            cout << "YES" << endl;
            for (int i = 0; i < ans.size(); i++) {
                cout << ans[i];
            } cout << endl;

        }

        //cout << "----" << endl;
    }
    

    return 0;
}