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

    int n, m, k; cin >> n >> m >> k;
    vector<int> people (n);
    vector<int> apart (m);
    for (int i = 0; i < n; i++) cin >> people[i];
    for (int i = 0; i < m; i++) cin >> apart[i];

    sort (people.begin(), people.end());
    sort (apart.begin(), apart.end());

    //print(people); print(apart);

    int apart_idx = 0, people_idx = 0; 
    int ans = 0;
    
    while (people_idx < n && apart_idx < m) {
        if (abs(people[people_idx] - apart[apart_idx]) <= k) {
            ans++;
            people_idx++;
            apart_idx++;
        }
        else if (people[people_idx] > apart[apart_idx]) {
            apart_idx++;
        } 
        else {
            people_idx++;
        }
    }

    cout << ans << endl;


    return 0;
}
