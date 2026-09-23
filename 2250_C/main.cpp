//#define LOCAL

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

struct Rank {
    int l, r, u, v;
};


int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;

        vector<Rank> arr (n);
        for (int i = 0; i < n; i++) {
            int l, r, u, v; cin >> l >> r >> u >> v;
            arr[i] = {l, r, u, v};
        }

        int ans = 0;

        // attempt to brute force the length of the subseq
        for (int m = 1; m <= n; m++) {

            print(m);
            
            int placed = 0;
            
            int idx = 0, i = 0; // idx is the position, i is the number we are trying to place at said position
            while (idx < m && i < n) {
                int l = arr[i].l - 1;
                int r = arr[i].r - 1;

                int u = (m + 1 - arr[i].v) - 1; // the subtraction kind of criss crosses
                int v = (m + 1 - arr[i].u) - 1;
                
                print(idx, i, l, r, u, v);

                if (((idx < l) || (idx > r)) && ((idx < u) || (idx > v))) {
                    i++; idx++; placed++;
                    print("placed");
                } else {
                    i++;
                    print("not placed");
                }

               
            }

            if (placed == m) {
                print("enough");
                ans = max (ans, m);
            } else{
                print("not enough");
            }

            space;
        }

        print(ans);
        
        cout << ans << endl;
        space; space;

    }


    return 0;
}