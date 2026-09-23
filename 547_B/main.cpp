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
    vector<int> arr (n);
    for (int i = 0; i < n; i++) cin >> arr[i];


    stack<pair<int, int>> stkL, stkR;
    vector<int> left(n), right(n);

    stkL.push({-1, -1});
    for (int i = 0; i < n; i++) {
        while (!stkL.empty() && stkL.top().first >= arr[i]) stkL.pop();
        left[i] = stkL.top().second;
        stkL.push({arr[i], i});
    }

    stkR.push({-1, n});
    for (int i = n - 1; i >= 0; i--) {
        while (!stkR.empty() && stkR.top().first >= arr[i]) stkR.pop();
        right[i] = stkR.top().second;
        stkR.push({arr[i], i});
    }

    print(left); print(right);

    vector<int> cand (n + 1);
    for (int i = 0; i < n; i++) {
        int width = (i - left[i]) + (right[i] - i) - 1;
        
        // so arr[i] is the minimum for a segment of "width" width
        cand[width] = max (cand[width], arr[i]);
    }

    vector<int> ans (n + 1);
    // any answer that works for a wide segment will also work for smaller segments
    ans[n] = cand[n];
    for (int i = n - 1; i >= 1; i--) {
        ans[i] = max(ans[i + 1], cand[i]);
    }

    print(cand); print(ans);

    for (int i = 1; i <= n; i++) {
        cout << ans[i] << " ";
    }
    cout << endl;


    return 0;
}