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
    map <string, pair<int, int>> mp;

    for (int i = 0; i < n; i++) {
        string s; int x, y;
        cin >> s >> x >> y;

        mp[s] = {x, y};
    }   


    int xcor = -1e9, ycor = -1e9;
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        //cout << s << endl;

        if (xcor == -1e9) {
            xcor = mp[s].first;
            ycor = mp[s].second;
        } else {
            
            ans += (abs(mp[s].first - xcor) + abs(mp[s].second - ycor));
            xcor = mp[s].first;
            ycor = mp[s].second;
        }

        
    }
    
    cout << ans << endl;
    
    return 0;
}
