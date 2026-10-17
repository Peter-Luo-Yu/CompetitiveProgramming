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

// projects v onto unit vector a, also needs the starting point of v and a
ld distance (ld au1, ld au2, ld v1, ld v2, ld s1, ld s2, ld x1, ld y1, ld x2, ld y2) {
    //ld amag = 1;
    ld vmag = sqrtl(v1 * v1 + v2 * v2);
    ld projmagnitude = (au1 * v1 + au2 * v2);
    ld end1 = s1 + au1 * projmagnitude;
    ld end2 = s2 + au2 * projmagnitude;

    ld dist;
    if (x1 <= end1 && end1 <= x2 && y1 <= end2 && end2 <= y2) { // inside
        dist = sqrtl(vmag * vmag - projmagnitude * projmagnitude);
    }
    else { // outside: dist is vmag
        dist = vmag;
    }
    print(end1, end2, dist);
    return dist;
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
    
    // How to deal with vertical lines: just don't
    // everything is a vector now, who cares about y = mx + b

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
        
        // let vector A = <x2 - x1, y2 - y1>, B = <x4 - x3, y4 - y3>
        // then we can easily compute the distance 
        ld ans = 1e18;

        ld a1 = x2 - x1, a2 = y2 - y1;
        ld b1 = x4 - x3, b2 = y4 - y3;

        // I will check the 4 endpoints
        ld va1 = x3 - x1, va2 = y3 - y1; // p1 -> p3
        ld vb1 = x3 - x2, vb2 = y3 - y2; // p2 -> p3

        ld vc1 = x4 - x1, vc2 = y4 - y1; // p1 -> p4
        ld vd1 = x4 - x2, vd2 = y4 - y2; // p2 -> p4

        ld ve1 = x1 - x3, ve2 = y1 - y3; // p3 -> p1
        ld vf1 = x1 - x4, vf2 = y1 - y4; // p4 -> p1

        ld vg1 = x2 - x3, vg2 = y2 - y3; // p3 -> p2
        ld vh1 = x2 - x4, vh2 = y2 - y4; // p4 -> p2
        
        
        // check all 8 candidates
        ld amag = sqrtl(a1 * a1 + a2 * a2);
        ld au1 = a1 / amag, au2 = a2 / amag; // au = a unit vector
        
        ld bmag = sqrtl(b1 * b1 + b2 * b2);
        ld bu1 = b1 / bmag, bu2 = b2 / bmag; // bu = b unit vector


        // point = orig + proja (v) = orig + anorm[(a . v) / ||a||]

        // now there are edge cases if p1 == p2

        if ((x1 == x2 && y1 == y2) && (x3 == x4 && y1 == y4)) {
            ld dist = sqrtl((x1 - x3) * (x1 - x3) + (y1 - y3) * (y1 - y3));
            print("c1: ", dist);  
        }
        else if (x1 == x2 && y1 == y2) { 
            // only project onto b
            ld dist = distance(bu1, bu2, ve1, ve2, x3, y3, x3, y3, x4, y4);
            dist = distance(bu1, bu2, vf1, vf2, x4, y4, x3, y3, x4, y4);
            dist = distance(bu1, bu2, vg1, vg2, x3, y3, x3, y3, x4, y4);
            dist = distance(bu1, bu2, vh1, vh2, x4, y4, x3, y3, x4, y4);

        }
        else if (x3 == x4 && y1 == y4) {
            // only project onto a
            ld dist = distance(au1, au2, va1, va2, x1, y1, x1, y1, x2, y2);
            dist = distance(au1, au2, vb1, vb2, x2, y2, x1, y1, x2, y2);
            dist = distance(au1, au2, vc1, vc2, x1, y1, x1, y1, x2, y2);
            dist = distance(au1, au2, vd1, vd2, x2, y2, x1, y1, x2, y2);
        }
        else {
            // projected onto a
            ld dist = distance(au1, au2, va1, va2, x1, y1, x1, y1, x2, y2);
            dist = distance(au1, au2, vb1, vb2, x2, y2, x1, y1, x2, y2);
            dist = distance(au1, au2, vc1, vc2, x1, y1, x1, y1, x2, y2);
            dist = distance(au1, au2, vd1, vd2, x2, y2, x1, y1, x2, y2);

            // projected onto b
            dist = distance(bu1, bu2, ve1, ve2, x3, y3, x3, y3, x4, y4);
            dist = distance(bu1, bu2, vf1, vf2, x4, y4, x3, y3, x4, y4);
            dist = distance(bu1, bu2, vg1, vg2, x3, y3, x3, y3, x4, y4);
            dist = distance(bu1, bu2, vh1, vh2, x4, y4, x3, y3, x4, y4);
        }
        



        space;

    }   



    return 0;
}