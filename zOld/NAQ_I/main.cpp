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

    int n; cin >> n;

    vector<ll> more (n);
    vector<ll> members (n);
    for (int i = 0; i < n; i++) {cin >> more[i];}
    for (int i = 0; i < n; i++) {cin >> members[i];}
    sort (members.begin(), members.end());
    reverse(members.begin(), members.end());

    ld maxAvg = 0.0; 
    ld runningSum = 0.0;
    for (int i = 0; i < n; i++){
        runningSum += members[i];
        ld avg = (runningSum + more[i])/(i+1);
        //cout << avg << endl;
        maxAvg = max (maxAvg, avg);
    }

    cout << setprecision(20) << maxAvg << endl;

    

    return 0;
}