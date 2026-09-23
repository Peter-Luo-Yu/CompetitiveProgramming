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

    int t; cin >> t;
    while (t--){
        int n, m, L;
        cin >> n >> m >> L;
        vector<pair<int, int>> h(n);

        for (int i = 0; i < n; i++){
            int l, r; cin >> l >> r;
            h[i] = {l, r};
        }

        vector<pair<int, int>> p(m);
        for (int i = 0; i < m; i++){
            int x, v; cin >> x >> v;
            p[i] = {x, v};
        }

        int ans = 0;
        int jump = 1; 
        priority_queue<int> pq;

        int idx = 0; bool failed = false;

        for (int i = 0; i < n; i++){    // looping through hurdles (and checking if we can cross)
            int l = h[i].first;      // l stands for location of hurdle
            int dist = h[i].second - h[i].first + 2; // min dist to the hurdle

            while (idx < m && p[idx].first < l){      // find all powerups before the hurdle (and sort - done automatically by the priority queue)
                pq.push(p[idx].second);
                idx++;
            }

            while (jump < dist && !pq.empty()){       // greedily consume the most potent powerups first to minimize the number of powerups used
                jump += pq.top();
                pq.pop(); 
                ans++;
            }

            if (pq.empty() && jump < dist){
                failed = true;
                break;
            }
        }

        if (failed) cout << -1 << endl;
        else cout << ans << endl;
    }


    return 0;

}