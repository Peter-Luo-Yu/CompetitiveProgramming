//#define LOCAL

#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#define print(...) debug(#__VA_ARGS__, __VA_ARGS__)
#else
#define print(...) 6
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

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n; cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    // need to know the position of the first smaller value to the left and right of a given pos
    stack<pair<int, int>> left, right;
    vector<int> smallL (n), smallR (n);
    
    left.push({-1, -1});
    for (int i = 0; i < n; i++) {
        while (!left.empty() && left.top().first >= arr[i]) left.pop();

        smallL[i] = left.top().second;
        left.push({arr[i], i});
    }

    // do it for the right
    right.push({-1, n});
    for (int i = n - 1; i >= 0; i--) {
        while (!right.empty() && right.top().first >= arr[i]) right.pop();

        smallR[i] = right.top().second;
        right.push({arr[i], i});
    }

    print(smallL); print(smallR);

    ll ans = 0;

    for (int i = 0; i < n; i++) {
        ll h = arr[i];

        int width = (i - smallL[i] - 1) + (smallR[i] - i - 1) + 1;

        //cout << h << " " << width << endl;

        ans = max (ans, h * width);
    }

    cout << ans << endl;

    return 0;
}