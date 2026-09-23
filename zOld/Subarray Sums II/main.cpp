#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl "\n"
#define print(arr) for (auto x : arr) cout << x << ' '; cout << '\n';

int main() {

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n, x; cin >> n >> x;

    vector<ll> prefix (n+1);
    map<ll, ll> prefix_count;

    ll count = 0;

    prefix_count[0] = 1;

    for (int i = 0; i < n; i++){
        ll val; cin >> val;

        prefix[i+1] = prefix[i] + val;          // basically prefix j (note: j - i = x)

        count += prefix_count[prefix[i+1] - x]; // check if there exists a prefix i = prefix j - x

        prefix_count[prefix[i+1]]++;            




        //cout << prefix[i+1] << " " << prefix_count[prefix[i+1]] << endl;
    }

    cout << count << endl;

    return 0;
}