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
    vector<pair<ll, ll>> arr (2 * n);
    for (int i = 0; i < n; i++) {
        ll a, b; cin >> a >> b;

        arr[2 * i] = {a, 0};
        arr[2 * i + 1] = {b, 1};
    }

    sort (arr.begin(), arr.end());
    //printP(arr);

    vector<ll> diff (2 * n), prefix (2 * n + 1);
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i].second == 0) {
            diff[i] = 1;
        } else {
            diff[i] = -1;
        }
    }
    for (int i = 1; i <= arr.size(); i++) {
        prefix[i] = prefix[i - 1] + diff[i - 1];
    }

    /*
    cout << "  ";
    print(diff); 
    print(prefix);
    cout << "  ";
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i].first << " ";
    } cout << endl;
    */

    vector<ll> ans (n + 1);
    for (int i = 1; i < prefix.size() - 1; i++) {
        //cout << prefix[i] << " " << arr[i].first << " " << arr[i - 1].first << " diff: " << diff[i] << endl;
        if (diff[i] == -1 && diff[i - 1] == 1) {
            ans[prefix[i]] += arr[i].first - arr[i - 1].first + 1;
        } else {
            ans[prefix[i]] += arr[i].first - arr[i - 1].first;
        }
    }

    //print(ans);

    for (int i = 1; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
    
    return 0;
}
