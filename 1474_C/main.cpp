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
        int n; cin >> n;
        vector<int> arr (2 * n);
        for (int i = 0; i < 2 * n; i++) cin >> arr[i];

        sort (arr.begin(), arr.end());
        print(arr);

        bool found = false;
        vector<pair<int, int>> ans;
        int initial = -1;

        for (int i = 0; i < 2 * n - 1; i++) {
            vector<pair<int, int>> temp;
            print(i);

            int x = arr[i] + arr[2 * n - 1];

            multiset<int> ms;
            for (auto a : arr) {
                ms.insert(a);
            }

            temp.push_back({arr[i], arr[2*n - 1]});
            ms.erase(ms.find(arr[i]));
            ms.erase(ms.find(arr[2 * n - 1]));

            print(ms);

            x = max (arr[i], arr[2 * n - 1]);

            bool failed = false;

            while (!ms.empty()) {
                auto it = ms.end();
                it--;

                int pair1 = *it;
                int pair2 = x - *it;

                print(x, pair1, pair2, ms);

                ms.erase(it);

                if (ms.find(pair2) == ms.end()) {
                    failed = true;
                    break;
                }

                ms.erase(ms.find(pair2));

                x = max(pair1, pair2);
                temp.push_back({pair1, pair2});
            }

            print(ms, failed);

            cerr << "-----" << endl;

            if (!failed) {
                found = true;
                ans = temp;
                initial = arr[i] + arr[2 * n - 1];
                break;
            }    
        }

        if (!found) {
            cout << "NO" << endl;
        } else {
            cout << "YES" << endl;
            cout << initial << endl;
            for (auto [a, b] : ans) {
                cout << a << " " << b << endl;
            }
        }
        
    }



    
    return 0;
}