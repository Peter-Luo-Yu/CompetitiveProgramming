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
        int n; cin >> n;
        vector<int> arr (n);

        string s; cin >> s;

        for (int i = 0; i < n; i++) {arr[i] = s[i] - '0';}

        int num1 = 0;
        vector<int> idxOf1;

        for (int i = 0; i < n; i++) {
            if (arr[i] == 1) {
                num1++;
                idxOf1.push_back(i);
            }
        }

        vector<int> idxOf0;
        for (int i = n - 1; i > n - 1 - num1; i--) {
            //cout << "i: " << i << endl;
            if (arr[i] == 0) {
                idxOf0.push_back(i);
            }
        }

        /*
        cout << "number of 1's: " << num1 << endl; 
        cout << "1's: "; print(idxOf1);
        cout << "0's: "; print(idxOf0);
        */

        if (num1 == 0 || num1 == n) {
            cout << "Bob" << endl;
            continue;
        }
        bool sorted = true;
        for (int i = n - 1; i > n - 1 - num1; i--) {
            if (arr[i] != 1) {
                sorted = false;
            }
        }

        if (sorted) {
            cout << "Bob" << endl;
            continue;
        }

        else {
            cout << "Alice" << endl;
        }

        int count = 0;
        for (int i = 0; i < idxOf1.size(); i++) {
            if (idxOf1[i] < n - num1) {
                count++;

            }
        }
        for (int i = 0; i < idxOf0.size(); i++) {
            count++;

        }

        cout << count << endl;
        vector<int> ans;

        for (int i = 0; i < idxOf1.size(); i++) {
            if (idxOf1[i] < n - num1) {
 
                ans.push_back(idxOf1[i] + 1);
            }
        }
        for (int i = 0; i < idxOf0.size(); i++) {

            ans.push_back(idxOf0[i] + 1);
        }

        sort (ans.begin(), ans.end());

        for (int i= 0; i < ans.size(); i++){
            cout << ans[i] << " ";
        }
        
        cout << endl;

    }
    

    return 0;
}