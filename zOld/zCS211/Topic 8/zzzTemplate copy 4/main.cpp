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

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    ll n; cin >> n;
    ll len = 0; cin >> len; 

    priority_queue<ll> pq;
    pq.push(len);
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        ll val; cin >> val;

        ll longest = pq.top();
        pq.pop();

        //cout << longest << endl;

        if (val > longest) break;

        if (longest % 2 == 0) {
            if (val % 2 == 0) {
                pq.push(longest/2 - val/2);
                pq.push(longest/2 - val/2);

                //cout << "1: " << longest/2 - val/2 << " " << longest/2 - val/2 << endl;
            } else {
                pq.push(longest/2 - (val/2) - 1);
                pq.push(longest/2 - (val/2));

                //cout << "2: " << longest/2 - (val/2) <<  " " << longest/2 - val/2 - 1 << endl;
            }
        } else {
            if (val % 2 == 0) {
                pq.push((longest/2) + 1 - (val/2));
                pq.push(longest/2 - (val/2));

                //cout << "3: " << longest/2 + 1 - val/2 << " " << longest/2 - (val/2) << endl;
            } else {
                pq.push(longest/2 - val/2);
                pq.push(longest/2 - val/2);
                
                //cout << "4: " << longest/2 - val/2 << " " << longest/2 - val/2 << endl;
            }   
        }
        ans++;
        
    }
    
    cout << ans << endl;
   

    
    return 0;
}
