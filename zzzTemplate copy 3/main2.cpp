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
#define lll __int128_t
#define ld long double
#define endl "\n"

int gcd(int a, int b) {
    if (!a || !b)
        return a | b;
    unsigned shift = __builtin_ctz(a | b);
    a >>= __builtin_ctz(a);
    do {
        b >>= __builtin_ctz(b);
        if (a > b)
            swap(a, b);
        b -= a;
    } while (b);
    return a << shift;
}


int32_t main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif    
    
    int t; cin >> t;
    while (t--) {

        int n; cin >> n;
        vector<int> arr (n);
        map<int, int> freq;
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
            freq[arr[i]]++;
        }

        print(arr);
        print(freq);

        vector<int> l, r;
        
        for (auto f : freq) {
            if (f.second >= 2) {
                l.push_back(f.first);
                for (int i = 0; i < f.second - 1; i++) {
                    r.push_back(f.first);
                }
            }
            else {
                l.push_back(f.first);
            }
        }

        print(l, r);

        reverse(r.begin(), r.end());
        for (auto val : r) l.push_back(val);

        arr = l;

        print(arr);


       

        // answer checker
        int ans = (n == 1) ? 1 : 2;

        int prev = arr[0];
        int idx = -1;
        for (int i = 1; i < n - 1; i++) {
            if (arr[i] > prev) {
                print(arr[i], prev);

                ans++;
                prev = arr[i];
                idx = i;

                
            }
        }
        
        print(idx);

        prev = arr[n - 1];
        for (int i = n - 2; i > idx; i--) {
            if (arr[i] > prev) {
                ans++;
                prev = arr[i];
            }
        }
        

        // print ans
        cout << ans << endl;
        for (auto l : arr) {
            cout << l << " ";
        }
        cout << endl;

        space;
    }


    return 0;
}