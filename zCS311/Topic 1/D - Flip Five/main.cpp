"""Author: Peter Yu
   It is ok to share my code anonymously for educational purposes"""
   
#define LOCAL

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

    // this is a brute force problem

    int t; cin >> t;
    while (t--) {
        // converting the grid to a number

        // 1 2 3
        // 4 5 6
        // 7 8 9

        string s1, s2, s3;
        cin >> s1 >> s2 >> s3;

        int goal = 0;
        int exp = 0;
        for (int i = 0; i < 3; i++) {
            if (s1[i] == '*') {
                goal += pow(2, exp);
            }
            exp++;
        }
        for (int i = 0; i < 3; i++) {
            if (s2[i] == '*') {
                goal += pow(2, exp);
            }
            exp++;
        }
        for (int i = 0; i < 3; i++) {
            if (s3[i] == '*') {
                goal += pow(2, exp);
            }
            exp++;
        }

        //print(goal);

        // XORing the number that represents the grid with these numbers 
        // represent flipping between white and black

        vector<int> ops = {11, 23, 38, 89, 186, 308, 200, 464, 416};

        // brute forcing over all possibilities 
        for (int i = 1; i <= 512; i++) {
            int cur = 0;

            int ans = 0;
            for (int j = 0; j < 9; j++) {
                if (((1 << j) & i) > 0) {
                    cur ^= ops[j];
                    ans++;
                }
            }

            if (cur == goal) {
                cout << ans << endl;
            }

            
        }


        // here's how I calcuated these numbers, using stoi 
        
        // 9 8 7 6 5 4 3 2 1
        string temp = "000100110";
        //print(stoi(temp, nullptr, 2));
        
    }


    
    return 0;
}