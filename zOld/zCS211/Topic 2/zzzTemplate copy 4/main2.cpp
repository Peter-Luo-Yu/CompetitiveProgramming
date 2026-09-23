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
        int p, n; cin >> p >> n;
        vector<int> a (n);
        int sum = 0;
        for (int i = 0; i < n; i++) {cin >> a[i]; sum += a[i];}

        if (p > sum) {cout << "IMPOSSIBLE" << endl; continue;}
        
        sum = p;
        vector<vector<int>> arr;

        int avg = p / n;
        for (int i = 0; i < n; i++) {
            // the capacity is a[i]
            int contrib = min (a[i], avg);
            sum -= contrib;

            arr.push_back({a[i], contrib, i});
        }

        // sort the arr and simulate the remaining dollars
        sort (arr.begin(), arr.end());
        int curIdx = 0;
        for (int i = 0; i < n; i++) {
            if (arr[i][0] != arr[curIdx][0]) {
                reverse (arr.begin() + curIdx, arr.begin() + i);
                curIdx = i;
            }
        }
        reverse (arr.begin() + curIdx, arr.end());

        
        //cout << "remaining: " << sum << endl; print2d(arr); 
        
        // simulating
        
        int idx = arr.size() - 1;
        while (sum > 0) {
            if (idx < 0) {
                idx = arr.size() - 1;
            }
            //cout << "idx before: " << idx << " max: " << arr[idx][0] << " contrib: " << arr[idx][1] << endl;
            while (arr[idx][0] <= arr[idx][1]) {
                idx--;
                if (idx < 0) {
                    idx = arr.size() - 1;
                }
            }
            if (idx < 0) {
                idx = arr.size() - 1;
            }

            //cout << "idx after: " << idx << " max: " << arr[idx][0] << " contrib: " << arr[idx][1] << endl;

            arr[idx][1]++;
            idx--;
            sum--;
        }
        

        //cout << "final: " << endl; print2d(arr); 

        vector<int> ans (n);
        for (int i = 0; i < n; i++) {
            ans[arr[i][2]] = min (arr[i][0], arr[i][1]);
        }

        //cout << "ans: "; 
        print(ans);

        //cout << "----------" << endl;
       
    }
    

    return 0;
}