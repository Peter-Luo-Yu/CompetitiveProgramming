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
        int id; cin >> id;

        string s; cin >> s;
        int idx = s.find("/");
        print(idx);

        string P = s.substr(0, idx);
        string Q = s.substr(idx + 1);
        print(P, Q);

        ll p = stoi(P), q = stoi(Q);

        if (p == 0 || q == 0) {
            cout << id << " " << 1 << "/" << 1 << endl;
            continue;
        }

        if (p == 1 && q == 1) {
            cout << id << " " << 1 << "/" << 2 << endl;
            continue;
        }
        
        if (p == 1 && q == 1) {
            cout << id << " " << 1 << "/" << 2 << endl;
            continue;
        }
        if (p < q) { // p / q -> q / q - p
            cout << id << " " << q << "/" << q - p << endl;
            continue;
        }

        // if (p > q) 
        if (q == 1) { // the edge case: p / 1 -> 1 / q + 1
            cout << id << " " << 1 << "/" << p + 1 << endl;
            continue;
        }

        // traverse up the tree until p < q, switch branches, then traverse down
        
        // go up until you are left child
        ll times = p / q;
        p -= times * q;
        print("now p > q", p, q); 

        // switch to right child
        ll temp = p;
        p = q;
        q -= temp;
        print("switch", p, q);

        // go back down
        q += p * times;

        cout << id << " " << p << "/" << q << endl;

        //space;
    }


    return 0;
}