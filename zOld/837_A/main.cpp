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


    string a; 
    getline(cin, a);
    
    string s; 
    getline(cin, s);
    
    print(a, s);

    vector<char> arr;
    for (auto c : s) {
        arr.push_back(c);
    }

    int n = stoi(a);

    string str = "";
    vector<string> words;
    for (int i = 0; i < n; i++) {
        if (arr[i] != ' ') {
            str += arr[i];
        }
        else {
            words.push_back(str);
            str = "";
        }
    }
    words.push_back(str);

    print(words);

    int ans = -1;

    for (int i = 0; i < words.size(); i++) {
        string cur = words[i];

        print(cur);

        int upper = 0;
        for (int j = 0; j < cur.size(); j++) {
            print(cur[j]);
            if (cur[j] < 'a') {
                upper++;
            }
        }

        print(upper);

        ans = max(ans, upper);
    }

    cout << ans << endl;


    return 0;
}