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


struct State { // 0 = ".", 1 = "X", 2 = "O";
    int p1, p2, p3, p4, p5, p6, p7, p8, p9;
    bool X = true;

    bool operator<(const State &o) const {
        return (p1 * 6561 + p2 * 2187 + p3 * 729 + p4 * 243 + p5 * 81 +
                p6 * 27 + p7 * 9 + p8 * 3 + p9) < 
                (o.p1 * 6561 + o.p2 * 2187 + o.p3 * 729 + o.p4 * 243 + o.p5 * 81 +
                o.p6 * 27 + o.p7 * 9 + o.p8 * 3 + o.p9);
    }
    
};

map<State, pair<int, int>> dp;

void solve(State s) {
    int winner = -1; 
    if (s.p1 == s.p2 && s.p2 == s.p3 && s.p1 != 0) winner = s.p1;
    if (s.p4 == s.p5 && s.p5 == s.p6 && s.p4 != 0) winner = s.p4;
    if (s.p7 == s.p8 && s.p8 == s.p9 && s.p7 != 0) winner = s.p7;
    
    if (s.p1 == s.p4 && s.p4 == s.p7 && s.p1 != 0) winner = s.p1;
    if (s.p2 == s.p5 && s.p5 == s.p8 && s.p2 != 0) winner = s.p2;
    if (s.p3 == s.p6 && s.p6 == s.p9 && s.p3 != 0) winner = s.p3;

    if (s.p1 == s.p5 && s.p5 == s.p9 && s.p1 != 0) winner = s.p1;
    if (s.p3 == s.p5 && s.p5 == s.p7 && s.p3 != 0) winner = s.p3;
    
    if (winner == 1) {
        dp[s] = {1LL, 0LL};
        return;
    }
    if (winner == 2) {
        dp[s] = {0LL, 1LL};
        return;
    }


    int Xwins = 0, Owins = 0;
    State next;
    if (s.p1 == 0) {
        next = s;
        next.p1 = (s.X) ? 1 : 2;
        next.X = !s.X;

        solve(next);
        Xwins += dp[next].first;
        Owins += dp[next].second;
    }
    if (s.p2 == 0) {
        next = s;
        next.p2 = (s.X) ? 1 : 2;
        next.X = !s.X;
        solve(next);
        Xwins += dp[next].first;
        Owins += dp[next].second;
    }
    if (s.p3 == 0) {
        next = s;
        next.p3 = (s.X) ? 1 : 2;
        next.X = !s.X;
        solve(next);
        Xwins += dp[next].first;
        Owins += dp[next].second;
    }
    if (s.p4 == 0) {
        next = s;
        next.p4 = (s.X) ? 1 : 2;
        next.X = !s.X;
        solve(next);
        Xwins += dp[next].first;
        Owins += dp[next].second;
    }
    if (s.p5 == 0) {
        next = s;
        next.p5 = (s.X) ? 1 : 2;
        next.X = !s.X;
        solve(next);
        Xwins += dp[next].first;
        Owins += dp[next].second;
    }
    if (s.p6 == 0) {
        next = s;
        next.p6 = (s.X) ? 1 : 2;
        next.X = !s.X;
        solve(next);
        Xwins += dp[next].first;
        Owins += dp[next].second;
    }
    if (s.p7 == 0) {
        next = s;
        next.p7 = (s.X) ? 1 : 2;
        next.X = !s.X;
        solve(next);
        Xwins += dp[next].first;
        Owins += dp[next].second;
    }
    if (s.p8 == 0) {
        next = s;
        next.p8 = (s.X) ? 1 : 2;
        next.X = !s.X;
        solve(next);
        Xwins += dp[next].first;
        Owins += dp[next].second;
    }
    if (s.p9 == 0) {
        next = s;
        next.p9 = (s.X) ? 1 : 2;
        next.X = !s.X;
        solve(next);
        Xwins += dp[next].first;
        Owins += dp[next].second;
    }

    dp[s] = {Xwins, Owins};
}



int32_t main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif    
    
    State initial = {0, 0, 0, 0, 0, 0, 0, 0, 0};
    solve(initial);


    /*
    for (auto d : dp) {

        cout << d.first.p1 << " " << d.first.p2 << " " << d.first.p3 << " " << endl;
        cout << d.first.p4 << " " << d.first.p5 << " " << d.first.p6 << " " << endl;
        cout << d.first.p7 << " " << d.first.p8 << " " << d.first.p9 << " " << endl;
        cout << d.second.first << " " << d.second.second << endl;

        cout << "------" << endl;
    }
    */


    int t; cin >> t;
    while (t--) {
        
        string s; cin >> s;

        State st;
        if (s[0] == '.') st.p1 = 0; if (s[0] == 'X') st.p1 = 1; if (s[0] == 'O') st.p1 = 2;
        if (s[1] == '.') st.p2 = 0; if (s[1] == 'X') st.p2 = 1; if (s[1] == 'O') st.p2 = 2;
        if (s[2] == '.') st.p3 = 0; if (s[2] == 'X') st.p3 = 1; if (s[2] == 'O') st.p3 = 2;
        if (s[3] == '.') st.p4 = 0; if (s[3] == 'X') st.p4 = 1; if (s[3] == 'O') st.p4 = 2;
        if (s[4] == '.') st.p5 = 0; if (s[4] == 'X') st.p5 = 1; if (s[4] == 'O') st.p5 = 2;
        if (s[5] == '.') st.p6 = 0; if (s[5] == 'X') st.p6 = 1; if (s[5] == 'O') st.p6 = 2;
        if (s[6] == '.') st.p7 = 0; if (s[6] == 'X') st.p7 = 1; if (s[6] == 'O') st.p7 = 2;
        if (s[7] == '.') st.p8 = 0; if (s[7] == 'X') st.p8 = 1; if (s[7] == 'O') st.p8 = 2;
        if (s[8] == '.') st.p9 = 0; if (s[8] == 'X') st.p9 = 1; if (s[8] == 'O') st.p9 = 2;

        if (dp.count(st) == 0) {
            cout << -1 << " " << -1 << endl;
        }
        else {
            cout << dp[st].first << " " << dp[st].second << endl;
        }

    }


    return 0;
}