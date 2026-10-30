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

    string s; getline(cin, s);
    int t = stoi(s);
    while (t--) {
        getline(cin, s);

        int ans = 1e9;
        for (int len = s.size(); len > 0; len--) {
            string repeat = s.substr(0, len);
            print(repeat);

            bool failed = false;

            for (int i = 0; i < s.size(); i += len) {
                string cur = s.substr(i, len);
                print(cur);

                // we need cur equal to repeat or just a prefix of repeat

                if (cur.size() == repeat.size()) {
                    if (cur != repeat) {
                        failed = true;
                        break;
                    }
                }
                else {
                    bool equal = true;
                    for (int j = 0; j < cur.size(); j++) {
                        if (cur[j] != repeat[j]) {
                            equal = false;
                        }
                    }
                    if (!equal) {
                        failed = true;
                        break;
                    }
                }
            }

            if (!failed) {
                print("good");
                ans = len;
            }
        }

        cout << ans << endl;
        print(ans);


    }

    return 0;
}