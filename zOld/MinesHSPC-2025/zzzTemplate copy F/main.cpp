#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define endl "\n"
#define print(arr) for (auto x : arr) cout << x << " "; cout << "\n";
#define print2d(arr) for (int i = 0; i < arr.size(); i++) {for (int j = 0; j < arr[i].size(); j++) {cout << arr[i][j] << " ";} cout << "\n";}
#define printG(adj) for (int i = 0; i < adj.size(); i++) {cout << "i: " << i << " | "; for (int j = 0; j < adj[i].size(); j++) {cout << adj[i][j] << " ";} cout << endl;}
#define printP(arr) for (auto x : arr) {cout << x.first << " " << x.second << "\n";}
#define space cout << "----------" << endl;

int n, k;
vector<int> subset;
vector<bool> vis;

vector<int> ans;
vector<pair<int, int>> arr;

void search (int x) {
    if (x == n) {
        //print(subset); cout << "size: " << subset.size() << endl;

        for (int i = 0; i < subset.size(); i++) {
            vis[subset[i]] = true;
        }

        //print(vis);

        bool failed = false;
        for (int i = 0; i < arr.size(); i++) {
            if (vis[arr[i].first - 1] && vis[arr[i].second - 1]) {
                failed = true;
                break;
            }
        }

        if (!failed) {
            //cout << "didn't fail" << endl;
            ans[subset.size()]++; 
        }

        vis = vector<bool> (n);
        return;
    } 

    search (x + 1);
    subset.push_back(x);
    search (x + 1);
    subset.pop_back();
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    cin >> n >> k;

    ans = vector<int> (n + 1);
    arr = vector<pair<int, int>> (k);
    vis = vector<bool> (n);

    for (int i = 0; i < k; i++) {
        cin >> arr[i].first >> arr[i].second;
    }

    search(0);

    print(ans);

    return 0;
}
