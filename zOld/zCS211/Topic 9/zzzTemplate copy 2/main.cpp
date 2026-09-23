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

int sccidx = 0;
vector<int> SCC;
stack<int> stk;

void dfs (vector<vector<int>> &adj, vector<bool> &vis, int s) {
    if (vis[s]) return;
    vis[s] = true;
    for (auto x: adj[s]) {
        dfs (adj, vis, x);
    }   
    stk.push(s);
}

void dfs2 (vector<vector<int>> &adj, vector<bool> &vis, int s) {
    if (vis[s]) return;
    vis[s] = true;
    for (auto x: adj[s]) {
        dfs2 (adj, vis, x);
    }   
    SCC[s] = sccidx;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    map<string, int> mp;
    vector<string> arr;
    vector<pair<string, string>> data;

    int n; cin >> n;
    int idx = 0;
    for (int i = 0; i < n; i++) {
        string a, b; cin >> a >> b;
        data.push_back({a, b});

        if (mp.count(a) == 0) {
            mp[a] = idx; idx++;
            arr.push_back(a);
        }
        if (mp.count(b) == 0) {
            mp[b] = idx; idx++;
            arr.push_back(b);
        }
    }

    //printP(mp);
    //print(arr);

    vector<vector<int>> adj (arr.size()), rev (arr.size());
    vector<bool> vis (arr.size());
    SCC = vector<int> (arr.size());

    for (int i = 0; i < data.size(); i++) {
        adj[mp[data[i].first]].push_back(mp[data[i].second]);
        rev[mp[data[i].second]].push_back(mp[data[i].first]);
    }

    //printG(adj);
    
    for (int i = 0; i < arr.size(); i++) {
        dfs(adj, vis, i);
    }

    vis = vector<bool> (arr.size());

    while (!stk.empty()) {
        int val = stk.top();
        stk.pop();

        if (!vis[val]) {
            dfs2 (rev, vis, val);
            sccidx++;
        }
    }

    
    map<int, vector<int>> sccmp;
    for (int i = 0; i < SCC.size(); i++) {
        sccmp[SCC[i]].push_back(i);
    }


    vector<vector<string>> good_groups;
    vector<string> bad_groups;

    for (auto x : sccmp) {
        //cout << x.first << " | "; print(x.second);

        if (x.second.size() > 1) {
            vector<string> temp;

            for (int i = 0; i < x.second.size(); i++) {
                temp.push_back(arr[x.second[i]]);
            }

            sort(temp.begin(), temp.end());  
            
            good_groups.push_back(temp);
        }
    }
    for (auto x : sccmp) {
        if (x.second.size() == 1) {
            bad_groups.push_back(arr[x.second[0]]);
        }
    }

    sort (good_groups.begin(), good_groups.end());
    sort (bad_groups.begin(), bad_groups.end());
    
    for (int i = 0; i < good_groups.size(); i++) {
        cout << "okay "; 
        for (int j = 0; j < good_groups[i].size(); j++) {
            cout << good_groups[i][j] << " ";
        }
        cout << endl;
    }
    
    if (!bad_groups.empty()) {
        cout << "avoid ";
        for (int i = 0; i < bad_groups.size(); i++) {
            cout << bad_groups[i] << " ";
        }
        cout << endl;
    }
    
    return 0;
}
