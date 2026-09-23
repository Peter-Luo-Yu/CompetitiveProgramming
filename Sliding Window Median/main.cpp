//#define LOCAL

#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#define print(...) debug(#__VA_ARGS__, __VA_ARGS__)
#else
#define print(...) 6
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

int n, k; 
multiset<ll> low, hi;

void ins(ll val) {
    ll med = *low.rbegin();
    if (med < val) { // greater -> insert to hi
        hi.insert(val);
        if (hi.size() > k / 2) {
            low.insert(*hi.begin());
            hi.erase(hi.begin());
        }
    } else { // smaller -> insert to low 
        low.insert(val);
        if (low.size() > ((k + (2 - 1)) / 2)) {
            hi.insert(*low.rbegin());
            low.erase(--low.end());
        } 
    }
}

void er(ll val) {
    if (hi.find(val) != hi.end()) {
        hi.erase(hi.find(val));
    }
    else {
        low.erase(low.find(val));
    }

    if (low.empty()) {
        low.insert(*hi.begin());
        hi.erase(hi.begin());
    }
}


int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    cin >> n >> k;
    vector<int> arr (n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }    

    low.insert(arr[0]); // you need to start off the chain with the first median
    for (int i = 1; i < k; i++) {
        ins(arr[i]);
    }
    cout << *low.rbegin() << " ";
    
    // treat i as endpoint of the window
    for (int i = k; i < n; i++) {
        // you actually must erase first and then insert or it breaks

        if (k == 1) { // for k = 1, you have to insert or you might lose the median in low
            ins(arr[i]);
            er(arr[i - k]);
        }
        else {
            er(arr[i - k]);
            ins(arr[i]);
        }
        cout << *low.rbegin() << " ";
    }


    return 0;
}