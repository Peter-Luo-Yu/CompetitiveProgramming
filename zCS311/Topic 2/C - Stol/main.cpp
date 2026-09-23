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

    // the problem is the same as problem A, but you do it 
    // on every single row.
    
    int n, m; cin >> n >> m;
    vector<vector<char>> arr (n, vector<char> (m));
 
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }
    
    // finding the height of the histogram going from the top to the bottom
    vector<vector<int>> sum (n, vector<int> (m));
 
    for (int j = 0; j < m; j++) {
        for (int i = 0; i < n; i++) {
            if (arr[i][j] == 'X') { // X resets it
                sum[i][j] = 0;
            }
            else { // arr[i][j] == '.'
                if (i == 0) {
                    sum[i][j] = 1;
                }
                else {
                    sum[i][j] = sum[i - 1][j] + 1; // otherwise you increase in height
                }
            }
        }
    }
 
    print(sum);
 
    ll ans = 0;
 
    for (int i = 0; i < n; i++) {
        stack<pair<int, int>> stkL, stkR;
        vector<int> nearL(m, -1), nearR(m, m);
 
        for (int j = 0; j < m; j++) {
 
            while (!stkL.empty() && stkL.top().first >= sum[i][j]) {
                stkL.pop();
            }
 
            if (!stkL.empty()) {
                nearL[j] = stkL.top().second;
            } 
            stkL.push({sum[i][j], j});
        }
 
        print(sum[i]);
        print(nearL);
 
        for (int j = m - 1; j >= 0; j--) {
 
            while (!stkR.empty() && stkR.top().first >= sum[i][j]) {
                stkR.pop();
            }
 
            if (!stkR.empty()) {
                nearR[j] = stkR.top().second;
            } 
            stkR.push({sum[i][j], j});
        }
 
        print(nearR);
 
 
        for (int j = 0; j < m; j++) {
            if (arr[i][j] == 'X') continue;
 
            ll h = sum[i][j];
            ll w = nearR[j] - nearL[j] - 1;
 
            print(h, w);
 
            ans = max (ans, 2 * (w + h));
        }
 
        space;
    }

    ans -= 1;
    ans = max (ans, 0LL);

    cout << ans << endl;
    
 
    return 0;
}