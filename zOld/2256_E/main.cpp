#define LOCAL

#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#define print(...) debug(#__VA_ARGS__, __VA_ARGS__)
#define space cerr << "----------" << endl;
#else
#define print(...) 6
#define space 7
#endif

template<typename T, typename S> ostream& operator << (ostream &os, const pair<T, S> &p);
template<typename C, typename T = decay<decltype(*begin(declval<C>()))>, typename enable_if<!is_same<C, string>::value>::type* = nullptr> ostream& operator << (ostream &os, const C &c);

template<typename T, typename S> ostream& operator << (ostream &os, const pair<T, S> &p) {return os << "(" << p.first << ", " << p.second << ")";}
template<typename C, typename T, typename enable_if<!is_same<C, string>::value>::type*> ostream& operator << (ostream &os, const C &c) {bool f = true; os << "["; for (const auto &x : c) {if (!f) os << ", "; f = false; os << x;} return os << "]";}

template<typename T> void debug(string s, T x) {cerr << "\033[1;35m" << s << "\033[0;32m = \033[33m" << x << "\033[0m\n";}
template<typename T, typename... Args> void debug(string s, T x, Args... args) {for (int i=0, b=0; i<(int)s.size(); i++) if (s[i] == '(' || s[i] == '{') b++; else
if (s[i] == ')' || s[i] == '}') b--; else if (s[i] == ',' && b == 0) {cerr << "\033[1;35m" << s.substr(0, i) << "\033[0;32m = \033[33m" << x << "\033[31m | "; debug(s.substr(s.find_first_not_of(' ', i + 1)), args...); break;}}


#define ll long long
#define ld long double
#define endl "\n"


// we don't actually even need the extended euclidian because n is small, we just brute force
ll inverse(ll x, ll MOD) {
    ll inv = -1;
    for (ll i = 0; i < MOD; i++) {
        ll res = (i * x) % MOD;
        if (res == 1) {
            inv = i; 
            break;
        }
    } 
    return inv;   
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    
    // assume center of mass is not affected by the operations - can be proved
    // the goal is to move the center of mass to the target location

    // w inverse = w^-1 exists because gcd(n, w) = 1. (just look up the proof)

    // that is (SumR / w, SumC / w) = (CenterR, CenterC)

    // in type "first" queries, the swap adds: (remember we are subtracting black and adding white (new black))
    // NewSumR = SumR - br + wr, NewSumC = SumC - bc + wc
    // New CenterR = (SumR - br + wr) * w^-1 = SumR * w^-1 + (wr - br) * w^-1 = Old CenterR + dr
    // we see that: dr = (wr - br) * w^-1 = tr - centerR
    //   similarly: dc = (wc - bc) * w^-1 = tc - centerC
    
    // complete search
    // solve: wr = br + (dr) * w 
    //        wc = bc + (dc) * w  

    // need proof: assume that after doing a complete search on every black cell, there will be at least one suitable white cell (dr, dc) distance away to swap with
    // finally in the case dr = 0 and dc = 0, just swap 1 1 with 1 1

    // in type "second" queries, you just have to find the center of mass and output it
    
    // should be at least 2400 rated problem but cheaters tanked it down to 2200

    string type; cin >> type;
    if (type == "first") {
        int t; cin >> t;
        while (t--) {
            ll n; cin >> n;
            vector<vector<char>> grid (n, vector<char> (n));
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    cin >> grid[i][j];
                }
            }

            //print(grid);

            // target row and column
            ll tr, tc; cin >> tr >> tc; tr--, tc--;

            ll w = 0; // num black cells

            // compute sum row and sum col
            ll sr = 0, sc = 0;
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (grid[i][j] == '#') {
                        w++;
                        sr += i;
                        sc += j;
                    }
                }
            }

            // center of mass row and col
            ll cr = (sr * inverse(w, n)) % n, cc = (sc * inverse(w, n)) % n; 

            // desired deltas
            ll dr = ((tr - cr) % n + n) % n, dc = ((tc - cc) % n + n) % n;

            print(sr, sc, cr, cc, dr, dc);


            if (dr == 0 && dc == 0) {
                cout << "1 1 1 1" << endl;
                continue;
            }

            // look for target black cell with white cell at corresponding delta
            ll br = -1, bc = -1;
            ll wr = -1, wc = -1;
            for (int i = 0; i < n; i++) {
                bool found = false;
                for (int j = 0; j < n; j++) {
                    if (grid[i][j] == '#') {
                        br = i; bc = j;

                        wr = (br + (dr * w) % n) % n;
                        wc = (bc + (dc * w) % n) % n;

                        if (grid[wr][wc] == '.') {
                            found = true;
                            break;
                        }
                    }
                }
                if (found) {
                    break;
                }
            }

            cout << br + 1 << " " << bc + 1 << " " << wr + 1 << " " << wc + 1 << endl;

        }

    }
    else {
        int t; cin >> t;
        while (t--) {
            ll n; cin >> n;
            vector<vector<char>> grid (n, vector<char> (n));
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    cin >> grid[i][j];
                }
            }

            ll w = 0;
            ll sr = 0, sc = 0;
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (grid[i][j] == '#') {
                        w++;
                        sr += i;
                        sc += j;
                    }
                }
            }

            // center of mass row and col
            ll cr = (sr * inverse(w, n)) % n, cc = (sc * inverse(w, n)) % n; 

            cout << cr + 1 << " " << cc + 1 << endl;

        }

    }


    return 0;
}