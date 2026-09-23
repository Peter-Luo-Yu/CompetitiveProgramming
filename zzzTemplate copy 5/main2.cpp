#define LOCAL

#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;

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
//#define endl "\n"

ll MOD = 1e9 + 7;

ll power (ll a, ll b) {
    ll res = 1;
    while (b > 0) {
        if (b % 2 == 1) {
            res = (res * a) % MOD;
        }
        a = (a * a) % MOD;
        b /= 2;
    }
    return res;
}


int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    auto start = high_resolution_clock::now();

    int N = 1e7 + 5;
    vector<int> factor(N); // smallest prime factor
    for (int i = 2; i < N; i++) {
        if (factor[i] == 0) {
            for (int j = i; j < N; j += i) {
                factor[j] = i;     
            }
        }
    }

    auto end = high_resolution_clock::now();
    duration<double, milli> elapsed = end - start;
    print("sieve: ", elapsed.count());

    vector<int> primes; // idx -> prime
    int val = 2;
    while (val * val < N) {
        if (factor[val] == val) {
            primes.push_back(val);
        }
        val++;
    }

    print(primes, primes.size());

    unordered_map<int, int> pidx; // prime -> idx
    for (int i = 0; i < primes.size(); i++) {
        pidx[primes[i]] = i;
    }
    vector<int> exponents (primes.size());

    
    vector<ll> ans (N);
    for (int i = 1; i < N; i++) {
        ll n = i;

        //print(n);

        while (n > 1) {
            ll fac = factor[n];
            int exp = 0;
            while (n % fac == 0) {
                n /= fac;
                exp++;
            }

            //print(fac, exp);
            exponents[pidx[fac]] += exp;
        }

        //print(freq);

        ll a = 1;
        for (int i = 0; i < exponents.size(); i++) {
            ll exp = exponents[i];
            if (exp % 2 == 1) {
                exp--;
            }

            if (exp > 0) {
                a *= power(primes[i], exp);
                a %= MOD;
            }
        }
        ans[i] = a;

        //print(a);

        //space;

        if (i % 10000 == 0) {
            end = high_resolution_clock::now();
            elapsed = end - start;
            print(i, elapsed.count());
        }
        
    }

    //print(ans);

    for (auto a : ans) {
        cout << a << ", ";
    }

    

    /*
    string s;
    while (s != "0") { 
        getline(cin, s);

        if (s == "0") break;
        //cout << s << endl;

        ll n = stoi(s);

        cout << ans[n] << endl;
        
    }
        */
        
        

    return 0;
}