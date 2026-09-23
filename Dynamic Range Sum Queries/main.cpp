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

struct SegmentTree {
    int n;
    vector<ll> arr;

    void init(int x) {
        n = 1;
        while (n < x) n *= 2;
        arr = vector<ll> (2 * n);
    }

    void set(int i, ll x) {
        i += n;
        arr[i] = x;

        i /= 2;
        while (i >= 1) {
            arr[i] = arr[2 * i] + arr[2 * i + 1];
            i /= 2;
        }
    }

    ll sum(int a, int b) {
        a += n; b += n;
        ll s = 0;
        while (a <= b) { // left even, right odd
            if (a % 2 == 1) s += arr[a++];
            if (b % 2 == 0) s += arr[b--];
            a /= 2; b /= 2;
        }
        return s;
    }

};


int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n, q; cin >> n >> q;

    SegmentTree segtree;
    segtree.init(n);
    for (int i = 0; i < n; i++) {
        int val; cin >> val;
        segtree.set(i, val);
    }

    print(segtree.arr);

    while (q--) {
        int t, a, b; cin >> t >> a >> b;

        if (t == 1) {
            a--;
            segtree.set(a, b);
        }
        else {
            a--, b--;
            cout << segtree.sum(a, b) << endl;
        }

        print(segtree.arr);
    }
    
    return 0;
}