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

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;

        vector<int> arr (n);
        for (int i = 0; i < n; i++) {cin >> arr[i];}

        vector<int> temp, ans;

        
        int idx = 0; // starting index

        if (arr[0] == n) {
            while (arr[idx] == arr[idx + 1] + 1 && idx < n - 1) {
                idx++;
            }
            idx++;
        } else {
            idx = 0;
        }

        cout << "start idx: " << idx << endl;

        if (idx >= n) {
            print(arr); continue;
        }

        int idx2 = 0, Max = -1;
        for (int i = idx; i < n; i++) {
            if (arr[i] > Max) {
                Max = arr[i];
                idx2 = i;
            }
        }

        for (int i = idx; i <= idx2; i++) {
            temp.push_back(arr[i]);
        }
        reverse(temp.begin(), temp.end());
        //cout << "temp: "; print(temp);

        for (int i = 0; i < n; i++) {
            if (i < idx || i > idx2) {
                ans.push_back(arr[i]);
            } else {
                ans.push_back(temp[i - idx]);
            }
        }

        //cout << "ans: "; 
        print(ans);
    }

    

    return 0;
}