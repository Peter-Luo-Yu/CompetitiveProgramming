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
        string s; cin >> s;

        // check len 1 substrings
        
        bool done = false;
        string mex;

        for (int i = 'a'; i <= 'z'; i++) {
            char c = (char) i;

            //cout << "c: " << c << endl;

            bool found = false;
            for (int j = 0; j < n; j++) {
                if (s[j] == c) {
                    found = true;
                    //cout << "found: " << c << endl;
                }
            }

            if (!found) {
                done = true;
                mex = c;
                break;
            }
        }

        if (done) {
            cout << mex << endl;
            continue;
        }

        // check 2 letter substrings

        for (int i = 'a'; i <= 'z'; i++) {
            for (int j = 'a'; j <= 'z'; j++) {
                bool found = false;

                char one = (char) i;
                char two = (char) j;

                for (int k = 0; k < n - 1; k++) {
                    if (s[k] == one && s[k + 1] == two) {
                        found = true;
                        //cout << "found: " << c << endl;
                    }
                }

                if (!found) {
                    done = true;
                    mex += one;
                    mex += two;
                    break;
                }
            }
            if (done) {
                break;
            }
        }

        if (done) {
            cout << mex << endl;
            continue;
        }

        // a small portion of 3 letter substrings: 
        // we only need to consider a _ _, because we only have 1000 - 26 - 26 * 26 < 576 poss

        for (int i = 'a'; i <= 'z'; i++) {
            for (int j = 'a'; j <= 'z'; j++) {
                bool found = false;

                char one = (char) i;
                char two = (char) j;

                for (int k = 0; k < n - 2; k++) {
                    if (s[k] == 'a' && s[k + 1] == one && s[k + 2] == two) {
                        found = true;
                        //cout << "found: " << c << endl;
                    }
                }

                if (!found) {
                    done = true;
                    mex += 'a';
                    mex += one;
                    mex += two;
                    break;
                }
            }
            if (done) {
                break;
            }
        }

        if (done) {
            cout << mex << endl;
            continue;
        }

        //space;
    }


    return 0;
}
