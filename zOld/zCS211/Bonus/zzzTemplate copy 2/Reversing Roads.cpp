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



vector<int> SCC;
stack<int> stk;
int sccidx = 0;

void dfs (vector<vector<int>> &adj, vector<bool> &vis, int s) {
    if (vis[s]) return;
    vis[s] = true;
    for (auto u : adj[s]) {
        dfs(adj, vis, u);
    }
    stk.push(s);
}

void dfs2 (vector<vector<int>> &adj, vector<bool> &vis, int s) {
    if (vis[s]) return;
    vis[s] = true;
    for (auto u : adj[s]) {
        dfs2 (adj, vis, u);
    }
    SCC[s] = sccidx;
}


int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    string str;
    int cnt = 1;
    vector<pair<int, int>> data;

    do {
        int n, m;
        getline(cin, str);
        if (str.empty()) break;

        int idx = str.find(" ");
        n = stoi(str.substr(0, idx));
        m = stoi(str.substr(idx + 1));

        vector<vector<int>> adj(n), rev(n);
        vector<bool> vis (n);

        SCC = vector<int> (n);
        stk = stack<int> ();
        sccidx = 0;

        vector<pair<int, int>> data;

        for (int i = 0; i < m; i++) {
            int a, b;
            getline(cin, str);
            idx = str.find(" ");
 

            a = stoi(str.substr(0, idx));
            b = stoi(str.substr(idx + 1));

            data.push_back({a, b});
        }


        for (int i = 0; i < data.size(); i++) {
            int a = data[i].first, b = data[i].second;
            adj[a].push_back(b);
            rev[b].push_back(a);
        }

        for (int i = 0; i < n; i++) {
            dfs(adj, vis, i);
        }
        vis = vector<bool> (n);
        while (!stk.empty()) {
            int val = stk.top();
            stk.pop();
            if (!vis[val]) {
                dfs2 (rev, vis, val);
                sccidx++;
            }
        }
        set<int> st;
        for (int i = 0; i < n; i++) {st.insert(SCC[i]);}
        //cout << "orig: " << st.size() << endl;

        if (st.size() == 1) {
            cout << "Case " << cnt << ": valid" << endl;
            cnt++;
            continue;
        }

       
        int ans1 = -1, ans2 = -1;
        bool found = false;

        for (int i = 0; i < data.size(); i++) {
            vector<pair<int, int>> arr = data;
            ans1 = arr[i].first;
            ans2 = arr[i].second;
            swap(arr[i].first, arr[i].second);
            

            adj = vector<vector<int>> (n);
            rev = vector<vector<int>> (n);
            vis = vector<bool> (n);

            SCC = vector<int> (n);
            stk = stack<int> ();
            sccidx = 0;
            
            for (int i = 0; i < arr.size(); i++) {
                int a = arr[i].first, b = arr[i].second;
                adj[a].push_back(b);
                rev[b].push_back(a);
            }

            // kosrarju
            for (int i = 0; i < n; i++) {
                dfs(adj, vis, i);
            }
            vis = vector<bool> (n);
            while (!stk.empty()) {
                int val = stk.top();
                stk.pop();
                if (!vis[val]) {
                    dfs2 (rev, vis, val);
                    sccidx++;
                }
            }
            st = set<int> ();

            for (int i = 0; i < n; i++) {st.insert(SCC[i]);}
            //cout << st.size() << endl;
                
            if (st.size() == 1) {
                found = true;
                break;
            }
        }

        if (found) {
            cout << "Case " << cnt << ": " << ans1 << " " << ans2 << endl;
        } else {
            cout << "Case " << cnt << ": invalid" << endl;
        }


        cnt++;
    } while (!str.empty());
    
    return 0;
}
