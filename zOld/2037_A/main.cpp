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
        int n; cin >> n;
        vector<int> arr (n); 
        for (int i = 0; i < n; i++) {cin >> arr[i];}

        map<int, int> mp;
        for (int i = 0; i < n; i++) {
            mp[arr[i]]++;
        }   

        int score = 0;

        for (auto x : mp){
            //cout << x.first << " " << x.second << endl;
            score += x.second/2;
        }
        cout << score << endl;

    }
    

    return 0;
}