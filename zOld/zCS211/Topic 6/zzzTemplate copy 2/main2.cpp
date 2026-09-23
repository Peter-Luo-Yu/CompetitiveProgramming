#include <bits/stdc++.h>
using namespace std;

map<int, vector<int>> arr;  // adj
map<int, vector<int>> rev;  // reverse adj
map<int, string> mp;         
map<int, int> dp;            

// dp[n] = number of favorable paths from n
int recurse(int n) {
    if (dp.count(n)) return dp[n]; 

    if (mp.count(n)) {
        dp[n] = (mp[n] == "favourably") ? 1 : 0;
        return dp[n];
    }

    int res = 0;
    for (int child : arr[n]) {
        res += recurse(child);
    }
    dp[n] = res;
    return dp[n];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;

        arr.clear(); rev.clear(); mp.clear(); dp.clear();

        for (int i = 0; i < n; i++) {
            int a, c, d; cin >> a;  
            string b; cin >> b;

            if (b != "favourably" && b != "catastrophically") {
                cin >> c >> d;
                arr[a] = {stoi(b), c, d};
                rev[stoi(b)].push_back(a);
                rev[c].push_back(a);
                rev[d].push_back(a);
            } else {
                mp[a] = b;
            }
        }

        cout << recurse(1) << endl;
    }

    return 0;
}
