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

    int years, m; cin >> years >> m;

    vector<ll> age (41);
    for (int i = 0; i < m; i++) {
        int dino; cin >> dino;
        age[dino]++;
    }

    //print(age);
    
    for (int y = 0; y < years; y++) {
        // increase age by 1
        for (int i = 39; i >= 0; i--) {
            age[i + 1] = age[i];
        }
        //print(age);

        ll adults = 0;
        for (int i = 10; i < 41; i++) {
            adults += age[i];
        }

        //cout << "adults: " << adults << endl;

        age[0] = adults/2;
    }


    ll ans = 0;
    for (auto a : age) {
        ans += a;
    }
   
    cout << ans << endl;


    return 0;
}
