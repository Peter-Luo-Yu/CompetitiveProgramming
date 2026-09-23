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
        int n, m; cin >> n >> m;
        vector<int> arr (n);
        for (int i = 0; i < n; i++) cin >> arr[i];

        map<int, int> freq;
        for (auto a : arr) {
            freq[a]++;
        }

        
        vector<pair<int, int>> temp;
        int idx = 0;
        for (auto f : freq) {
            if (f.first % 2 == 0 && freq.count(f.first / 2) == 0) {
                temp.push_back({f.first / 2, 0});
            }
            temp.push_back({f.first, f.second});
        }

        sort (temp.begin(), temp.end());

        vector<int> lens (temp.size());
        vector<int> fs (temp.size());

        for (int i = 0; i < temp.size(); i++) {
            lens[i] = temp[i].first;
            fs[i] = temp[i].second;
        }

        print(lens);
        print(fs);

        vector<int> pref (fs.size() + 1);
        for (int i = 0; i < fs.size(); i++) {
            pref[i + 1] = pref[i] + fs[i];
        }

        print(pref);

        
        int ans = -1;
        for (int i = 0; i < lens.size(); i++) {
            int bigger = pref[pref.size() - 1] - pref[i + 1];

            int cur = fs[i] + bigger;
            if (freq.count(lens[i] * 2) > 0) {
                cur += freq[lens[i] * 2];
            }

            print(lens[i], cur);

            ans = max (ans, cur);
        }

        cout << ans << endl;

        print(ans);
        space;
    }


    return 0;
}