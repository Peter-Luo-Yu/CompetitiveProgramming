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
    set<int> unique;
    for (int i = 0; i < n; i++){
        int val; cin >> val;

        unique.insert(val);
    }

    int difficulty = unique.size();

    cout << min(difficulty, k) << endl;
    

    return 0;
}