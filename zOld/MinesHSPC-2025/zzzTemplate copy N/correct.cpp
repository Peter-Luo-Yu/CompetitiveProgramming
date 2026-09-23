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

    int n; cin >> n;

    vector<vector<int>> adj (n);

    for (int i = 0; i < n; i++) {
        int b; cin >> b; b--;
        adj[i].push_back(b);
    }

    //printG(adj);

    vector<int> indeg (n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < adj[i].size(); j++) {
            indeg[adj[i][j]]++;
        }
    }

    //cout << "start indeg: "; print(indeg);

    vector<bool> matched (n);
    int pairs = 0;
    // Greedy: always pair the leaf with it's parent
    queue<int> q;
    for (int i = 0; i < n; i++) {
        if (indeg[i] == 0) {
            q.push(i);
        }
    }

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        int match = adj[cur][0];

        if (matched[cur] || matched[match]) continue;

        indeg[match]--;
        matched[cur] = true;
        matched[match] = true;

        pairs++;

        int next = adj[match][0];
        if (matched[next]) continue;

        indeg[next]--;

        if (indeg[next] == 0) {
            q.push(next);
        }
    }

    //cout << "end indeg:   "; print(indeg);

    //print(matched);


    // now there are only cycles

    for (int i = 0; i < n; i++) {
        if (!matched[i]) {
            int len = 0;

            int cur = i;
            while (!matched[cur]) {
                matched[cur] = true;
                len++;
                cur = adj[cur][0];
            }

            
            pairs += len / 2;
            
        }
    }

    cout << n - 2 * pairs << endl;

    return 0;
}