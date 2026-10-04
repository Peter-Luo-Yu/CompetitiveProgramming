#pragma GCC optimize("O3,unroll-loops")

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

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM =
            chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int t; cin >> t;

    while (t--) {
        int n; cin >> n;
        //vector<ll> arr (n);
        //for (int i = 0; i < n; i++) cin >> arr[i];

        // instead of tracking all values reached by element,
        // we simply track for each reachable number, how many elements actually reach it

        // freq: reach - number of elements, cost: reach - operations;

        unordered_map<ll, pair<ll, ll>, custom_hash> mp; 
        mp.reserve(n * 40);

        for (int i = 0; i < n; i++) {
            //unordered_set<ll, custom_hash> unique;

            ll cur, c = 0;
            cin >> cur;

            bool hit_one = false, hit_two = false;

            while (!(hit_one && hit_two)) {
                if (cur == 1) hit_one = true;
                if (cur == 2) hit_two = true;

                /*
                if (freq.count(cur) == 0) {
                    freq[cur] = 0;
                    cost[cur] = 0;
                } */

                mp[cur].first++;
                mp[cur].second += c;  
                
                //unique.insert(cur);

                if (cur & 1) {
                    cur += 1;
                } else {
                    cur >>= 1;
                }

                c += 1;
            } 

        }

        //printP(freq); space;
        //printP(cost); space; 

        ll ans = 1e18;

        // first = key, second = pair<ll, ll>
        for (auto x : mp) {
            if (x.second.first == n) {
                ans = min (ans, x.second.second);
            }
        }

        cout << ans << endl;

        //space;
    }


    return 0;
}
