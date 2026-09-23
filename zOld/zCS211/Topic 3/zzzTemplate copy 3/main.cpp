#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define endl "\n"
#define print(arr) for (auto x : arr) cout << x << " "; cout << "\n";
#define print2d(arr) for (int i = 0; i < arr.size(); i++) {for (int j = 0; j < arr[i].size(); j++) {cout << arr[i][j] << " ";} cout << "\n";}
#define printG(adj) for (int i = 0; i < adj.size(); i++) {cout << "i: " << i << " | "; for (int j = 0; j < adj[i].size(); j++) {cout << adj[i][j] << " ";} cout << endl;}
#define printP(arr) for (auto x : arr) {cout << x.first << " " << x.second << "\n";}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    ll n, k; cin >> n >> k;

    if (n == 1 && k == 1) {
        cout << "N" << endl;
        return 0;
    } 
    if (n == 2 && k == 1) {
        cout << "A" << endl;
        return 0;
    }

    // lets try generating the fib sequence, I found 92 doesn't over flow it.
    // we only need up until 10^18

    vector<ll> fib;
    fib.push_back(1);
    fib.push_back(1);
    for (int i = 2; i < 92; i++) {  
        fib.push_back(fib[i - 1] + fib[i - 2]);
    }

    //print(fib);

    ll val = k;
    int pos = min (n - 1, 90LL);
    //cout << "start pos: " << pos << endl;
    while (pos > 1) {   
        //cout << "pos: " << pos << " val: " << val << " len: " << fib[pos] << endl;
        if (val <= fib[pos - 2]) {
            //cout << "c1" << endl;
            val = val;
            pos -= 2;
        } else {
            //cout << "c2" << endl;
            val = val - fib[pos - 2]; 
            pos -= 1; 
        }
    }
    
    //cout << "fpos: " << pos << " fval: " << val << " flen: " << fib[pos] << endl;

    if (pos == 0) {
        cout << "N" << endl;
    } else {
        cout << "A" << endl;
    }
    
    return 0;
}
