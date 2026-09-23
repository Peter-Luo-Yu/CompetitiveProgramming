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
    ll n;
    vector<ll> lazy, tree;
    
    void init(ll x) {
        n = x;
        lazy = tree = vector<ll> (4 * n);
    }

    void apply(ll v, ll len, ll val) {
        lazy[v] += val;
        tree[v] += val; // max seg tree
    }

    void push(ll v, ll l, ll r) {
        ll mid = (l + r) / 2;
        apply(2 * v, mid - l + 1, lazy[v]);
        apply(2 * v + 1, r - mid, lazy[v]);
        lazy[v] = 0;
    }

    void add (ll v, ll l, ll r, ll ql, ll qr, ll val) {
        if (qr < l || ql > r) return;
        if (ql <= l && r <= qr) {
            apply(v, r - l + 1, val);
        }
        else {
            push(v, l, r);

            ll mid = (l + r) / 2;
            add(2 * v, l, mid, ql, qr, val);
            add(2 * v + 1, mid + 1, r, ql, qr, val);
            tree[v] = max(tree[2 * v], tree[2 * v + 1]);
        }
    }
    void add (ll ql, ll qr, ll val) {
        add (1, 0, n - 1, ql, qr, val);
    }

    // GOAL: return idx of where is the max is in a range

    ll findMax (ll v, ll l, ll r, ll ql, ll qr) {
        if (qr < l || ql > r) return -1e9;
        if (ql <= l && r <= qr) {
            return tree[v];
        }
        else {
            push(v, l, r);
            ll mid = (l + r) / 2;
            return max(findMax(2 * v, l, mid, ql, qr), findMax(2 * v + 1, mid + 1, r, ql, qr));
        }
    }

    ll findMax (ll ql, ll qr) {
        return findMax(1, 0, n - 1, ql, qr);
    }
    
    ll findIdx (ll v, ll l, ll r, ll ql, ll qr, ll val) {
        if (qr < l || ql > r || tree[v] < val) return -1;

        if (l == r) {
            return l;
        }

        push(v, l, r);

        ll mid = (l + r) / 2;
        ll left = findIdx(2 * v, l, mid, ql, qr, val);
        if (left != -1) return left;

        return findIdx(2 * v + 1, mid + 1, r, ql, qr, val);
    }

    ll findMaxIdx (ll ql, ll qr) {
        ll maxVal = findMax(1, 0, n - 1, ql, qr);
        return findIdx(1, 0, n - 1, ql, qr, maxVal);
    }

};

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    
    // thought: we need a max segment tree to find the max within a range
    int N = 1e6 + 5;
    SegmentTree seg;
    seg.init(N);

    for (int i = 1; i <= N; i++) {
        int minDig = 9, maxDig = 0;

        int val = i;
        while (val > 0) {
            int dig = val % 10;
            //print(dig);
            minDig = min(minDig, dig);
            maxDig = max(maxDig, dig);
            val /= 10;
        }

        //print(i, minDig, maxDig);

        seg.add(i, i, maxDig - minDig);

        //space;
    }

    int t; cin >> t;
    while (t--) {
        int l, r; cin >> l >> r;
        cout << seg.findMaxIdx(l, r) << endl;
    }


    return 0;
}