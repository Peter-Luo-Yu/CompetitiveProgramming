#define LOCAL

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
#define space cout << "-------" << endl;
        


int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> a(n), b(n);

        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < n; i++) cin >> b[i];

        int num1 = 0, num0 = 0, un = 0, zero = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] == 1) {
                num1++;
                if (b[i] != a[i]) {
                    un++;
                }
            } else {
                num0++;
                if (a[i] == b[i]) {
                    zero++;
                }
            }
            
        }

        bool equal = true;
        for (int i = 0; i < n; i++) {
            if (a[i] != b[i]) {
                equal = false;
            }
        }

        if (equal) {
            cout << 0 << endl;
            //space;
            continue;
        }
        
        //cout << un << endl;

        if (un > 0) {
            if (un % 2 == 1) {
                cout << 1 << endl;
            } else {
                cout << 2 << endl;
            }
        } else {
            if (zero > 0 && num1 > 0) {
                cout << 2 << endl;
            } else {
                cout << -1 << endl;
            }
        }

       
        //space;
    }

    
    return 0;
}