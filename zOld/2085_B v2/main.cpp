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
        vector<int> arr (n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        
        //print(arr);

        vector<pair<int, int>> ans;

        while (true) {
            //print(arr);

            int idx = -1;

            // just greedily combine 0 with the guy to his right, last zero is to the left of course
            for (int i = 0; i < arr.size(); i++) {
                if (arr[i] == 0) {
                    idx = i;
                    break;
                }
            }

            if (idx == -1) {
                break;
            }

            //cout << "idx: " << idx << endl;

            vector<int> next;

            if (idx < arr.size() - 1) {
                ans.push_back({idx, idx + 1});

                for (int i = 0; i < idx; i++) {
                    next.push_back(arr[i]);
                }

                if (arr[idx + 1] == 1) { 
                    next.push_back(2);
                } else {
                    next.push_back(1);
                }

                for (int i = idx + 2; i < arr.size(); i++) {
                    next.push_back(arr[i]);
                }

            } else { // idx == n - 1;
                ans.push_back({idx - 1, idx});

                for (int i = 0; i < idx - 1; i++) {
                    next.push_back(arr[i]);
                }
               
                if (arr[idx - 1] == 1) { 
                    next.push_back(2);
                } else {
                    next.push_back(1);
                }
            }

            arr = next;
        }


        ans.push_back({0, arr.size() - 1});

        cout << ans.size() << endl;

        for (auto x : ans) {
            cout << x.first + 1 << " " << x.second + 1 << endl;
        }


        //space;
    }


    return 0;
}
