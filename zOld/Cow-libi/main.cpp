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

    int G, N; cin >> G >> N;

    vector<vector<int>> grazing;
    vector<int> times; 
    for (int i = 0; i < G; i++){
        int x, y, t; cin >> x >> y >> t;    
        grazing.push_back({t, x, y});
    }
    sort(grazing.begin(), grazing.end());
    
    
    for (int i = 0; i < grazing.size(); i++){
        //cout << grazing[i][0] << " " << grazing[i][1] << " " << grazing[i][2] << endl;
        times.push_back(grazing[i][0]);
    }
    //print(times);

    int ans = 0;
    
    for (int i = 0; i < N; i++){
        int x, y, t; cin >> x >> y >> t;
        bool crime = true;

        int l = upper_bound(times.begin(), times.end(), t) - times.begin();
        
        //cout << "l: " << l << endl;

        ld dist1, time1, dist2, time2;

        if (l < G) {
            long long dx = x - grazing[l][1];
            long long dy = y - grazing[l][2];
            long long dt = abs(t - times[l]);

            if (dx * dx + dy * dy > dt * dt) {
                crime = false;
            }
        }

        if (l > 0){
            long long dx = x - grazing[l-1][1];
            long long dy = y - grazing[l-1][2];
            long long dt = abs(t - times[l-1]);

            if (dx * dx + dy * dy > dt * dt) {
                crime = false;
            }
        }
        
        if (!crime){
            ans++;
        }
    }   
    
    cout << ans << endl;


    return 0;
}