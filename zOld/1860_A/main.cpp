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

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int t; cin >> t;
    while (t--) {
        string s; cin >> s;
        if (s == "()") {
            cout << "NO" << endl;
        }
        else {
            reverse(s.begin(), s.end());

            string one = "", two = "";
            for (int i = 0; i < s.size(); i++) {
                one += "()";
                two += "(";
            }
            for (int i = 0; i < s.size(); i++) {
                two += ")";
            }

            bool work1 = true, work2 = true;

            for (int i = 0; i <= one.size() - s.size(); i++) {
                string sub1 = one.substr(i, s.size());
                string sub2 = two.substr(i, s.size());

                print(sub1, sub2);

                if (sub1 == s) {
                    work1 = false;
                }
                if (sub2 == s) {
                    work2 = false;
                }
            }

            cout << "YES" << endl;
            if (work1) {
                cout << one << endl;
            } else {
                cout << two << endl;
            }

            print(one, two);
        }

    }
    


    return 0;
}