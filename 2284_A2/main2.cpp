#define LOCAL

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


int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif    
    
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<ll> arr (n);
        map<ll, ll> freq;
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
            arr[i] = (1LL << arr[i]);
            freq[arr[i]]++;
        }

        ll Max = freq.rbegin() -> first;

        for (auto &f : freq) {
            ll cur = f.first;

            if (cur == Max) break;

            if (f.second >= 2) {
                freq[cur * 2] += (f.second / 2);
                f.second -= 2 * (f.second / 2);
            } 
        }
        print(freq);

        
        ll a = 0, b = 0;

        if (freq[Max] > 2) {
            ll amt;
            if (freq[Max] % 2 == 0) { // ex 4
                amt = freq[Max] - 2;
                a += Max * amt / 2;
                b += Max * amt / 2;
                freq[Max] -= amt;
            }
            else { // ex 3
                amt = freq[Max] - 1;
                a += Max * amt / 2;
                b += Max * amt / 2;
                freq[Max] -= amt;
            }
        }

        for (auto it = freq.rbegin(); it != freq.rend();) {
            if (it -> second != 0) {
                if (it -> second % 2 == 1) break;

                print(it -> first, it -> second);

                a += (it -> second / 2) * (it -> first);
                b += (it -> second / 2) * (it -> first);
                it -> second = 0;
            }
            it++;
        }

        print(a, b);

        for (auto it = freq.begin(); it != freq.end();) {
            if (it -> second == 0) {
                freq.erase(it++);
            }
            else {
                it++;
            }
        }

        print(freq);

        if (freq.begin() == freq.end()) {
            ll ans = a * b;
            cout << ans << endl;
            space;
            continue;
        }


        Max = freq.rbegin() -> first;
        a += Max;

        for (auto f : freq) {
            if (f.first == Max) break;
            b += f.first;
        }
       
        print(a, b);

        ll ans = a * b;
        cout << ans << endl;

        space;
    }


    return 0;
}