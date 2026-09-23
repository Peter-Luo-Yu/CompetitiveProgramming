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

    //cout << "pushing: " << s << endl;

    stk.push(s);
}

void dfs2 (vector<vector<int>> &adj, vector<bool> &vis, int s) {
    if (vis[s]) return;
    vis[s] = true;

    for (auto u : adj[s]) {
        dfs2 (adj, vis, u);
    }

    //cout << "s: " << s << endl;

    SCC[s] = sccidx;

}


int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

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

        //cout << n << " " << m << endl; 

        vector<vector<int>> adj(n);
        vector<bool> vis (n);
        SCC = vector<int> (n);
        stk = stack<int> ();
        sccidx = 0;

        data = vector<pair<int, int>> ();

        for (int i = 0; i < m; i++) {
            int a, b;

            getline(cin, str);

            idx = str.find(" ");

            a = stoi(str.substr(0, idx));
            b = stoi(str.substr(idx + 1));

            //cout << a << " " << b << endl;
            
            adj[a].push_back(b);

            data.push_back({a, b});
        }

        vector<vector<int>> orig = adj;
        vector<vector<int>> revOrig (n);

        for (int i = 0; i < orig.size(); i++) {
            for (int j = 0; j < orig[i].size(); j++) {
                revOrig[orig[i][j]].push_back(i);
            }
        }

        //printG(orig); space;
        //printG(revOrig); space;

        for (int i = 0; i < n; i++) {
            dfs(orig, vis, i);
        }

        //print(vis);

        vis = vector<bool> (n);
        
        while (!stk.empty()) {
            int val = stk.top();
            stk.pop();

            //cout << "val: " << val << endl;

            if (!vis[val]) {
                dfs2 (revOrig, vis, val);
                sccidx++;
            }
        }
            
        print(SCC);

        set<int> initial;
        for (int i = 0; i < n; i++) {initial.insert(SCC[i]);}
        
        if (initial.size() == 1) {
            cout << "Case 1: valid" << endl;

            cout << "====================" << endl;
            continue;
        }


        cout << "===========" << endl;

        // rev an edge.

        bool found = false;
        int one = -1, two = -1;
        
        cout << "data: "; printP(data);

        for (int i = 0; i < m; i++) {
            vector<pair<int, int>> arr = data;

            int temp = arr[i].first;

            arr[i].first = arr[i].second;
            arr[i].second = arr[i].first;

            one = arr[i].first, two = arr[i].second;

            adj = vector<vector<int>> (n);
            vector<vector<int>> rev(n);

            for (int j = 0; j < arr.size(); j++) {
                int a = arr[j].first, b = arr[j].second;

                adj[a].push_back(b);
                rev[b].push_back(a);
            }

            //printG(adj);
            
            SCC = vector<int> (n);
            stk = stack<int> ();
            sccidx = 0;
            vis = vector<bool> (n);
            for (int i = 0; i < n; i++) {
                dfs(adj, vis, i);
            }

            print(vis);

            vis = vector<bool> (n);
            while (!stk.empty()) {
                int val = stk.top();
                stk.pop();

                if (!vis[val]) {
                    dfs2 (revOrig, vis, val);
                    sccidx++;
                }
            }

            cout << "SCC: "; print(SCC);

            set<int> setset;
            for (int i = 0; i < n; i++) {setset.insert(SCC[i]);}
        
            if (setset.size() == 1) {
                found = true;
                break;
            }

            space;
        }



        if (found) {
            cout << "found" << endl;
        }





        cout << "====================" << endl;

    } while (!str.empty());
    
    
    return 0;
}
