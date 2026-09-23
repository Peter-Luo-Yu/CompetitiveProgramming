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
        int n, m, k; cin >> n >> m >> k;

        vector<int> tables (m);

        string s; cin >> s;

        map<char, int> freq;

        for (int i = 0; i < n; i++) {
            if (s[i] == 'E') {
                freq['E']++;
            }
            if (s[i] == 'A') {
                freq['A']++;
            } 
            if (s[i] == 'I') {
                freq['I']++;
            }
        }

        //printP(freq);

        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == 'E') { // find first non empty
                for (int j = 0; j < m; j++) {
                    if (tables[j] > 0 && tables[j] + 1 <= k) {
                        tables[j]++;
                        ans++;
                        freq['E']--;
                        break;
                    }
                }
            }
            if (s[i] == 'I') {
                for (int j = 0; j < m; j++) {
                    if (tables[j] == 0) {
                        tables[j]++;
                        ans++;
                        freq['I']--;
                        break;
                    }
                }
            }
            if (s[i] == 'A') {
                bool placed = false;

                if (freq['I'] == 0) {
                    //cout << "c1" << endl;
                    for (int j = 0; j < m; j++) { 
                        if (tables[j] == 0) {
                            tables[j]++;
                            ans++; 
                            freq['A']--;
                            placed = true;
                            break;
                        }
                    }
                } else {
                    //cout << "c2" << endl;
                    for (int j = 0; j < m; j++) {
                        if (tables[j] > 0 && tables[j] + 1 <= k) {
                            tables[j]++;
                            ans++;
                            freq['A']--;
                            placed = true;
                            break;
                        }
                    } 
                }

                if (!placed) {
                    for (int j = 0; j < m; j++) {
                        if (tables[j] + 1 <= k) {
                            tables[j]++;
                            ans++;
                            freq['A']--;
                            placed = true;
                            break;
                        }
                    } 
                }
            }

            //print(tables);

            
        }

        cout << ans << endl;
        
        //space;
    }
    


    return 0;
}
