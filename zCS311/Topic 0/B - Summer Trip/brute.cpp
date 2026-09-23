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

    string s; cin >> s;

    map<char, vector<int>> pos; // positions of each number
    for (int i = 0; i < s.size(); i++) {
        pos[s[i]].push_back(i);
    }
    
    // The answer is the number of distinct elements between 2 consecutive occurences of the same char

    ll ans = 0;

    // for each different character
    for (auto c : pos) {
        vector<int> temp = c.second;

        // loop through the positions of each occurence of that character
        for (int i = 0; i < temp.size(); i++) {
            set<int> st; // set counts the number of unique chars in between

            // split into 2 cases, we are inbetween two chars, or we are at the last char
            if (i == (temp.size() - 1)) {
                for (int j = temp[i] + 1; j < s.size(); j++) {
                    st.insert(s[j]);
                }
            } else {
                for (int j = temp[i] + 1; j < temp[i + 1]; j++) {
                    st.insert(s[j]);
                }
            }

            ans += st.size();
        }
    }

    // the complexity seems to be too slow, but even in the worst cases
    // abcd..xyz ...... abcd...xyz 
    // we seem to get a complexity of O(26N)

    cout << ans << endl;


    return 0;
}