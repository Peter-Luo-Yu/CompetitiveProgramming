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

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    
    int t; cin >> t; 
    while (t--) {
        int n, k; cin >> n >> k;
        string s; cin >> s;

        vector<char> ans (n);

        int num0 = 0, num1 = 0, num2 = 0;
        for (auto c : s) {
            num0 += (c == '0');
            num1 += (c == '1');
            num2 += (c == '2');   
        }

        for (int i = 0; i < num0; i++) {
            ans[i] = '-';
        }
        for (int i = n - 1; i > n - 1 - num1; i--) {
            ans[i] = '-';
        }


        for (int i = num0; i < min(num0 + num2, n); i++) {
            if (ans[i] != '-') {
                ans[i] = '?';
            }    
        }
        for (int i = n - 1 - num1; i > max(n - 1 - num1 - num2, 0); i--) {
            if (ans[i] != '-') {
                ans[i] = '?';
            }    
        }

        for (int i = 0; i < n; i++) {
            if (ans[i] != '-' && ans[i] != '?') {
                ans[i] = '+';
            }
        }



        if (k == n) {
            for (int i = 0; i < n; i++) {
                ans[i] = '-';
            }
        }

        for (auto a : ans) {
            cout << a;
        }
        cout << endl;

        //print(num0, num1, num2, ans);

    }


    return 0;
}