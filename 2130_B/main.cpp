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


#define int long long
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
        int n, s; cin >> n >> s;

        vector<int> arr (n);
        map<int, int> freq;
        int sum = 0;
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
            sum += arr[i];
            freq[arr[i]]++;
        }

        vector<int> ans (n);
        if (s < sum) { // already impossible
            ans = arr;
            for (auto a : ans) {
                cout << a << " ";
            }
            cout << endl;

            continue;
        }

        if (s == sum || s > sum + 1) { // gauranteed win
            cout << -1 << endl;
            continue;
        }


        // I misread the problem, so actually you can go to the end
        // and then walk left still

        // so in order to prevent 01 -> ez win
        // you have to place the twos in between 0 and 1,
        // this forces the existence of 02 and 21
        // this you can always get +2 and +3
        // by the chicken mcnugget thm, the 
        // max number you can't get is n*m-n-m = 6 - 2 - 3 = 1
        // basically you can get everything except one above the answer

        int idx = 0;
        for (int i = 0; i < freq[0]; i++) ans[idx++] = 0;
        for (int i = 0; i < freq[2]; i++) ans[idx++] = 2;
        for (int i = 0; i < freq[1]; i++) ans[idx++] = 1; 

        for (auto a : ans) {
            cout << a << " ";
        }
        cout << endl;

    }


    return 0;
}