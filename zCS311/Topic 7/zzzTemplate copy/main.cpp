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

ld distance (ld x1, ld y1, ld x2, ld y2) {
    ld dist2 = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
    return sqrtl(dist2);
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    // first step is to check slopes...
    // but it seems like the answer is always the
    // shortest dist from end point to the other line segment
    // unless the two segments intersect

    // I derived this on paper using: u . v = ||u||*||v||*cos(0) 
    // projv (u) = ((u . v) / ||v||^2) v

    // ||projv (u)|| = (u . v) / ||v|| = adj
    // hypotenuse = u
    // opposite = hypotenuse - adj

    // but it seems cross product is way easier
    // just do d = (u = goal - p1) cross (v = goal - p2) / ||p1 - p2||

    int t; cin >> t;
    while (t--) {
        ld x1, y1, x2, y2, x3, y3, x4, y4;
        cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;

        ld temp = max(x1, x2);
        x1 = min(x1, x2); x2 = temp;

        temp = max(y1, y2);
        y1 = min(y1, y2); y2 = temp;

        temp = max(x3, x4);
        x3 = min(x3, x4); x4 = temp;

        temp = max(y3, y4);
        y3 = min(y3, y4); y4 = temp;

        // now one < two and three < four
        print(x1, y1, x2, y2, x3, y3, x4, y4);
        

        bool vert1 = (x1 == x2);
        bool vert2 = (x3 == x4);

        //print(hori1, hori2);

        // Step 1: check for intersection
        

        if (vert1 && vert2) {
            // intersect: either one line is on top or the other line is on top
            if ((x1 == x3) && !(y3 > y2 && y1 > y4)) {
                cout << 0 << endl;

                print("ans = 0");
                space;
                
            }
            // don't intersect
            else {
                // this overlap
                if (!(y3 > y2 && y1 > y4)) {
                    cout << abs(x1 - x3) << endl;

                    print(abs(x1 - x3));
                    space;
                }
                else { // no overlap
                    ld dist1 = distance(x1, y1, x3, y3);
                    ld dist2 = distance(x1, y1, x4, y4);
                    ld dist3 = distance(x2, y2, x3, y3);
                    ld dist4 = distance(x2, y2, x4, y4);

                    ld ans = min(min(dist1, dist2), min(dist3, dist4));
                    cout << ans << endl;

                    print(ans);
                    space;
                }

            }
        }
        else if (vert1) {   // comparing with line2

        }
        else if (vert2) {
        }
        else {
            ld m1 = (y2 - y1) / (x2 - x1);
            ld m2 = (y4 - y3) / (x4 - x3);
            
            ld b1 = y1 - m1 * x1;
            ld b2 = y3 - m2 * x3;

            print(m1, b1, m2, b2);
            
            // m1 * x + b1 = m2 * x + b2
            // x = (b2 - b1) / (m1 - m2)
            ld xint = (b2 - b1) / (m1 - m2);
            ld yint = m1 * xint + b1;

            print(xint, yint);


        }
        
        
        space;
    }



    return 0;
}