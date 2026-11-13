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


struct SegmentTree {
    int n;
    vector<int> lazy, tree;
 
    void init(int x) {
        n = x;
        tree = lazy = vector<int> (4 * n);
    }
 
    void apply(int v, int len, int val) { // change tree[v] to val * len; 
        tree[v] += val * len;
        lazy[v] += val;
    }
 
    void push(int v, int l, int r) {
        int mid = (l + r) / 2;
        apply(2 * v, mid - l + 1, lazy[v]);
        apply(2 * v + 1, r - mid, lazy[v]);
        lazy[v] = 0;
    }
 
    void add(int v, int l, int r, int ql, int qr, int val) {
        if (qr < l || ql > r) return;
        if (ql <= l && r <= qr) {
            apply(v, r - l + 1, val);
        }
        else {
            push(v, l, r);
            int mid = (l + r) / 2;
            add(2 * v, l, mid, ql, qr, val);
            add(2 * v + 1, mid + 1, r, ql, qr, val);
            tree[v] = tree[2 * v] + tree[2 * v + 1]; // change to tree[2v] + tree[2v + 1]
        }
    }
 
    void add(int ql, int qr, int val) {
        add(1, 0, n - 1, ql, qr, val);
    }
 
    // sum actually returns the max now :)

    int sum(int v, int l, int r, int ql, int qr) {
        if (qr < l || ql > r) return 0; // change to 0
        if (ql <= l && r <= qr) {
            return tree[v];
        }
        else {
            push(v, l, r);
            int mid = (l + r) / 2;
            return max(sum(2 * v, l, mid, ql, qr), sum(2 * v + 1, mid + 1, r, ql, qr));
        }
    }
 
    int sum(int ql, int qr) {
        return sum(1, 0, n - 1, ql, qr);
    }
 
    int findk (int k) { // 0 indexed
        int v = 1, l = 0, r = n - 1;
 
        while (l < r) {
            push(v, l, r);
            int mid = (l + r) / 2;
            if (tree[2 * v] > k) { // left side has more than k active
                v = 2 * v;
                r = mid;
            }
            else {
                k -= tree[2 * v];
                v = 2 * v + 1;
                l = mid + 1;
            }
        }
 
        return l;
    }

    
    void build(int v, int l, int r, const vector<int>& a) { // set leaves from a[0..n-1]
        lazy[v] = 0;
        if (l == r) { tree[v] = a[l]; return; }
        int mid = (l + r) / 2;
        build(2 * v, l, mid, a);
        build(2 * v + 1, mid + 1, r, a);
        tree[v] = max(tree[2 * v], tree[2 * v + 1]);
    }

    void build(const vector<int>& a) {
        build(1, 0, n - 1, a);
    }

    void erase(int pos) {
        add(pos, pos, -(int) 1e12);
    }

    void set(int pos, int val) {
        add(pos, pos, sum(pos, pos) * -1);
        add(pos, pos, val);
    }


    // push every position in [ql, qr] whose value is >= T
    void collect(int v, int l, int r, int ql, int qr, int T, vector<int>& out) {
        if (qr < l || ql > r || tree[v] < T) return;
        if (l == r) { out.push_back((int)l); return; }
        push(v, l, r);
        int mid = (l + r) / 2;
        collect(2 * v, l, mid, ql, qr, T, out);
        collect(2 * v + 1, mid + 1, r, ql, qr, T, out);
    }

    void collect(int ql, int qr, int T, vector<int>& out) {
        collect(1, 0, n - 1, ql, qr, T, out);
    }
 
};

int32_t main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif    
    
    
    int n, q; cin >> n >> q;

    vector<int> values (6);
    for (int i = 0; i < 6; i++) cin >> values[i];

    string s; cin >> s;
    SegmentTree segtree;
    segtree.init(n);



    


    return 0;
}