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

    int N = 1e6 + 5;
    vector<bool> sieve(N, true);
    sieve[0] = sieve[1] = false;
    for (int i = 2; i * i <= N; i++) {
        for (int j = 2 * i; j <= N; j+=i) {
            sieve[j] = false;
        }
    } 
    //print(sieve);

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;

        vector<int> divisors;

        for (int i = 1; i * i <= n; i++) {
            if (n % i == 0) {
                if (i != 1) {
                    divisors.push_back(i);
                }

                int otherdiv = n / i;
                if (i != otherdiv) {
                    divisors.push_back(otherdiv);
                }
            }
        }

        sort (divisors.begin(), divisors.end());
        //print(divisors);

        int ans = 0;

        vector<bool> vis (divisors.size());
        for (int i = 0; i < divisors.size(); i++) {
            if (sieve[divisors[i]]) {
                ans++;
                vis[i] = true;
            }
        }

        vector<int> cur;
        for (int i = 0; i < divisors.size(); i++) {
            if (vis[i]) continue;

            cur.push_back(divisors[i]);
            vis[i] = true;
            ans++;
            for (int j = i + 1; j < divisors.size(); j++) {
                if (vis[j]) continue;

                int next = divisors[j];

                bool good = true;

                for (int k = 0; k < cur.size(); k++) {
                    if (next % cur[k] == 0) {
                        good = false;
                        break;
                    }
                }

                if (good) {
                    cur.push_back(next);
                    vis[j] = true;
                }
            }

            //cout << "cur: "; print(cur);

            cur.clear();
        
        }

        cout << ans << endl;


        //space;

    }


    return 0;
}
