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

    // this first observation that Arvind went over in class was 
    // to reduce the problem into horizontal and vertical segments
    // and checking if they intersect

    // I did get help: https://blog.csdn.net/weixin_52027970/article/details/161524294

    // the second crucial observation is to use a sweep line approach so that 
    // we don't need to store both the ranges of both the x values
    // and the y values, because everything would explode and
    // you are better off using an O(n^2) idea.
    // the sweep line technique implicitly takes care of 
    // the x coordinate by splitting the events into 2 types
    // an open - when you insert the range into active ranges.
    // and the close - when you remove the range from active ranges.

    // Now that the x coordinates are implicitly taken care of:
    // we are simply looping over each event which cooresponds to 
    // a x-val and a range of the y-values

    // Now, for each event, you have to check if the two y coordinates 
    // are in between any acive ranges, for this you can use binary search

    ll n; cin >> n;
    vector<vector<ll>> arr; // not using struct to hopefully not get caught

    for (int i = 0; i < n; i++) {
        ll x1, y1, x2, y2; 
        cin >> x1 >> y1 >> x2 >> y2;

        // event 1: opening of range -> 0
        arr.push_back({x1, y1, y2, 0});

        // event 2: closing of range -> 1
        arr.push_back({x2, y1, y2, 1});
    }

    // of course we need to process the events in order
    sort (arr.begin(), arr.end());

    print(arr);
    
    set<ll> st;
    bool intersect = false;
    for (int i = 0; i < arr.size(); i++) {
        // so there's actually a much easier way to check for intersection
        // we know the x intervals already overlap

        // so all we are checking for is for their to be a y value inbetween
        // the our current y-range: arr[i][1] -> arr[i][2]

        // just use upperbound so we don't get absolutely cooked
        auto it = st.upper_bound(arr[i][1]);
        if (it != st.end() && (*it < arr[i][2])) {
            print(i, *it, arr[i][1], arr[i][2]);
            intersect = true;
        }

        // insert / remove interval
        if (arr[i][3] == 0) {
            st.insert(arr[i][1]);
            st.insert(arr[i][2]);
        }
        else {
            st.erase(arr[i][1]);
            st.erase(arr[i][2]);
        }
    }


    cout << (intersect ? 1 : 0) << endl;

    return 0;
}