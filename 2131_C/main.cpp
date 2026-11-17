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
        
        // add k or repleace with distance -> subtracting k if far away
        // or replace x with k - x if close

        // tc 3: k = 5
        // 6 -> 11, also 6 -> 1 -> 5 -> 11
        // 2 -> 3 -> 8
        // 9 -> 4

        vector<int> a(n), b(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < n; i++) cin >> b[i];        

        // if a[i] < k, then it can get replaced with k - a[i]

        vector<int> A(n), B(n);
        map<int, int> fa, fb;
        for (int i = 0; i < n; i++) {
            A[i] = a[i] % k;
            B[i] = b[i] % k;
            fa[A[i]]++; fb[B[i]]++;
        }

        print(A); print(B);

        bool failed = false;
        for (int i = 0; i < n; i++) {
            int val = a[i] % k;
            
            if (fb[val] > 0) {
                fb[val]--;
            }
            else if (fb[k - val] > 0) {
                fb[k - val]--;
            }
            else {
                failed = true;
            }

        }

        print(failed);

        if (failed) {
            cout << "NO" << endl;
        }
        else {
            cout << "YES" << endl;
        }

        space;
    }   


    return 0;
}