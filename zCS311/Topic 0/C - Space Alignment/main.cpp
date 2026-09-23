"""Author: Peter Yu
   It is ok to share my code anonymously for educational purposes"""
   
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

    int n; cin >> n;
    vector<string> arr (n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    int ans = -1;
    
    // we only have to brute force t up to 2000 because in the biggest case senario we have:
    // sssss....sss (999x s) {     followed by:
    //      t {
    //      t }
    // sssssss.... }
    // max (t) = 1998
    // but brute forcing t up to 1000 still passes due to weak tests

    for (int t = 1; t <= 1000; t++) {
        stack<string> stk;
        int depth = -1;
        map<int, vector<int>> lengths;

        // the goal is to track the lengths of the string at each depth

        for (int i = 0; i < n; i++) {

            // I'm able to do this because the brackets are gauranteed to work

            string cur = arr[i];
            if (cur[cur.size() - 1] == '{') {
                stk.push(cur);
                depth++;
                continue;
            }
            
            string top = stk.top();
            stk.pop();

            int len = 0;
            for (int j = 0; j < cur.size() - 1; j++) {
                if (cur[j] == 's') {
                    len++;
                }
                else {
                    len+=t;
                }
            }
            lengths[depth].push_back(len);

            len = 0;
            for (int j = 0; j < top.size() - 1; j++) {
                if (top[j] == 's') {
                    len++;
                }
                else {
                    len+=t;
                }
            }
            lengths[depth].push_back(len);

            depth--;
        }

        // now, if all of the lengths at each depth are matching
        // we check if the lenghts themselves follow the pattern of depth * i

        int I = -1;
        bool same = true;
        bool aligned = true;
        for (auto l : lengths) {
            for (int i = 0; i < l.second.size() - 1; i++) {
                if (l.second[i] != l.second[i + 1]) {
                    same = false;
                }
            }

            if (!same) break;

            if (l.first > 0) {
                int candI = l.second[0] / l.first;
                if (I == -1) {
                    I = candI;
                }
                else {
                    if (candI != I) {
                        aligned = false;
                    }
                }
            }
        }

        if (aligned && same) {
            ans = t;
            break;
        }
    }

    cout << ans << endl;
    
    return 0;
}