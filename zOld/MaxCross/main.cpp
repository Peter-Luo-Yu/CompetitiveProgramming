#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define endl "\n"
#define print(arr) for (auto x : arr) cout << x << ' '; cout << '\n';

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    freopen("maxcross.in", "r", stdin);
    freopen("maxcross.out", "w", stdout);

    int n, k, b; cin >> n >> k >> b;

    vector<int> broken (n);
    vector<int> prefix (n+1);

    for (int i = 0; i < b; i++){
        int pos; cin >> pos;
        broken[pos - 1]++;
    }

    for (int i = 0; i < n; i++){
        prefix[i+1] = prefix[i] + broken[i];
    }

    int Min = 1e9;
    //print(prefix);
    for (int i = 0; i <= n - k; i++){
        //cout << prefix[i + k] << " " << prefix[i] << " " << prefix[i + k] - prefix[i] << endl;
        Min = min (Min, prefix[i + k] - prefix[i]);
    }
    cout << Min << endl;
     

    return 0;
}