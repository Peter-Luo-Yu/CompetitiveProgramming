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


int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    string s; cin >> s;

    vector<int> f (s.size()), l (s.size());
    map<char, pair<int, int>> occur; // {first occur, last occur}

    for (int i = 0; i < s.size(); i++) {
        occur[s[i]].first = 1e9;
        occur[s[i]].second = -1e9;
    }
    for (int i = 0; i < s.size(); i++) {
        occur[s[i]].first = min(occur[s[i]].first, i);
        occur[s[i]].second = max(occur[s[i]].second, i);
    }
    
    print(occur);

    for (int i = 0; i < s.size(); i++) {
        f[occur[s[i]].first] = 1;
        l[occur[s[i]].second] = 1;
    }

    print(f, l);

    vector<ll> prefF(s.size() + 1), prefL(s.size() + 1);
    for (int i = 0; i < s.size(); i++) {
        prefF[i + 1] = prefF[i] + f[i];
        prefL[i + 1] = prefL[i] + l[i];
    }

    print(prefF);
    print(prefL);

    map<char, vector<int>> pos; // positions of each number
    for (int i = 0; i < s.size(); i++) {
        pos[s[i]].push_back(i);
    }

    print(pos);
    
    ll ans = 0;
    for (auto c : pos) {
        vector<int> temp = c.second;

        for (int i = 0; i < temp.size(); i++) {
            if (i == (temp.size() - 1)) {
                ans += (prefF[prefF.size() - 1] - prefF[i + 1]);
                print(prefF.size() - 1, i, ans);
            } else {
                ans += (prefF[temp[i + 1] - 1] - prefF[temp[i] + 1]);
                print(temp[i + 1], i, ans);
            }
        }

        space;
    }

    cout << ans << endl;
    print(ans);

    return 0;
}