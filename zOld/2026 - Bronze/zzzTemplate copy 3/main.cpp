#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define endl "\n"
#define print(arr) for (auto x : arr) cout << x << ' '; cout << '\n';
#define print2d(arr) for (int i = 0; i < arr.size(); i++) {for (int j = 0; j < arr[i].size(); j++) {cout << arr[i][j] << " ";} cout << "\n";}
#define printG(adj) for (int i = 0; i < adj.size(); i++) {cout << "i: " << i << " | "; for (int j = 0; j < adj[i].size(); j++) {cout << adj[i][j] << " ";} cout << endl;}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    ll n, q; cin >> n >> q;
    vector<ll> arr (n); 
    for (int i = 0; i < n; i++) {cin >> arr[i];}

    vector<ll> pow2 (32);
    ll val = 1;
    for (int i = 0; i < min (n, 32LL); i++) {
        pow2[i] = val; val *= 2LL;
    }

    //print(arr);
    //print(pow2);

    vector<pair<ld, int>> deals (min (n, 32LL));    // deal -- arr idx
    for (int i = 0; i < min (n, 32LL); i++) {
        ld temp = (ld) arr[i] / (ld) pow2[i];
        //cout << temp << endl;
        deals[i] = {temp, i};
    }
    sort (deals.begin(), deals.end());

    /*
    cout << "DEALS: " << endl;
    for (int i = 0; i < min (n, 32LL); i++) {
        cout << deals[i].first << " " << deals[i].second << endl;
    } cout << endl;
    */

    vector<pair<ll, ll>> best (min (n, 32LL));    // amount -- arr idx
    for (int i = 0; i < deals.size(); i++) {
        best[i] = {pow2[deals[i].second], deals[i].second};
    }

    /*
    cout << "BEST: " << endl;
    for (auto x : best) {
        cout << x.first << " " << x.second << endl;
    } cout << endl;
    */
    
    while (q--) {
        ll a; cin >> a; //cout << "a: " << a << endl;

        vector<ll> costs; 
        ll cost2 = 1e18;
        for (int i = 0; i < n; i++) {
            if (i > 32 || best[i].first > a) {
                cost2 = min (cost2, arr[best[i].second]);
            }
        }
        costs.push_back(cost2);


        ll cost1 = 0;
        while (a > 0) {
            ll amount = 0;
            int idx = 0;
            for (int i = 0; i < best.size(); i++) {
                if (a >= best[i].first) {
                    amount = (ll) a / (ll) best[i].first; 
                    idx = i;
                    break;
                }
            }

            a -= amount * best[idx].first;
            //cout << "idx: " << idx << " amount: " << amount << " new a: " << a << endl;

            cost1 += amount * arr[best[idx].second];
            //cout << " unit: " << arr[best[idx].second] << endl;


            ll tempCost = 1e18;
            for (int i = 0; i < min(n, 32LL); i++) {
                if (best[i].first > a) {
                    tempCost = min (tempCost, arr[best[i].second]);
                }
            }
            ll temp = tempCost + cost1;
            costs.push_back(temp);
            
        }
        
        costs.push_back(cost1);
        sort (costs.begin(), costs.end());
        //print(costs);

        ll ans = costs[0];
        cout  << ans << endl;
    }
        
    
    

    return 0;
}