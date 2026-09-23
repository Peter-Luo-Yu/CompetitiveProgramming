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

int n;
vector<int> perm;
vector<bool> chosen;

vector<int> height, stall;

ll ans = 0;

void recurse () {
    if (perm.size() == n) {
        //print(perm);
        
        bool failed = false;

        for (int i = 0; i < n; i++) {
            if (height[perm[i]] > stall[i]) {
                failed = true;
                break;
            }
        }

        if (!failed) {
            ans++;
        }
        
        return;
    }

    for (int i = 0; i < n; i++) {
        if (!chosen[i]) {
            perm.push_back(i);
            chosen[i] = true;
            recurse();

            perm.pop_back();
            chosen[i] = false;
        }
    }
    return;
}



int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    cin >> n;
    
    height = vector<int> (n);
    stall = vector<int> (n);

    for (int i = 0; i < n; i++) cin >> height[i];
    for (int i = 0; i < n; i++) cin >> stall[i];

    chosen = vector<bool> (n);
    
    recurse();

    cout << ans << endl;

    return 0;
}
