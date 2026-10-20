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

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<ll> arr (n);
        for (int i = 0; i < n; i++) cin >> arr[i];

        ll ans = 1e18;

        ll l = -1, r = -1;
        ll prev = -1;
        for (int i = 0; i < n; i++) {
            if (l == -1) {
                l = i; r = i;
                prev = arr[i];
                continue;
            }
            
            if (arr[i] == prev) {
                r++;
            }
            else {
                ll cost = l * prev + (n - r - 1) * prev; 
                ans = min(ans, cost);

                //cout << l << " " << r << " " << cost << endl;

                prev = arr[i];
                l = i; r = i;
            }
        }
        ll cost = l * prev + (n - r - 1) * prev; 
        //cout << l << " " << r << " " << cost << endl;

        ans = min(ans, cost);

        cout << ans << endl;

        
    }


    return 0;
}