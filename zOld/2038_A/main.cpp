#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define endl "\n"
#define print(arr) for (auto x : arr) cout << x << ' '; cout << '\n';

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n, k; cin >> n >> k;
    vector<int> a(n), b(n); // a is reward, b is wage

    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];

    vector<int> ans (n);

    int cur = 0;
    for (int i = n - 1; i >= 0; i--){
        int left = k - cur;

        //cout << "left: " << left << " " << a[i]/b[i] << endl;

        if (a[i]/b[i] <= left) {
            cur += a[i]/b[i];
            ans[i] = a[i]/b[i];
        }
        else {
            
            cur += left;
            ans[i] = left;

            //cout << "final remanining hours: " << left << endl;
        }

        if (cur >= k){
            break;
        }
    }

    if (cur < k){
        for (int i = 0; i < n; i++){
            cout << 0 << " ";
        }
    } else {
        print(ans);
    }

    

    return 0;
}