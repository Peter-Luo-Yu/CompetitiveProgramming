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


    // the goal is to find the smallest size substring that needs to be inserted
    // logically, it makes sense to check how much of the prefix and suffix match

    string s1, s2; cin >> s1 >> s2;

    // checking left prefix
    int idx1 = 0, idx2of1 = s1.size() - 1;
    while (idx1 < min(s1.size(), s2.size()) && s1[idx1] == s2[idx1]) {
        idx1++;
    }

    // checking right suffix
    int idx2of2 = s2.size() - 1;

    // I asked gemini (first google result) why my code was WA'ing
    // it's because I didn't consider the edge case when the two pointers crossed, skill issue :(
    while (idx2of1 >= 0 && idx2of2 >= 0 && min(idx2of1, idx2of2) >= idx1 && s1[idx2of1] == s2[idx2of2]) {
        idx2of1--; 
        idx2of2--;
    }

    print(idx1, idx2of1, idx2of2);

    // printing the final ans

    if (idx1 > idx2of2) {
        cout << 0 << endl;
        return 0;
    }

    int ans = idx2of2 - idx1 + 1;

    cout << ans << endl;

    
    return 0;
}