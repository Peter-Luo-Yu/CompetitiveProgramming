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

    int nr, ng, nb; cin >> nr >> ng >> nb; // need
    int Or, og, ob; cin >> Or >> og >> ob; // own

    int x1, x2; cin >> x1 >> x2;            // buy

    int r = nr - Or;    
    int g = ng - og;
    int b = nb - ob;

    //cout << r << " " << g << " " << b << endl; 
 
    if (r > 0){
        x1 -= r;
    }
    if (b > 0){
        x2 -= b;
    }

    int left = x1 + x2;
    
    //cout << x1 << " " << x2 << " " << left << endl; 

    if (x1 < 0 || x2 < 0 || left < g){
        cout << -1 << endl;
    } else {
        int ans = 0;
        if (r > 0) {ans += r;} 
        if (b > 0) {ans += b;}
        if (g > 0) {ans += g;}

        cout << ans << endl;
    }
    

    return 0;
}