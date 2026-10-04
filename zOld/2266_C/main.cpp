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
        int n; cin >> n;
        string s; cin >> s;

        vector<int> arr (n);
        for (int i = 0; i < n; i++) {
            arr[i] = s[i] - '0';
        }

        if (arr[0] == 1) {
            int num0 = 0; 
            for (auto a : arr){
                num0 += (a == 0);
            }
            cout << num0 << endl;
            continue;
        }

        vector<int> pref0 (n + 1), pref1 (n + 1);

        for (int i = 0; i < n; i++) {
            if (arr[i] == 0) {
                pref0[i + 1] = pref0[i] + 1;
            }
            else {
                pref0[i + 1] = pref0[i];
            }

            if (arr[i] == 1) {
                pref1[i + 1] = pref1[i] + 1;
            }
            else {
                pref1[i + 1] = pref1[i];
            }
        }

        print(arr);
        print(pref0);
        print(pref1);

        int best = 1e9;
        // all ones starting at i
        for (int i = 0; i < n; i++) {
            // zeros to the left
            int left = pref0[i] - pref0[0];
            // ones to the right
            int right = pref1[n] - pref1[i];

            print(i, left, right);

            int l = i, r = n - i;

            best = min (best, (l - left) + (r - right));
        }

        // consider if we don't any ones
        best = min(best, pref1[n]);
        
        print(best);

        cout << best << endl;

        space;


    }


    return 0;
}