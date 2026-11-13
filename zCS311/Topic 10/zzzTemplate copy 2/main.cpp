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

#define PI (ld) 3.14159265358979323

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


// BEGIN CODE -----


int32_t main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif    
    

    int n;
    while (true) {
        cin >> n;
        if (n == -1) break;

        if (n == 0) {
            cout << 1 << endl;
            continue;
        }
        if (n % 2 == 1) {
            cout << 0 << endl;
            continue;
        }

        print(n);


        // attempt to implement it in a numerically smart way
        // m = 3, n = n;

        ld sum = 0;
        for (int k = 1; k <= 3; k++) {
            for (int j = 1; j <= n; j++) {
                ld a = cosl(k * PI / 4);
                ld b = cosl(j * PI / (n + 1));

                ld val = 4 * (a * a + b * b);
                sum += logl(val);
            }
        }

        ld res = expl(sum / 4);
        
        print(res);

        cout << fixed << setprecision(0) << res << endl;


        space;
    }

    


    return 0;
}