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

    ll n, k; cin >> n >> k;

    vector<ld> arr (n);
    for (int i = 0; i < n; i++) {cin >> arr[i];}
    sort (arr.begin(), arr.end());

    ld sum = 0;
    ld sumSq = 0;
    ld avg;
    ld cost = 1e30;

    int l = 0, r = 0;

    while (r < n) {
        ld badness = 0;

        while (r - l < k) {
            sum += arr[r];
            sumSq += (arr[r] * arr[r]);
            r++;
        }

        // check
        //avg = (ld) sum / (ld) k;
        //cout << avg << endl;

        badness = sumSq - (sum * sum) / k;

        cost = min (cost, badness);
        // increment
        sum -= arr[l];
        sumSq -= (arr[l] * arr[l]);
        l++;
    }


    cout << setprecision(10) << cost << endl;

    return 0;
}