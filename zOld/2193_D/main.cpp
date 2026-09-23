#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define endl "\n"
#define print(arr) for (auto x : arr) cout << x << ' '; cout << '\n';
#define print2d(arr) for (int i = 0; i < arr.size(); i++) {for (int j = 0; j < arr[i].size(); j++) {cout << arr[i][j] << " ";} cout << "\n";}
#define printG(adj) for (int i = 0; i < adj.size(); i++) {cout << "i: " << i << " | "; for (int j = 0; j < adj[i].size(); j++) {cout << adj[i][j] << " ";} cout << endl;}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> a(n), b(n);

        for (int i = 0; i < n; i++) {cin >> a[i];}
        for (int i = 0; i < n; i++) {cin >> b[i];}

        sort (a.begin(), a.end()); reverse (a.begin(), a.end());
        

        ll score = 0LL;
        ll need = 0LL;
        ll levels = 0LL;

        //cout << "a: "; print(a);
        //cout << "b: "; print(b);
        
        for (int i = 0; i < n; i++) {
            //cout << b[i] << endl;
            
            if (need + b[i] <= n) {
                //cout << "b[i]:" << b[i] << endl;
                levels++;
                need += b[i];
                //cout << "need: " << need << " diffi: " << a[need - 1] << " levels: " << levels << endl;

                ll newScore = (ll) a[need - 1] * levels;
                score = max (score, newScore);
            } else {
                break;
            }
            
        }
        //cout << "ans: ";
        cout << score << endl;
        //cout << "---------" << endl;
    }
    

    return 0;
}