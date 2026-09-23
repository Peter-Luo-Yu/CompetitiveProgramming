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
        int n, k; cin >> n >> k;

        map <int, int> mp;

        for (int i = 0; i < k; i++){
            int b, c; cin >> b >> c;

            mp[b] += c;
        }

        vector<int> profits;
        for (auto x : mp){
            profits.push_back(x.second);
        }
        sort (profits.begin(), profits.end()); 

        int used = 0; 
        int ans = 0;
        for (int i = profits.size() - 1; i >= 0; i--){
            if (used < n){
                used++;
                ans += profits[i];
            }
           
        }
        cout << ans << endl; 
    }    

    return 0;
}