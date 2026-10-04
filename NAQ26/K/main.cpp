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

        int Max = 123456789;

        vector<int> digits;
        int val = n;
        while (val > 0) {
            digits.push_back(val % 10);
            val /= 10;
        }

        reverse(digits.begin(), digits.end());

        print(digits);

        // check if already good
        bool good = true;
        for (int i = 0; i < digits.size() - 1; i++) {
            if (digits[i] != digits[i + 1] - 1) {
                good = false;
            }
        }
        if (good) {
            cout << n << endl;
            continue;
        }

        // now we know it isn't good

        // same starting digit
        if (digits[0] <= 9 - digits.size() + 1) {
            vector<int> same = digits;
            for (int i = 1; i < same.size(); i++) {
                same[i] = same[i - 1] + 1;
            }
            print(same);

            int res = 0;
            int power = 1;

            for (int i = same.size() - 1; i >= 0; i--) {
                res += power * same[i];
                power *= 10;
            }

            if (n < res && res <= Max) {
                for (auto s : same) {
                    cout << s;
                }
                cout << endl;
                continue;
            }
        }

        // increase starting digit by 1
        if (digits[0] <= 9 - digits.size()) {
            vector<int> same = digits;
            same[0] = digits[0] + 1;

            for (int i = 1; i < same.size(); i++) {
                same[i] = same[i - 1] + 1;
            }
            print(same);

            int res = 0;
            int power = 1;

            for (int i = same.size() - 1; i >= 0; i--) {
                res += power * same[i];
                power *= 10;
            }

            if (n < res && res <= Max) {
                for (auto s : same) {
                    cout << s;
                }
                cout << endl;
                continue;
            }
        }

        // now we promote -> inc num digits by 1
        
        if (digits.size() + 1 > 9) {
            cout << -1 << endl;
        }

        vector<int> same(digits.size() + 1);
        same[0] = 1;

        for (int i = 1; i < same.size(); i++) {
            same[i] = same[i - 1] + 1;
        }
        print(same);

        int res = 0;
        int power = 1;

        for (int i = same.size() - 1; i >= 0; i--) {
            res += power * same[i];
            power *= 10;
        }

        if (n < res && res <= Max) {
            for (auto s : same) {
                cout << s;
            }
            cout << endl;
            continue;
        }
        

        cout << -1 << endl;
       

    }


    return 0;
}