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
    cin.tie(0);

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int t; cin >> t;

    while (t--) {
        ll a, b, c1, c2, g;
        cin >> a >> b >> c1 >> c2 >> g;

        if (a >= g) {
            cout << 0 << endl;
        }
        else if (c2 > c1) {
            ll curExchanges = b / c2; 
            a += curExchanges * c1;
            b -= curExchanges * c2;

            if (a >= g) {
                cout << 0 << endl;
                continue;
            }

            //cout << "a: " << a << " b: " << b << " g: " << g << endl;

            ll ans = 0;

            ll cur = a;     

            ll exchangeNeeded =  (g - a) / c1 + ((g - a) % c1 != 0LL);
            ll get = exchangeNeeded * c2 - 1LL;

            //cout << "need: " << exchangeNeeded << " get to: " << get << endl;

            ans += get - b;

            cur += c1 * (get / c2);

            //cout << "cur: " << cur << endl;

            ans += g - cur;
            ans = max (ans, 0LL);
            cout << ans << endl;

        } else if (c2 == c1) {
            ll curExchanges = b / c2; 

            a += curExchanges * c1;
            b -= curExchanges * c2;

            if (a >= g) {
                cout << 0 << endl;
                continue;
            }

            ll exchangeNeeded = (g - a) / c1 + ((g - a) % c1 != 0LL);
            exchangeNeeded -= curExchanges;
            ll worst = exchangeNeeded * c2 + b - 1LL;

            //cout << "need: " << exchangeNeeded << " worst: " << worst << endl;

            ll ans = 0;
            ans += worst;

            ll cur = a;
            cur += c1 * (worst / c2);

            //cout << "cur: " << cur << endl;

            ans += g - cur;
            ans = max (ans, 0LL);

            cout << ans << endl;

            /*
            cout << "need: " << exchangeNeeded << " have: " << curExchanges << endl; 

            ll coins = (exchangeNeeded - curExchanges) * c2 - b;

            cout << "coins for ex: " << coins << endl;

            ll dist = g - a;

            ll ans = max (dist, coins);
            */
            
        } 
        else if (c2 < c1) {
            ll curExchanges = b / c2; 

            a += curExchanges * c1;
            b -= curExchanges * c2;

            if (a >= g) {
                cout << 0 << endl;
                continue;
            }
            

            ll dist = g - a;

            //cout << "dist: " << dist << " buf: " << (c2 - b) << endl;

            ll ans1 = (g - a) + (c2 - b) - 1LL;
            
            /*
            // suppose we make 1 exchange to free buffer
            ll ans2 = c2 - b;
            b = 0;
            a += c1;
            cout << "dist2: " << dist << " buf2: " << (c2 - b) << endl;
            ans2 += (g - a) + (c2 - b) - 1LL;
            */

            ans1 = max (ans1, 0LL);
            cout << ans1 << endl;
            
        }
        
    }
    

    return 0;
}