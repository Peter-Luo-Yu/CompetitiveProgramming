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

    ll t; cin >> t;
    while (t--) {
        ll n, m; cin >> n >> m;

        vector<ll> a(n), b(m);
        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < m; i++) cin >> b[i];

        sort (b.begin(), b.end());

        ll cur = min (a[0], b[0] - a[0]);
        
        //cout << "start: " << cur << endl;
        
        bool failed = false;

        for (int i = 1; i < n; i++) {
            // a[i] = b[j] - a[i] >= cur want this equal or greather than cur
            // search for b[j] >= cur + a[i];

            ll target = cur + a[i];
            
            //cout << "target: " << target << endl;

            ll idx = lower_bound(b.begin(), b.end(), target) - b.begin();
            

            if (idx >= m && a[i] < cur) {
                failed = true;
                break;
            }
            else {

                //cout << "found: " << b[idx] << endl;

                ll best = 1e9;
                
                if (a[i] >= cur) {
                    best = a[i];
                } 
                if (idx < m) {
                    best = min (best, (ll) b[idx] - (ll) a[i]);
                }

                //cout << "best: " << best << endl;

                if (best != 1e9 && best >= cur) {
                    cur = best;
                } else {
                    failed = true;
                    break;
                }



                //cout <<  "cur: " << cur << endl;
            }
        }
        

        if (failed) {
            cout << "NO" << endl;
        } else {
            cout << "YES" << endl;
        }

        //space;

    }

    
    return 0;
}
