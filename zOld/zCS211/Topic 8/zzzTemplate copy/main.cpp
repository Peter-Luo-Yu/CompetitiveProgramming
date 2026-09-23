#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define lll __int128
#define ld long double
#define endl "\n"
#define print(arr) for (auto x : arr) cout << x << " "; cout << "\n";
#define print2d(arr) for (int i = 0; i < arr.size(); i++) {for (int j = 0; j < arr[i].size(); j++) {cout << arr[i][j] << " ";} cout << "\n";}
#define printG(adj) for (int i = 0; i < adj.size(); i++) {cout << "i: " << i << " | "; for (int j = 0; j < adj[i].size(); j++) {cout << adj[i][j] << " ";} cout << endl;}
#define printP(arr) for (auto x : arr) {cout << x.first << " " << x.second << "\n";}
#define space cout << "---------" << endl;


// Video Tutorial: https://www.youtube.com/watch?v=RPeFsb47Qps

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    ll n, c; cin >> n >> c;

    vector<ll> t(n), d(n);
    
    for (int i = 0; i < n; i++) {
        cin >> t[i] >> d[i];
    }

    //print(t); print(d); space;

    ll l = 0, r = 1e18;
    ll ans = 2e18;
    while (l <= r) {
        ll mid = (l + r)/2LL; // the k value

        //cout << "mid: " << mid << endl;

        lll effort = 0;

        vector<ll> research(n), work(n);

        for (int i = 0; i < n; i++) {
            research[i] = min(mid + 1, t[i]/d[i] + (t[i] % d[i] != 0));
            work[i] = max(0LL, t[i] - research[i] * d[i]);
            effort += research[i] + work[i];
        }

        lll lastDay = 0;

        for (int i = 0; i < n; i++) {
            if (research[i] == mid + 1) {
                lastDay += (1 + work[i]);
            }
        }

        //cout << "research: "; print(research); cout << "work: "; print(work);
        //cout << "total: " << (ll) effort << " last: " << (ll) lastDay << endl;

        lll cap = (lll) c * (mid + 1);

        if (effort <= cap && lastDay <= c) {
            ans = mid;
            r = mid - 1;
            //cout << "decreasing!" << endl;
        } else {
            l = mid + 1;
            //cout << "increasing!" << endl;
        }

        
    }


    cout << ans << endl;
    

    return 0;
}
