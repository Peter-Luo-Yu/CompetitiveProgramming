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

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> arr (n);
        for (int i = 0; i < n; i++) cin >> arr[i];


        vector<int> pos (n + 1);
        for (int i = 0; i < n; i++) {
            pos[arr[i]] = i;
        }

        print(arr, pos);

        bool inc = true;
        for (int i = 0; i < n; i++) {
            if (arr[i] != i + 1) {
                inc = false;
            }
        }

        if (inc) {
            cout << "NO" << endl;
            continue;
        }
        
        bool found = false;
        int ans1 = -1, ans2 = -1, ans3 = -1;

        for (int i = 0; i < n - 2; i++) {
            for (int j = i; j < n - 1; j++) {
                if (arr[i] < arr[j]) {
                    for (int k = j; k < n; k++) {
                        if (arr[j] > arr[k]) {
                            found = true;
                            ans1 = i;
                            ans2 = j;
                            ans3 = k;
                            break;
                        }
                    }
                }

                if (found) break;
            }
            if (found) break;
        }

        if (!found) {
            cout << "NO" << endl;
            continue;
        }
        cout << "YES" << endl;
        cout << ans1 + 1 << " " << ans2 + 1 << " " << ans3 + 1<< endl;
    }


    return 0;
}