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
        int n; cin >> n;
        vector<int> arr (n);
        for (int i = 0; i < n; i++) cin >> arr[i];

        map<int, int> freq;
        for (auto a : arr) {
            freq[a]++;
        }

        print(freq);
        
        if (freq[0] == 0) {
            string ans = "ABC";
            for (int i = 0; i < n - 3; i++) {
                ans += "A";
            }
            cout << "YES" << endl;
            cout << ans << endl;
        }
        else if (freq[0] == 1) {
            cout << "NO" << endl;
        } 
        else if (freq[0] == 2) {
            vector<char> ans (n, '-');
            int idx1 = -1, idx2 = -1;

            for (int i = 0; i < n; i++) {
                if (arr[i] == 0) {
                    idx1 = i;
                    break;
                }
            }
            for (int i = idx1 + 1; i < n; i++) {
                if (arr[i] == 0) {
                    idx2 = i;
                    break;
                }
            }
            
            print(idx1, idx2);

            ans[idx1] = 'A';
            ans[idx2] = 'B';

            for (int i = 0; i < n; i++) {
                if (ans[i] == '-') {
                    ans[i] = 'C';
                }
            }

            cout << "YES" << endl;
            for (auto a : ans) {
                cout << a;
            }
            cout << endl;

        }
        else {
            vector<char> ans (n, '-');
            int idx1 = -1, idx2 = -1;

            for (int i = 0; i < n; i++) {
                if (arr[i] == 0) {
                    idx1 = i;
                    break;
                }
            }
            for (int i = idx1 + 1; i < n; i++) {
                if (arr[i] == 0) {
                    idx2 = i;
                    break;
                }
            }
            
            print(idx1, idx2);

            ans[idx1] = 'A';
            ans[idx2] = 'B';

            for (int i = idx2 + 1; i < n; i++) {
                if (arr[i] == 0) {
                    ans[i] = 'C';
                }
            }

            for (int i = 0; i < n; i++) {
                if (arr[i] == 1) {
                    ans[i] = 'A';
                }
            }
            for (int i = 0; i < n; i++) {
                if (ans[i] == '-') {
                    ans[i] = 'B';
                }
            }

            cout << "YES" << endl;
            for (auto a : ans) {
                cout << a;
            } cout << endl;

        }




    }


    return 0;
}