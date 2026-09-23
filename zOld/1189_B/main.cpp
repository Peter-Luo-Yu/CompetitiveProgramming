#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define endl "\n"
#define print(arr) for (auto x : arr) cout << x << " "; cout << "\n";
#define print2d(arr) for (int i = 0; i < arr.size(); i++) {for (int j = 0; j < arr[i].size(); j++) {cout << arr[i][j] << " ";} cout << "\n";}
#define printG(adj) for (int i = 0; i < adj.size(); i++) {cout << "i: " << i << " | "; for (int j = 0; j < adj[i].size(); j++) {cout << adj[i][j] << " ";} cout << endl;}
#define printP(arr) for (auto x : arr) {cout << x.first << " " << x.second << "\n";}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n; cin >> n;
    vector<ll> arr (n);
    for (int i = 0; i < n; i++) {cin >> arr[i];}

    sort (arr.begin(), arr.end());

    //print(arr);

    
    int idx = n - 1;
    vector<int> ans (n, -10);
    int l = n/2 - 1;
    int r = n/2 + 1;

    ans[n/2] = arr[idx]; idx--;
    //cout << l << " " << r << endl;

    while (l >= 0 && r <= n - 1) {
        //cout << "hi: " << arr[idx] << endl;
        if (l < 0) {
            break;
        }
        ans[l] = arr[idx];
        idx--;
        if (r > n - 1) {
            break;
        }
        ans[r] = arr[idx];
        idx--;
        l--; r++;
    }

    if (ans[0] == -10) {
        ans[0] = arr[0];
    } else if (ans[n - 1] == -10) {
        ans[n - 1] = arr[0];
    }
    
    //print(ans);

    bool failed = false;
    int before, after;
    for (int i = 0; i < n; i++) {
        //cout << "i: " << i << " arr: " << ans[i] << endl;
        if (i == 0) {
            before = ans[n-1];
            after = ans[1];
        } else if (i == n-1) {
            before = ans[n-2];
            after = ans[0];
        } else {
            before = ans[i - 1];
            after = ans[i + 1];
        }
        //cout << "arr: " << ans[i] << " sum: " << before +  after << endl;
        if (ans[i] >= before + after) {
            failed = true;
        }
    }

    if (failed) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
        print(ans);
    }
    

    
    
    
    return 0;
}
