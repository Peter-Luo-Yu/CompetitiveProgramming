#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define endl "\n"
#define print(arr) for (auto x : arr) cout << x << " "; cout << "\n";
#define print2d(arr) for (int i = 0; i < arr.size(); i++) {for (int j = 0; j < arr[i].size(); j++) {cout << arr[i][j] << " ";} cout << "\n";}
#define printG(adj) for (int i = 0; i < adj.size(); i++) {cout << "i: " << i << " | "; for (int j = 0; j < adj[i].size(); j++) {cout << adj[i][j] << " ";} cout << endl;}
#define printP(arr) for (auto x : arr) {cout << x.first << " " << x.second << "\n";}
#define printS(arr)

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

        stack<int> stk;
        vector<int> moved;
        
        for (int i = 0; i < n; i++) {
            if (i == 0) {
                stk.push(arr[i]);
                continue;
            }

            while (!stk.empty() && stk.top() > arr[i]) {
                moved.push_back(stk.top() + 1);
                stk.pop();
            }

            stk.push(arr[i]);
        }
        
        int minmoved = 2e9;
        if (!moved.empty()) {
            minmoved = *min_element(moved.begin(), moved.end());
        }

        /*
        while (!stk.empty()) {
            cout << stk.top() << endl;
            stk.pop();
        } */

        //cout << "moved: "; print(moved); cout << "minmoved: " << minmoved << " --------" << endl;

        while (!stk.empty() && stk.top() > minmoved) {
            moved.push_back(stk.top() + 1);
            stk.pop();
        }

        vector<int> ans;
        while (!stk.empty()) {
            ans.push_back(stk.top());
            stk.pop();
        }
        for (int i = 0; i < moved.size(); i++) {
            ans.push_back(moved[i]);
        }

        sort (ans.begin(), ans.end());
        print(ans);
        
    }


    
    return 0;
}
