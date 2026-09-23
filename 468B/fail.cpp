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

    int n, a, b; cin >> n >> a >> b;
    vector<int> arr (n);
    map<int, vector<int>> freq; // stores val - index

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        freq[arr[i]].push_back(i);
    }

    /*
    for (auto f : freq) {
        cout << f.first << " | "; print(f.second);
    } space;
    */

    vector<int> matched (n);
    
    vector<int> ans (n);

    for (int i = 0; i < n; i++) {
        if (matched[i]) continue;

        int cur = i;
        int match = -1;

        if (a - arr[i] == arr[i] && freq[a - arr[i]].size() > 1) {
            match = freq[a - arr[i]][0];
            freq[a - arr[i]].erase(freq[a - arr[i]].begin());
            ans[cur] = 0; ans[match] = 0;
        }
        else if (a - arr[i] != arr[i] && freq.count(a - arr[i]) > 0 && freq[a - arr[i]].size() > 0) {
            match = freq[a - arr[i]][0];
            freq[a - arr[i]].erase(freq[a - arr[i]].begin());
            ans[cur] = 0; ans[match] = 0;
        }
        else if (b - arr[i] == arr[i] && freq[b - arr[i]].size() > 1) {
            match = freq[b - arr[i]][0];
            freq[b - arr[i]].erase(freq[b - arr[i]].begin());
            ans[cur] = 0; ans[match] = 0;
        }
        else if (b - arr[i] != arr[i] && freq.count(b - arr[i]) > 0 && freq[b - arr[i]].size() > 0) {
            match = freq[b - arr[i]][0];
            freq[b - arr[i]].erase(freq[b - arr[i]].begin());
            ans[cur] = 1; ans[match] = 1;
        }

        //cout << "cur: " << cur << " match: " << match << endl;

        if (match != -1) {
            freq[arr[i]].erase(freq[arr[i]].begin());
            matched[i] = true;
            matched[match] = true;
        }

        /*
        for (auto f : freq) {
            cout << f.first << " | "; print(f.second);
        } space;
         */
        
    }

    bool failed = false;
    for (auto f : freq) {
        if (f.second.size() > 0) {
            failed = true;
        }
    }
    if (failed) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
        print(ans);
    }
   


    return 0;
}
