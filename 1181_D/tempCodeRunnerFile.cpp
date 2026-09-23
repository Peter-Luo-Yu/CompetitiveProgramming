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

struct SegTree {
    ll n; 
    vector<ll> tree, lazy;

    void init(ll x) {
        n = x;
        tree = lazy = vector<ll> (4 * n);
    }

    void apply(ll v, ll len, ll val) {
        tree[v] += val;
        lazy[v] += val;
    }

    void push(ll v, ll l, ll r) {
        ll m = (l + r) / 2;
        apply(2 * v, m - l + 1, lazy[v]);
        apply(2 * v + 1, r - m, lazy[v]);
        lazy[v] = 0;
    }

    void add(ll v, ll l, ll r, ll ql, ll qr, ll val) {
        if (r < ql || l > qr) return;
        if (ql <= l && r <= qr) {
            apply(v, r - l + 1, val);
        }
        else {
            push(v, l, r);
            ll m = (l + r) / 2;
            add (2 * v, l, m, ql, qr, val);
            add (2 * v + 1, m + 1, r, ql, qr, val);
            tree[v] = min(tree[2 * v], tree[2 * v + 1]);
        }
    }
    void add (ll ql, ll qr, ll val) {
        add(1, 0, n - 1, ql, qr, val);
    }

    // find position of the kth 1
    ll findk (ll v, ll l, ll r, ll k) {
        if (l == r) return l;

        ll mid = (l + r) / 2;

        if (k <= tree[2 * v]) {
            return findk(2 * v, l, mid, k);
        }
        else {
            return findk(2 * v + 1, mid + 1, r, k - tree[2 * v]);
        }
    }
    ll findk (ll k) {
        return findk(1, 0, n - 1, k);
    }

};


int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n, m, q; cin >> n >> m >> q;

    vector<int> orig (n);
    for (int i = 0; i < n; i++) cin >> orig[i];

    map<int, int> temp; // city - freq
    for (int i = 0; i < n; i++) {
        temp[orig[i]]++;
    }
    for (int i = 1; i <= m; i++) {
        if (temp.count(i) == 0) {
            temp[i] = 0;
        }
    }

    map<int, int> freq; // times appeared - num cities
    map<int, vector<int>> idx; // times appeared - which cities (decides who gets activated)  
    for (auto t : temp) {
        freq[t.second]++;   
        idx[t.second].push_back(t.first);
    }

    vector<pair<int, int>> arr; // times appeared - num cities
    for (auto f : freq) {
        arr.push_back({f.first, f.second});
    }

    print(orig);
    print(temp);
    print(arr);
    print(idx);

    vector<ll> queries (q);
    for (int i = 0; i < q; i++) {
        cin >> queries[i]; queries[i] -= n;
    }
    sort (queries.begin(), queries.end());

    SegTree seg;
    seg.init(m); // everybody starts out inactive

    ll prevT = 0, curT = 0;
    ll qidx = 0;
    ll active_cities = 0;
    for (int i = 1; i <= arr.size(); i++) {
        // difference in freq appeared (=> diff in years)
        ll gap = arr[i].first - arr[i - 1].first;

        // multiply difference by number of cities that need to leveled up
        curT += gap * arr[i - 1].second;

        // people getting activated
        for (int j = 0; j < idx[arr[i - 1].first].size(); j++) {
            seg.add(idx[arr[i - 1].first][j] - 1, idx[arr[i - 1].first][j] - 1, 1);
            active_cities++;
        }

        print(prevT, curT, gap);
        print(seg.tree);
        
        // find the idx of the query
        while (qidx < queries.size() && queries[qidx] <= curT) {
            // finds the offset of the query in the current block
            ll index = (queries[qidx] - prevT - 1) % active_cities;

            // +1 because seg tree is tracking sum, you want position of sum = offset
            ll ans = seg.findk(index + 1) + 1;

            print(queries[qidx], index, ans);
            qidx++;
        }


        arr[i].second += arr[i - 1].second;
        arr[i - 1].second = 0;
        prevT = curT;

        space;
    }






    return 0;
}