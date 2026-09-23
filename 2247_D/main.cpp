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


int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int t; cin >> t;
    while (t--) {
        int n, q; cin >> n >> q;

        vector<int> arr (n), temp(n);

        map<int, int> mp; // val - index
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
            temp[i] = arr[i];
        }
       
        sort (temp.begin(), temp.end());

        //print(temp);

        for (int i = 0; i < temp.size(); i++) {
            mp[temp[i]] = i;
        }

        //print(mp);

        
        //vector<pair<int, int>> cand;
        int ans = 0;
        for (int i = 0; i < n - 1; i++) {
            int sup = mp[arr[i]]; // supposed to go

            //print(sup);

            if (i != sup) {
                swap(arr[i], arr[sup]);
                ans = max (ans, i ^ sup);
                i--;
            }
        }
        

        cout << ans << endl;
        
    }


    
    return 0;
}