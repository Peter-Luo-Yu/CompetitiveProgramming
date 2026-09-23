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
        int n, m; cin >> n >> m;

        vector<int> arr(n);
        //map<int, bool> safe; // can't remove these
        vector<pair<int, int>> odd, even;

        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        
        /*
        vector<int> arr2 = arr;
        sort (arr2.begin(), arr2.end());
        for (int i = 0; i < n - m; i++) {
            safe[arr2[i]] = true;
        } */
        

        for (int i = 0; i < n; i++) {
            if (i % 2 == 0) {
                odd.push_back({arr[i], i});
            } else {
                even.push_back({arr[i], i});
            }
        }

        sort (odd.begin(), odd.end());
        sort (even.begin(), even.end());
        reverse (odd.begin(), odd.end());
        reverse (even.begin(), even.end());

        //printP(odd); space; printP(even); space; printP(safe); space;

        int numOdd = 0, numEven = 0;
        for (int i = 0; i < m; i++) {
            int val; cin >> val;

            if (val % 2 == 1) {
                numOdd++;
            } else {
                numEven++;
            }
        }

        //cout << "odd: " << numOdd << " even: " << numEven << endl;
        
        int oddMarked = 0, evenMarked = 0;

        vector<bool> marked (n, false);
        int idx = 0;
        for (int i = 0; i < numOdd; i++) {
            int remove = odd[idx].first;

            if (remove > 0) {
                //cout << "r: " << remove << endl;
                marked[odd[idx].second] = true; oddMarked++;
                idx++;
            }
            if (idx >= odd.size()) {
                break;
            }
        }

        idx = 0;
        for (int i = 0; i < numEven; i++) {
            int remove = even[idx].first;
            if (remove > 0) {
                //cout << "r: " << remove << endl;
                marked[even[idx].second] = true; evenMarked++;
                idx++;
            }
            if (idx >= even.size()) {
                break;
            }
        }


        if (numOdd > 0 && oddMarked == 0) {
            marked[odd[0].second] = true;
        }
        if (numEven > 0 && evenMarked == 0) {
            marked[even[0].second] = true;
        }



        ll ans = 0;
        for (int i = 0; i < n; i++) {
            if (!marked[i]) {
                ans += arr[i];
            }
        }

        cout << ans << endl;

        //space; space;
    }
    
    return 0;
}
