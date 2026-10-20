/*Author: Peter Yu
   It is ok to share my code anonymously for educational purposes */


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

#define eps (ld) 1e-5

#define ll long long
#define ld long double
#define endl "\n"


int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    // the idea is that the most extreme point that can be targeted is the 
    // tangent line from the satillite to the extreme point on the sphere

    // so any point close to the direct line of sight from the satillite to
    // the origin of the sphere will have angle greater than 90 degrees
    // or where cosine theta < 0


    string s = "";
    while (true) {
        getline(cin, s);
        if (s == "0 0") break;

        // k satillites, m targets
        int k = stoi(s.substr(0, s.find(" ")));
        int m = stoi(s.substr(s.find(" ") + 1));
        print(k, m);
       
        // I learned that you can abuse s.find("something", starting at this index)
        vector<vector<ld>> satellites (k, vector<ld> (3)), targets(m, vector<ld> (3));
        for (int i = 0; i < k; i++) {
            getline(cin, s);

            int idx = 0;
            satellites[i][0] = stold(s.substr(0, s.find(" ")));
            idx = s.find(" ") + 1;

            satellites[i][1] = stold(s.substr(idx, s.find(" ", idx)));
            idx = s.find(" ", idx) + 1;

            satellites[i][2] = stold(s.substr(idx, s.find(" ", idx)));

            //print(satellites[i]);
        }
        for (int i = 0; i < m; i++) {
            getline(cin, s);

            int idx = 0;
            targets[i][0] = stold(s.substr(0, s.find(" ")));
            idx = s.find(" ") + 1;

            targets[i][1] = stold(s.substr(idx, s.find(" ", idx)));
            idx = s.find(" ", idx) + 1;

            targets[i][2] = stold(s.substr(idx, s.find(" ", idx)));

            //print(targets[i]);
        }

        // now we brute force for each satellite, which targets can we hit
        vector<bool> hit (m);

        for (int i = 0; i < k; i++) {
            ld x = satellites[i][0];
            ld y = satellites[i][1];
            ld z = satellites[i][2];

            for (int j = 0; j < m; j++) {
                ld tx = targets[j][0];
                ld ty = targets[j][1];
                ld tz = targets[j][2];

                // so to check if the angle > 90
                // we have to make the vectors pointing to the target
                // v1 = <tx - 0, ty - 0, tz - 0> and v2 = <tx - x, ty - y, tz - z>
                // since v1 . v2 = |v1||v2|cos(0)
                // we see if theta > 90, cos(theta) < 0
                // so we want (v1 . v2) / (|v1||v2|) < 0

                ld v2i = tx - x;
                ld v2j = ty - y;
                ld v2k = tz - z;

                ld v1dotv2 = tx * v2i + ty * v2j + tz * v2k;
                ld v1mag = sqrtl(tx * tx + ty * ty + tz * tz);
                ld v2mag = sqrtl(v2i * v2i + v2j * v2j + v2k * v2k);

                ld check = v1dotv2 / (v1mag * v2mag);

                print(tx, ty, tz);
                print(v2i, v2j, v2k);
                print(v1dotv2, v1mag, v2mag);
                print(check);

                // actually there is an edge case when the dot product is 0 (orthogonal)
                if ((check < eps) || (v1dotv2 < check)) {
                    hit[j] = true;
                }

                space;
            }
        }

        print(hit);

        int ans = 0;
        for (int i = 0; i < m; i++) {
            if (hit[i]) ans++;
        }

        cout << ans << endl;
    }

    return 0;
}