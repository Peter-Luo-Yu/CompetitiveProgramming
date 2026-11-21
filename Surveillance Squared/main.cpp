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


#define int long long
#define lll __int128_t
#define ld long double
#define endl "\n"

#define PI (ld) 3.14159265358979323

int gcd(int a, int b) {
    if (!a || !b)
        return a | b;
    unsigned shift = __builtin_ctz(a | b);
    a >>= __builtin_ctz(a);
    do {
        b >>= __builtin_ctz(b);
        if (a > b)
            swap(a, b);
        b -= a;
    } while (b);
    return a << shift;
}

int cross (int x1, int y1, int x2, int y2) {
    return (x1 * y2 - x2 * y1);
}

ld mag (int x1, int y1) {
    return sqrtl(x1 * x1 + y1 * y1);
}

// returns dist squared
ld dist (int x1, int y1, int x2, int y2) {
    return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
}

int32_t main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif    

    print(PI / 4);
    
    string s = "-"; 
    while (s != "") {
        getline(cin, s);
        if (s == "") break;

        int n = stoi(s);
        vector<vector<int>> arr (n, vector<int> (4));
        for (int i = 0; i < n; i++) {
            getline(cin, s);

            int pos = 0;
            int sz = 0;
            int idx = 0;
            for (int j = 0; j < s.size(); j++) {
                if (s[j] == ' ') {
                    //print(pos, j, s.substr(pos, sz));
                    arr[i][idx] = stoi(s.substr(pos, sz));
                    pos = j + 1;
                    sz = 0;
                    idx++;
                }
                else {
                    sz++;
                }
            }
            //print(s.substr(pos));
            arr[i][3] = stoi(s.substr(pos));
        }

        print(arr);

        vector<int> ans(n);

        for (int i = 0; i < n; i++) {

            int v1x = arr[i][2];
            int v1y = arr[i][3];

            int vpx = arr[i][0] - arr[i][2];
            int vpy = arr[i][1] - arr[i][3];

            for (int j = 0; j < n; j++) {
                if (i == j) continue;

                int v2x = arr[j][0] - arr[i][0];
                int v2y = arr[j][1] - arr[i][1];

                if (dist(arr[j][0], arr[j][1], arr[i][0] + arr[i][2], arr[i][1] + arr[i][3]) > 
                    dist(arr[j][0], arr[j][1], vpx, vpy)) continue;

                print(v1x, v1y, v2x, v2y);
                
                int cp = cross(v1x, v1y, v2x, v2y);

                ld mag1 = mag(v1x, v1y);
                ld mag2 = mag(v2x, v2y);

                ld theta = asinl((ld) cp / (mag1 * mag2));

                print(theta);

                if (abs(theta) <= PI / 4) {
                    ans[i]++;
                }


            }
        }

        for (auto a : ans) {
            cout << a << endl;
        }
        cout << endl;


        space;
    }



    return 0;
}