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

struct point {
    int a; 
    int b;
};

bool custom (point one, point two) {
    if (one.a == two.a) {
        return one.b > two.b;
    }
    return one.a < two.a;
}


int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("mountains.in", "r", stdin);
    freopen("mountains.out", "w", stdout);
 
    ll n; cin >> n;
    vector<point> arr;
    for (int i = 0; i < n; i++) {
        ll a, b; cin >> a >> b;
        point pt;
        pt.a = a - b; pt.b = a + b;

        arr.push_back(pt);
    }

    //for (auto x : arr) cout << x.a << " " << x.b << endl;

    sort (arr.begin(), arr.end(), custom);

    //for (auto x : arr) cout << x.a << " " << x.b << endl;
    

    ll cnt = 0;
    ll l = 0, r = 0; 
    
    for (int i = 0; i < arr.size(); i++) {
        if (i == 0) {
            //l = arr[i][0];
            r = arr[i].b;
            cnt++;
            continue;
        }
       
        if (arr[i].b > r) {
            cnt++;
            r = arr[i].b;
        }
        
    }

    cout << cnt << endl;
    
    return 0;
}
