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
        int n, m, L; cin >> n >> m >> L;

        vector<pair<int, int>> hurdles;
        for (int i = 0; i < n; i++){
            int a, b; cin >> a >> b;
            hurdles.push_back({a,b});
        }
        sort (hurdles.begin(), hurdles.end());
        hurdles.push_back({1e9, 1e9 + 1});

        int idx = 0;

        vector<vector<int>> pups; 
        vector<int> temp;

        bool first_inc = true;

        for (int i = 0; i < m; i++){
            //cout << "cur: " << hurdles[idx].first  << endl;
            int a, b; cin >> a >> b;

            if (a < hurdles[idx].first){
                first_inc = false;

                temp.push_back(b);
            }
            else {

                if (temp.size() > 0){
                    
                    sort (temp.begin(), temp.end());
                    pups.push_back(temp);
                    temp.clear();
                }

                int num_increments = 0;
                while (a > hurdles[idx].first){
                    idx++; num_increments++;
                }

                //cout << "numincrement: " << num_increments << endl;
                
                for (int i = 0; i < num_increments - 1; i++){
                    pups.push_back({-1});
                }

                if (first_inc){     // f**ing offset
                    pups.push_back({-1});
                    first_inc = false;
                }
            

                temp.push_back(b);
            }
            //cout << "temp: "; print(temp);
            //cout << "cur: " << hurdles[idx].first << endl;
        }
        sort (temp.begin(), temp.end());
        pups.push_back(temp);
        
        while (pups.size() < hurdles.size() - 1){
            pups.push_back({-1});
        }

        /*
        for (auto x : hurdles){
            cout << x.first << " " << x.second << endl;
        } cout << endl;

        cout << "pups: " << endl;
        for (int i = 0; i < pups.size(); i++){
            for (int j = 0; j < pups[i].size(); j++){
                cout << pups[i][j] << " ";
            }
            cout << endl;
        } 
        */

        int ans = 0; bool failed = false;
        int cur = 1;
        vector<int> pup_pool;

        for (int i = 0; i < hurdles.size() - 1; i++){
            int cost = hurdles[i].second - hurdles[i].first + 2;
            //cout << "i: " << i << " cost: " << cost << endl;

            for (int j = 0; j < pups[i].size(); j++){
                pup_pool.push_back(pups[i][j]);
            }   
            sort (pup_pool.begin(), pup_pool.end());

            //cout << "i: " << i << " pup_pool: "; print(pup_pool);

            while (!pup_pool.empty()){
                if (pup_pool.back() == -1) break;

                if (cur >= cost) break;

                cur += pup_pool.back();
                pup_pool.pop_back();
                ans++;

                
            }

            if (cur < cost){
                failed = true;
            }
        }

        //cout << "ans: ";
        if (failed){
            cout << -1 << endl;
        } else {
            cout << ans << endl;
        }

        //cout << "-------" << endl;
    
    }
    

    return 0;
}