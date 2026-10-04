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

    int a, b, c; cin >> a >> b >> c;

    vector<int> usb; vector<int> ps2;

    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        int price; string type;
        cin >> price >> type;
        if (type == "USB") {
            usb.push_back(price);
        } else {
            ps2.push_back(price);
        }
    }

    sort (usb.begin(), usb.end());
    sort (ps2.begin(), ps2.end());

    ll cnt = 0, cost = 0;

    for (int i = 0; i < min(a, (int) usb.size()); i++) {
        cost += usb[i]; cnt++;
    }
    for (int i = 0; i < min(b, (int) ps2.size()); i++) {
        cost += ps2[i]; cnt++;
    }

    vector<int> remain;
    for (int i = min(a, (int) usb.size()); i < usb.size(); i++) remain.push_back(usb[i]);
    for (int i = min(b, (int) ps2.size()); i < ps2.size(); i++) remain.push_back(ps2[i]);

    sort (remain.begin(), remain.end());

    for (int i = 0; i < min(c, (int) remain.size()); i++) {
        cost += remain[i]; cnt++;
    }
    
    cout << cnt << " " << cost << endl;

    return 0;
}
