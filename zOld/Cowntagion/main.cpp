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

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n; cin >> n;

    vector<vector<int>> adj (n);

    for (int i = 0; i < n - 1; i++) {
        int a, b; cin >> a >> b; a--, b--;

        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    //printG(adj);

    int ans = n - 1;

    for (int i = 0; i < n; i++) {
        if (adj[i].size() > 1 || i == 0) {
            int children = adj[i].size();
            if (i != 0) children--;

            int log_children = 0;
			int pow = 1;
			while(pow < children + 1) { // need one more to keep for yourself, send the other n - 1 to the children.
				log_children++, pow *= 2;
            }
			ans += log_children;

            //cout << log_children << endl;
        }
    }

    cout << ans << endl;



    
    
    
    return 0;
}
