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
        vector<int> arr (n); map<int, int> freq;

        for (int i = 0; i < n; i++) {
            cin >> arr[i];
            freq[arr[i]]++;
        }

        set<int> orig;
        for (int i = 0; i < n; i++) {orig.insert(arr[i]);}

        if (orig.size() == n) {
            cout << 1 << " " << n << endl; 

            continue;
        }

        // any element appearing more than once simply cannot be removed
        //printP(freq);
        //cout << "---" << endl;

        vector<pair<int, int>> temp;
        int l = -1, r = -1;
        for (int i = 0; i < n; i++) {
            if (freq[arr[i]] == 1) {
                if (l == -1) {
                    l = i; r = l;
                } else {
                    r = i;
                }
            } else {
                temp.push_back({l, r});
                l = -1, r = -1;
            }
        }
        if (l != -1) {
            temp.push_back({l, r});
        }
       

        //cout << "temp: "; printP(temp);
        //cout << "---" << endl;

        int bestIdx = -1;
        int maxDiff = -1;
        for (int i = 0; i < temp.size(); i++) {
            if (temp[i].first != -1) {
                if (temp[i].second - temp[i].first > maxDiff) {
                    maxDiff = temp[i].second - temp[i].first;
                    bestIdx = i;
                }
            }
        }

        if (bestIdx == -1) {
            cout << 0 << endl;
        } else {
            cout << temp[bestIdx].first + 1 << " " << temp[bestIdx].second + 1 << endl;
        }


    }

    
    return 0;
}
