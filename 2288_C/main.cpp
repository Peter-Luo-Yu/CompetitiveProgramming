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

        int n, k; cin >> n >> k;

        vector<int> arr (n);
        map<int, int> freq;
        for (int i = 0; i < n; i++) {
            cin >> arr[i]; 
            arr[i] = arr[i] / k + (arr[i] % k != 0);
            freq[arr[i]]++;
        }

        sort (arr.begin(), arr.end());
        print(arr);
        print(freq);
        
        vector<int> vals;
        for (auto f : freq) vals.push_back(f.first);
        print(vals);

        int end = arr[arr.size() - 2];
        print(end);

        // greedy = keep the fattest guy alive
        int save = 0;
        int cur = 0;
        for (auto f : freq) {
            if (f.first == end) break;
            
            if (f.first > cur) cur = f.first;

            int dist = end - cur;
            print(f, cur, end, dist);
            save += min(dist, f.second);
            cur += min(dist, f.second);
        }

        save = min(save, end - 1);
        print(save);

        

        int ans = end - save - 1;
        print(ans);

        cout << ans << endl;

        space;

    }


    return 0;
}