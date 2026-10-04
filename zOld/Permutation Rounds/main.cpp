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

    ll n; cin >> n;
    vector<ll> arr (n);
    for (ll i = 0; i < n; i++) {
        cin >> arr[i];
        arr[i]--;
    }

    vector<bool> vis (n);
    vector<ll> lens;

    for (ll i = 0; i < n; i++) {
        if (vis[i]) continue;

        ll len = 0;
        ll cur = arr[i];
        while (!vis[cur]) {
            vis[cur] = true;
            cur = arr[cur];
            len++;
        }
        lens.push_back(len);
        len = 0;
    }

    //print(lens);

    ll N = 2 * 1e5 + 5;
    vector<ll> spf (N);

    for (ll i = 0; i < N; i++) {
        spf[i] = i;
    }
    for (ll i = 2; i < N; i++) {
        if (spf[i] == i) {
            for (ll j = i * i; j < N; j += i) {
                if (spf[j] == j) {
                    spf[j] = i;
                }
            }
        }
    }

    //print(spf);

    map<ll, ll> factorization;

    for (ll i = 0; i < lens.size(); i++) {
        ll val = lens[i];

        while (val > 1) {
            ll factor = spf[val];
            ll exp = 0;

            while (val % factor == 0) {
                val /= factor;
                exp++;
            }

            factorization[factor] = max (factorization[factor], exp);
        }
    }

    //printP(factorization);

    ll ans = 1;
    ll MOD = 1e9 + 7;
    for (auto x : factorization) {
        for (ll i = 0; i < x.second; i++) {
            ans *= x.first;
            ans %= MOD;
        }
    }

    cout << ans << endl;

    return 0;
}
