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

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        
        map<int, int> freqA, freqB;

        for (int i = 0; i < n; i++) {
            int val; cin >> val;
            freqA[val]++;
        }        
        
        // first promote, then distribute
        for (auto x : freqA) {
            if (x.first == freqA.rbegin() -> first) break;
            
            if (x.second > 2) {
                int numPromoted = x.second - 2;
                
                freqA[x.first] = 1;
                freqB[x.first] += 1;

                freqA[x.first + 1] += numPromoted;

                //cout << "test: " << x.first + 1 << " " << freqA[x.first + 1] << endl;

                if (freqA[x.first + 1] % 2 != 0) {

                } else {
                    int amt = freqA[x.first + 1];
                    //cout << "amt: " << amt << endl;
                    freqA[x.first + 1] = amt/2;
                    freqB[x.first + 1] = amt/2;
                }
            } 
            
            //cout << "A: " << endl; printP(freqA); 
            //cout << "B: " << endl; printP(freqB); space;
        }


        for (auto x : freqA) {
            if (x.second == 2) {
                int amt = freqA[x.first];
                    
                freqA[x.first] = amt/2;
                freqB[x.first] = amt/2;
            }
        }


        bool failed = false;

        for (auto x : freqA) {
            if (x.second != freqB[x.first]) {
                failed = true;
            }
        }

        if (failed) {
            cout << "NO" << endl;
        } else {
            cout << "YES" << endl;
        }
        


        //cout << "=========" << endl;
    }


    return 0;
}
