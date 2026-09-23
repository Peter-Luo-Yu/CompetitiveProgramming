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

    freopen("rental.in", "r", stdin);
    freopen("rental.out", "w", stdout);

    int n, m, r; cin >> n >> m >> r;

    vector<int> cows (n), rent (r);
    vector<pair<int, int>> shops (m);

    for (int i = 0; i < n; i++) cin >> cows[i];
    for (int i = 0; i < m; i++) cin >> shops[i].second >> shops[i].first;
    for (int i = 0; i < r; i++) cin >> rent[i];

    sort (cows.begin(), cows.end()); reverse (cows.begin(), cows.end());
    sort (rent.begin(), rent.end()); reverse (rent.begin(), rent.end());
    sort (shops.begin(), shops.end()); reverse (shops.begin(), shops.end());

    //print(cows);
    //print(rent);
    //printP(shops);

    int cow_idx = 0, rent_idx = 0, shop_idx = 0;
    ll ans = 0;

    while (cow_idx < n) {
        int gallons = cows[cow_idx];
   
        int money = 0;
        int cur = shop_idx;
        int remain = 0;


        while (cur < m) {
            int cur_gal = min (gallons, shops[cur].second);
            money += cur_gal * shops[cur].first;
            gallons -= cur_gal;

            if (gallons == 0) {
                remain = shops[cur].second - cur_gal;
                break;
            } else {
                cur++;
            }
        }

        //cout << money << endl;

        if (rent_idx >= r || money >= rent[rent_idx]) {       // sell the cow's milk
            ans += money;
            shop_idx = cur;

            if (shop_idx < m) {
                shops[shop_idx].second = remain;
            }
    
            cow_idx++;

        } else {
            ans += rent[rent_idx];
            n--;
            rent_idx++;
        }

    }

    cout << ans << endl;

    return 0;
}
