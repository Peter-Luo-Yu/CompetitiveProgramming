#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define endl "\n"
#define print(arr) for (auto x : arr) cout << x << " "; cout << "\n";
#define print2d(arr) for (int i = 0; i < arr.size(); i++) {for (int j = 0; j < arr[i].size(); j++) {cout << arr[i][j] << " ";} cout << "\n";}
#define printG(adj) for (int i = 0; i < adj.size(); i++) {cout << "i: " << i << " | "; for (int j = 0; j < adj[i].size(); j++) {cout << adj[i][j] << " ";} cout << endl;}
#define printP(arr) for (auto x : arr) {cout << x.first << " " << x.second << "\n";}
#define space cout << "----------" << endl;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    // stall for t seconds, spreads every p seconds.
    int p, t; cin >> p >> t;

    string s; cin >> s; 

    int cur = 0, idx = 0;

    //cout << "t = 0: " << s << endl;

    int iterations = (t / p) - (t % p == 0); 

    while (idx < iterations) {
        string next = s;

        for (int i = 0; i < s.size(); i++) {
            if (i == 0) {
                if (s[i] == 'I' && s[i + 1] == 'H') {
                    next[i + 1] = 'I';
                }
            } else if (i == s.size() - 1) {
                if (s[i] == 'I' && s[i - 1] == 'H') {
                    next[i - 1] = 'I';
                }
            } else {
                if (s[i] == 'I' && s[i + 1] == 'H') {
                    next[i + 1] = 'I';
                }
                if (s[i] == 'I' && s[i - 1] == 'H') {
                    next[i - 1] = 'I';
                }
            }
        }

        s = next;
        cur += p;
        idx++;
        
        //cout << "t = " << cur << ": " << s << endl;
        
    }

    bool foundH = false;

    for (int i = 0; i < s.size(); i++) {
        if (s[i] == 'H') {
            foundH = true;
            break;
        }
    }

    if (foundH == false) {
        cout << "ALL INFECTED" << endl;
    } else {
        cout << "CURED" << endl;
    }

    return 0;
}
