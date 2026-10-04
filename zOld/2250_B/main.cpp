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
#define line cout << "----------" << endl;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    
    int t; cin >> t;
    while (t--) {
        int n, k; cin >> n >> k;
        vector<int> arr (n);

        int Max = (n / 2) + ((n + 1) / 2) - 2;

        if (k > Max) {
            cout << -1 << endl;
            //line;
            continue;
        }

        int num0 = ((n + 1) / 2); // 0 has more
        int num1 = (n / 2);

        if (k == Max) {
            for (int i = 0; i < num0; i++) {
                cout << "0";
            }
            for (int i = 0; i < num1; i++) {
                cout << "1"; 
            }
            cout << endl;
            continue;
        }
        
        if (k % 2 == 1) {
            // split into k/2 + 1 and k/2
            int placed = 1;
            cout << "1";
            for (int i = 0; i < (k / 2) + 1 + 1; i++) {
                cout << "0"; 
                placed++;
            }
            for (int i = 0; i < (k / 2) + 1; i++) {
                cout << "1"; 
                placed++;
            }

            for (int i = placed; i < n; i++) {
                if ((i - placed) % 2 == 0) cout << "0";
                else cout << "1";
            }
            cout << endl;
        }
        else {
            // split into k/2 and k/2 of course
            int placed = 0;
            for (int i = 0; i < (k / 2) + 1; i++) {
                cout << "0"; 
                placed++;
            }
            for (int i = 0; i < (k / 2) + 1; i++) {
                cout << "1"; 
                placed++;
            }

            for (int i = placed; i < n; i++) {
                if ((i - placed) % 2 == 0) cout << "0";
                else cout << "1";
            }
            cout << endl;
        }


        //line;

    }
    


    return 0;
}