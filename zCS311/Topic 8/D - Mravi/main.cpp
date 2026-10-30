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

struct Node {
    ld percent;
    ll super;
};


vector<vector<pair<ll, Node>>> adj;
vector<bool> vis;
vector<ld> result;


void dfs(int s) {
    if (vis[s]) return;
    vis[s] = true;

    print("parent: ", s);

    for (auto u : adj[s]) {
        print("child: ", u.first);

        if (vis[u.first]) continue; // make sure not to visit the parent

        // first update the child node
        result[u.first] = result[s] * (u.second.percent / (ld) 100);

        // if it is a super connection, square it
        // remember "All super pipes can have their superpower turned on or off by Bobi."

        if (u.second.super == 1 && result[u.first] > 1) {
            result[u.first] *= result[u.first];
        }

        dfs (u.first);
    }
}


int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n; cin >> n;

    // i is connected to -> vector{adj[i]}, inside the vector each term {cur node, percent, super}
    adj = vector<vector<pair<ll, Node>>> (n);

    for (int i = 0; i < n - 1; i++) {
        ll a, b;
        ld percent;
        ll super; 
        cin >> a >> b >> percent >> super;
        a--, b--;

        print(a, b, percent, super);

        Node node;
        node.percent = percent;
        node.super = super;

        adj[a].push_back({b, node});
        adj[b].push_back({a, node});
    }

    vector<ld> ants (n);
    for (int i = 0; i < n; i++) {
        cin >> ants[i];
    }

    print(ants);

    /*
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < adj[i].size(); j++) {
            print(i, j, adj[i][j].first, adj[i][j].second.percent, adj[i][j].second.super);       
        }
    } */

    ld l = 0, r = 1e10;
    while (r - l > 1e-9) {
        ld mid = (l + r) / (ld) 2;

        print(mid);

        vis = vector<bool> (n);
        result = vector<ld> (n);

        result[0] = mid;
        dfs (0);

        print(result);

        bool failed = false;
        for (int i = 0; i < n; i++) {
            if (ants[i] == -1) continue;
            if (ants[i] > result[i]) {
                failed = true;
            }
        }

        if (failed) { // failed means more water needed
            l = mid;
        }
        else {
            r = mid;
        }
    }

    print(l, r);

    cout << fixed << setprecision(5) << r << endl;



    return 0;
}