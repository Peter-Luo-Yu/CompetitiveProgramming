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

    ll n; cin >> n;

    vector<ll> thresh (n), cur (n);
    map<ll, vector<pair<ll, ll>>> mp;

    for (int i = 0; i < n; i++) {
        ll t; cin >> t; thresh[i] = t;
        ll m; cin >> m;

        for (int j = 0; j < m; j++) {
            ll source, amount; 
            cin >> source >> amount;
            source--;

            cur[i] += amount;

            mp[source].push_back({i, amount});
        }
    }

    //print(thresh);
    //print(cur);
    //space;

    /*
    for (auto x : mp) {
        cout << x.first << " | "; printP(x.second);
    } 
    space;
    */
    
    vector<bool> vis(n);
    queue<ll> q;
    q.push(0); vis[0] = true;

    while (!q.empty()) {
        ll val = q.front();
        q.pop();

        //cout << "val: " << val << endl;

        vector<pair<ll, ll>> arr = mp[val];

        for (int i = 0; i < arr.size(); i++) {
            //cout << arr[i].first << " lost " << arr[i].second << endl;

            cur[arr[i].first] -= arr[i].second;

            //cout << "i: " << arr[i].first << " arr: " << cur[arr[i].first] << endl;

            if (cur[arr[i].first] < thresh[arr[i].first]) {

                if (!vis[arr[i].first]) {
                    //cout << "dead: " << arr[i].first << endl;

                    q.push(arr[i].first);
                    vis[arr[i].first] = true;
                }
            }
        }

    }

    //space;
    //print(thresh);
    //print(cur);
    //space;

    ll surviving = n - 1;
    for (int i = 1; i < cur.size(); i++) {
        if (cur[i] < thresh[i]) {
            surviving--;
        }
    }

    cout << max(surviving, 0LL) << endl;

    return 0;
}
