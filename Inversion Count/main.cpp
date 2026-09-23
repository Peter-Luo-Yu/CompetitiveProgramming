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
    vector<ll> tree;

    void init(int x) {
        n = 1;
        while (n < x) n *= 2;
        tree = vector<ll> (2 * n);
    }

    void set(int i, ll x) {
        i += n;
        tree[i] = x;
        i /= 2;
        while (i >= 1) {
            tree[i] = tree[2 * i] + tree[2 * i + 1];
            i /= 2;
        }
    }

    int sum(int a, int b) {
        a += n; b += n;
        ll sum = 0;
        while (a <= b) {
            if (a % 2 == 1) sum += tree[a++];
            if (b % 2 == 0) sum += tree[b--];
            a /= 2; b /= 2;
        }
        return sum;
    }

};


int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> arr (n);

        // coordinate compress
        vector<pair<int, int>> temp(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
            temp[i] = {arr[i], i};
        }
        
        sort (temp.begin(), temp.end());
        //print(temp);

        vector<int> perm (n);
        for (int i = 0; i < n; i++) {
            perm[temp[i].second] = i + 1;
        }
        print(perm);

        SegmentTree segtree;
        segtree.init(n);

        ll ans = 0;
        for (int i = 0; i < n; i++) {
            ll inversions = segtree.sum(perm[i], n - 1);
            print(inversions);
            ans += inversions;

            segtree.set(perm[i] - 1, 1);
            print(segtree.tree);
        }

        cout << ans << endl;

    }



    return 0;
}