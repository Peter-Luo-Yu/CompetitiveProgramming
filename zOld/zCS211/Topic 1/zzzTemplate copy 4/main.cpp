#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define endl "\n"
#define print(arr) for (auto x : arr) cout << x << ' '; cout << '\n';
#define print2d(arr) for (int i = 0; i < arr.size(); i++) {for (int j = 0; j < arr[i].size(); j++) {cout << arr[i][j] << " ";} cout << "\n";}
#define printG(adj) for (int i = 0; i < adj.size(); i++) {cout << "i: " << i << " | "; for (int j = 0; j < adj[i].size(); j++) {cout << adj[i][j] << " ";} cout << endl;}
#define printM(mp) for (int i = 0; i < mp.size(); i++) {cout << "i: " << i << " | "; print(mp[i]);} cout << endl;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n; cin >> n;
    vector<int> arr (n);
    map<int, vector<int>> mp;

    for (int i = 0; i < n; i++) {
        int val; cin >> val;
        arr[i] = val;
        mp[val].push_back(i);
    }   

    
    //printM(mp);

    int ans = 0;
    vector<bool> vis (n, false);

    for (int i = 0; i < n; i++) {
        if (vis[i]) continue;

        int height = arr[i];
        int idx = i;
        vis[i] = true;
        ans++; height--;
        int idx2 = idx + 1;
        //cout << "i: " << i << " visisted - "; print(vis);

        while (mp[height].size() > 0 && height > 0) {

            idx2 = lower_bound(mp[height].begin(), mp[height].end(), idx + 1) - mp[height].begin();
            
            if (idx2 >= mp[height].size()) {
                //cout << "no later terms for h: " << height << endl;
                break;
            } 
            
            while (idx2 < mp[height].size() && vis[mp[height][idx2]]) {
                idx2++;
            }
            if (idx2 >= mp[height].size()) {
                //cout << "no later terms for h: " << height << endl;
                break;
            } 
            idx = mp[height][idx2];

            //cout << "marked: " << mp[height][idx2] << " value: " << arr[mp[height][idx2]] << endl;
            vis[mp[height][idx2]] = true;

            height--;

        }
        //cout << "i: " << i << " visited - "; print(vis);
       
    }

    cout << ans << endl;

    
    return 0;
}