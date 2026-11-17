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


#define int long long
#define lll __int128_t
#define ld long double
#define endl "\n"

int gcd(int a, int b) {
    if (!a || !b)
        return a | b;
    unsigned shift = __builtin_ctz(a | b);
    a >>= __builtin_ctz(a);
    do {
        b >>= __builtin_ctz(b);
        if (a > b)
            swap(a, b);
        b -= a;
    } while (b);
    return a << shift;
}

int32_t main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif    
    

    int t; cin >> t;
    while (t--) {

        int n, k; cin >> n >> k;

        map<int, int> freq;
        map<int, vector<int>> loc;

        vector<vector<int>> arr (n);

        for (int i = 0; i < n; i++) {
            int m; cin >> m;
            for (int j = 0; j < m; j++) {
                int num; cin >> num;
                freq[num]++;
                loc[num].push_back(i);
                arr[i].push_back(num);
            }
        }

        bool seenAll = true;
        for (int i = 0; i < k; i++) {
            if (freq[i + 1] == 0) {
                seenAll = false;
            }
        }
        
        if (!seenAll) {
            cout << "NO" << endl;
            continue;
        }


        // check sets of size n - 1

        int amt = 0;
        for (int i = 0; i < n; i++) {
            bool failed = false;
            for (int j = 0; j < arr[i].size(); j++) {
                if (freq[arr[i][j]] <= 1) {
                    failed = true;
                }
            }

            if (!failed) {
                amt++;
            }
        }

        if (amt >= 2) {
            cout << "YES" << endl;
        }
        else {
            cout << "NO" << endl;
        }
    
        
       

    }


    return 0;
}