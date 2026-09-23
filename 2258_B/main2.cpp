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
        int n, m; cin >> n >> m;
        vector<int> arr (n);
        for (int i = 0; i < n; i++) cin >> arr[i];

        map<int, int> freq;
        for (auto a : arr) {
            freq[a]++;
        }

        print(freq);

        ll smal = 1e9;
        ll smalF = -1;
        for (auto f : freq) {
            if (f.second > smalF) {
                smalF = f.second;
                smal = f.first;
            }
            else if (f.second == smalF) {
                if (f.first < smal) {
                    smal = f.first;
                }
            }
        }

        print(smal, smalF);

        int ans = -1;

        if (smal % 2 == 0) {
            int thresh = smal / 2;

            int cur = smalF;
            for (auto f : freq) {
                if (f.first >= thresh) {
                    cur += f.second;
                }
            }

            ans = max (ans, cur);
        }
        else {
            int cur = 0;
            for (auto f : freq) {
                if (f.first == 2 * smal) {
                    cur += 2 * f.second;
                }
                else {
                    cur += f.second;
                }
            }
            ans = max (ans, cur);
        }

        print(ans);
        cout << ans << endl;
    }


    return 0;
}