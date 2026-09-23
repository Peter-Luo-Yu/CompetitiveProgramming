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

    // instead of brute forcing over all possible subarrays -> n^2
    // we just assume the min to be the current index and extend 
    // as far out as possible in both directions.
    // which means we need to know the nearest smallest values to the left and right
    // segment tree is slow because of the extra log n factor
    // instead we use mono stack for O(n) performance

    int n; cin >> n;
    vector<int> arr (n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    stack<pair<int, int>> stkL, stkR;
    vector<int> smallL(n, -1), smallR(n, n);

    // computing nearest smaller value to the left

    for (int i = 0; i < n; i++) {
        while (!stkL.empty() && stkL.top().first >= arr[i]) stkL.pop();

        if (!stkL.empty()) {
            smallL[i] = stkL.top().second;
        }
        stkL.push({arr[i], i});
    }

    print(smallL);

    // computing nearest smaller value to the right
    
    for (int i = n - 1; i >= 0; i--) {
        while (!stkR.empty() && stkR.top().first >= arr[i]) stkR.pop();

        if (!stkR.empty()) {
            smallR[i] = stkR.top().second;
        }
        stkR.push({arr[i], i});
    }

    print(smallR);


    // simple brute force

    ll ans = -1;
    int s = 1e9, e = 1e9;

    for (int i = 0; i < n; i++) {
        // the deal here is that the smallest value to the left or right 
        // act as endpoints of the segment and is actually not supposed 
        // to be included in the count

        // when subtracting the r - l to compute the length of the segment [r, l]
        // we undercount by 1, the len is r - l + 1;
        // thus, we overcount by 2 and undercount by 1 = net overcount by 1

        ll width = smallR[i] - smallL[i] - 1;

        ll h = arr[i];

        ll cur = width * h;

        print(cur);
        
        if (cur > ans) {
            ans = cur;
            s = smallL[i] + 1;
            e = smallR[i] - 1;
        }
        else if (cur == ans) {
            if (smallL[i] + 1 < s) {
                s = smallL[i] + 1;
                e = smallR[i] - 1;
            }
        }
    }

    // convert to 1 indexed
    cout << s + 1 << " " << e + 1 << " " << ans << endl;

    return 0;
}