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

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;

        vector<ll> a(n), b(n);
        map<pair<ll, ll>, ll> pos; // pair -> position
        map<ll, pair<ll, ll>> arr; // position -> pair

        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < n; i++) cin >> b[i];

        for (int i = 0; i < n; i++) {
            pos[{a[i], b[i]}] = i;
            arr[i] = {a[i], b[i]};
        }

        /*
        for (auto x : pos) {
            cout << x.first.first << " " << x.first.second << " " << x.second << endl;
        } */

        bool failed = false;
        vector<pair<ll, ll>> ans;

        if (n % 2 == 1) {
            bool mid_placed = false;

            for (int i = 0; i < n/2; i++) {
                ll pa = arr[i].first;
                ll pb = arr[i].second;

                if (pa == pb) {
                    if (!mid_placed) { // then place it in the middle, otherwise it will auto matically be in mid

                        // cur pos = i, swap pos = n / 2

                        ll tempa = arr[n/2].first, tempb = arr[n/2].second;

                        arr[n/2] = {pa, pb};
                        arr[i] = {tempa, tempb};

                        pos[{pa, pb}] = n/2;
                        pos[{tempa, tempb}] = i;

                        mid_placed = true;

                        ans.push_back({i, n/2});
                    }
                    else {
                        failed = true;
                        break;
                    }
                    i--;
                } else {
                    if (pos.count({pb, pa}) == 0) {
                        failed = true;
                        break;
                    }

                    // swapping {pb, pa} with what is in goal pos = n - 1 - i;
                    ll curpos = pos[{pb, pa}];

                    if (curpos != n - 1 - i) {

                        ll tempa = arr[n - 1 - i].first, tempb = arr[n - 1 - i].second;

                        arr[n - i - 1] = {pb, pa};
                        arr[curpos] = {tempa, tempb};

                        pos[{pb, pa}] = n - 1 - i;
                        pos[{tempa, tempb}] = curpos;

                        ans.push_back({curpos, n - 1 - i});
                    }
                }
            }

        } else {
            for (int i = 0; i < n/2; i++) {
                ll pa = arr[i].first;
                ll pb = arr[i].second;

                if (pa == pb) {
                    failed = true;
                    break;
                }

                if (pos.count({pb, pa}) == 0) {
                    failed = true;
                    break;
                }

                // swapping {pb, pa} with what is in goal pos = n - 1 - i;
                ll curpos = pos[{pb, pa}];

                if (curpos != n - 1 - i) {

                    ll tempa = arr[n - 1 - i].first, tempb = arr[n - 1 - i].second;

                    arr[n - i - 1] = {pb, pa};
                    arr[curpos] = {tempa, tempb};

                    pos[{pb, pa}] = n - 1 - i;
                    pos[{tempa, tempb}] = curpos;

                    ans.push_back({curpos, n - 1 - i});
                }
            
            }
        }

        if (failed) {
            cout << -1 << endl;
        } else {
            cout << ans.size() << endl;
            for (auto x : ans) {
                cout << x.first + 1 << " " << x.second + 1 << endl;
            }
        }

        //space;
    }


    return 0;
}
