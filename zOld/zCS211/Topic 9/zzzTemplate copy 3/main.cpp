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

stack<int> stk;
vector<int> SCC;
vector<bool> vis;
int sccidx = 0;

void dfs (vector<vector<int>> &adj, vector<bool> &vis, int s) {
    if (vis[s]) return;

    vis[s] = true;

    for (auto x : adj[s]) {
        dfs(adj, vis, x);
    }

    //cout << "pushing: " << s << endl;
    stk.push(s);
}

void dfs2 (vector<vector<int>> &rev, vector<bool> &vis, int s) {
    if (vis[s]) return;

    vis[s] = true;

    for (auto x : rev[s]) {
        dfs2(rev, vis, x);
    }

    SCC[s] = sccidx;
}




int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);


    int n = -1;
    string s = "sup"; 

    vector<vector<string>> data;
    vector<vector<int>> adj;

    int idx = 0;
    while (!s.empty()) {
        getline(cin, s);
        //cout << s << endl;

        if (s.empty()) break;

        if (n == -1) {
            n = stoi(s);
            //cout << "N: " << n << endl;
            adj = vector<vector<int>> (n);
            data = vector<vector<string>> (n);
            SCC = vector<int> (n);
            vis = vector<bool> (n);
            continue;
        }       
        
        int prev = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == ' ') {
                //cout << "sub: " << s.substr(prev, i - prev) << endl;
                
                data[idx].push_back(s.substr(prev, i - prev));
                prev = i + 1;
            }
        }
        data[idx].push_back(s.substr(prev));
        idx++;

    }

    /*
    
    for (int i = 0; i < data.size(); i++) {
        for (int j = 0; j < data[i].size(); j++) {
            cout << data[i][j] << " | ";
        } cout << endl;
    } cout << endl;

    cout << data.size() << endl; space;

    */

    for (int i = 0; i < data.size(); i++) {

        for (int j = 0; j < data.size(); j++) {
            if (i == j) {
                continue;
            }

            for (int k = 0; k < data[j].size(); k++) {
                if (data[i][1] == data[j][k]) {
                    adj[j].push_back(i);
                }
            }
        }
    } 

    //printG(adj); space;
    
    vector<vector<int>> rev (adj.size());

    for (int i = 0; i < adj.size(); i++) {
        for (int j = 0; j < adj[i].size(); j++) {
            rev[adj[i][j]].push_back(i);
        }
    }

    // DO KOSARAJU

    for (int i = 0; i < n; i++) {
        dfs (adj, vis, i);
    }

    vis = vector<bool> (n);

    while (!stk.empty()) {
        int val = stk.top();
        stk.pop();

        //cout << "val: " << val << endl;

        if (!vis[val]) {
            dfs2(rev, vis, val);
            sccidx++;
        }
    }

    //print(SCC);

    map<int, int> mp;

    for (int i = 0; i < SCC.size(); i++) {
        mp[SCC[i]]++;
    }

    int Max = -1;
    for (int i = 0; i < mp.size(); i++) {
        Max = max (Max, mp[i]);
    } 

    cout << SCC.size() - Max << endl;
    
    return 0;
}
