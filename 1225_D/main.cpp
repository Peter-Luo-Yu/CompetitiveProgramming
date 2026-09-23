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

    int n, k; cin >> n >> k;

    int N = 1e5 + 5;
    vector<int> spf (N);

    for (int i = 0; i < N; i++) {
        spf[i] = i;
    }

    for (int i = 2; i * i < N; i++) {
        if (spf[i] == i) {
            for (int j = i; j < N; j += i) {
                if (spf[j] == j) {
                    spf[j] = i;
                }
            }
        }
    }

    //print(spf);

    map<int, int> seen;
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        int val; cin >> val;

        if (val == 1) {
            // we know the complement of 1 is always 1
            //cout << "one" << endl;
            ans += seen[1];
            seen[1]++;
            //space;
            continue;
        }

        int comp = 1;
        int reduced = 1;
        while (val > 1) {
            int factor = spf[val];

            int exp = 0;
            while (val % factor == 0) {
                val /= spf[val];
                exp++;
            }

            //cout << "factor: " << factor << " exp: " << exp << endl;
            
            int reduce_exp = exp % k;
            //cout << "reduce exp: " << reduce_exp << " reduce val: " << pow(factor, reduce_exp) << endl;
            reduced *= pow(factor, reduce_exp);


            int comp_exp = (k - reduce_exp) % k;
            //cout << "comp exp: " << comp_exp << " comp val: " << pow(factor, comp_exp) << endl;
            comp *= pow(factor, comp_exp);

        }

        //cout << "final reduce: " << reduced << " final comp: " << comp << endl;

        ans += seen[comp];
        seen[reduced]++;

        //space;
    }

    cout << ans << endl;

    return 0;
}
