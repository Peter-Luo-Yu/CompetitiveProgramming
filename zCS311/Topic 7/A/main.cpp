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


#define ll long long
#define ld long double
#define endl "\n"

#define eps (ld) 1e-6


// projects v onto unit vector a, also needs the starting point of v and a
ld distance (ld au1, ld au2, ld v1, ld v2, ld s1, ld s2, ld x1, ld y1, ld x2, ld y2) {
    //ld amag = 1;
    ld vmag2 = (v1 * v1 + v2 * v2);
    ld projmagnitude = (au1 * v1 + au2 * v2);
    ld end1 = s1 + au1 * projmagnitude;
    ld end2 = s2 + au2 * projmagnitude;

    ld dist;
    // correct way to check if (end1, end2) is on line segment (x1, y1) -> (x2, y2)
    ld lx = min(x1, x2), hx = max(x1, x2);
    ld ly = min(y1, y2), hy = max(y1, y2);

    if (lx - eps <= end1 && end1 <= hx + eps && ly - eps <= end2 && end2 <= hy + eps) { // inside
        dist = sqrtl(vmag2 - projmagnitude * projmagnitude);
    }
    else { // outside: dist is vmag
        dist = sqrtl(vmag2);
    }

    print(end1, end2, dist);
    return dist;
}

// since we are in 2d, it just returns the k component of cross product because i and j are 0.
ld cross (ld u1, ld u2, ld v1, ld v2) {
    ld res = u1 * v2 - u2 * v1;
    print("cross: ", res);
    return res;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

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

        // now there are edge cases if p1 == p2 or p3 == p4

        if ((x1 == x2 && y1 == y2) && (x3 == x4 && y3 == y4)) { // dist between 2 points
            ld dist = sqrtl((x1 - x3) * (x1 - x3) + (y1 - y3) * (y1 - y3));
            ans = min(ans, dist);
            print("c1: ", dist);  
            cout << ans << endl;
            continue;
        }

        else if (x1 == x2 && y1 == y2) { // dist between point and line
            // only project onto b
            ld dist = distance(bu1, bu2, ve1, ve2, x3, y3, x3, y3, x4, y4);
            ans = min(ans, dist);
            dist = distance(bu1, bu2, vf1, vf2, x4, y4, x3, y3, x4, y4);
            ans = min(ans, dist);
            dist = distance(bu1, bu2, vg1, vg2, x3, y3, x3, y3, x4, y4);
            ans = min(ans, dist);
            dist = distance(bu1, bu2, vh1, vh2, x4, y4, x3, y3, x4, y4);
            ans = min(ans, dist);

        }
        else if (x3 == x4 && y3 == y4) {
            // only project onto a
            ld dist = distance(au1, au2, va1, va2, x1, y1, x1, y1, x2, y2);
            ans = min(ans, dist);
            dist = distance(au1, au2, vb1, vb2, x2, y2, x1, y1, x2, y2);
            ans = min(ans, dist);
            dist = distance(au1, au2, vc1, vc2, x1, y1, x1, y1, x2, y2);
            ans = min(ans, dist);
            dist = distance(au1, au2, vd1, vd2, x2, y2, x1, y1, x2, y2);
            ans = min(ans, dist);
        }
        else { // I also have to check if the line segments intersect
            // projected onto a
            ld dist = distance(au1, au2, va1, va2, x1, y1, x1, y1, x2, y2);
            ans = min(ans, dist);
            dist = distance(au1, au2, vb1, vb2, x2, y2, x1, y1, x2, y2);
            ans = min(ans, dist);
            dist = distance(au1, au2, vc1, vc2, x1, y1, x1, y1, x2, y2);
            ans = min(ans, dist);
            dist = distance(au1, au2, vd1, vd2, x2, y2, x1, y1, x2, y2);
            ans = min(ans, dist);

            // projected onto b
            dist = distance(bu1, bu2, ve1, ve2, x3, y3, x3, y3, x4, y4);
            ans = min(ans, dist);
            dist = distance(bu1, bu2, vf1, vf2, x4, y4, x3, y3, x4, y4);
            ans = min(ans, dist);
            dist = distance(bu1, bu2, vg1, vg2, x3, y3, x3, y3, x4, y4);
            ans = min(ans, dist);
            dist = distance(bu1, bu2, vh1, vh2, x4, y4, x3, y3, x4, y4);
            ans = min(ans, dist);
        }


        // Source: the cses book if nice with the cross products
        bool intersect = false;
        // Step 1: overlap, check 3 cross products and they have to be 0

        // check (p1p2 x p3p4) (p1p3 x p2p4) (p1p4 x p2p3)
        bool one = (abs(cross(a1, a2, b1, b2)) < eps);
        bool two = (abs(cross(va1, va2, vd1, vd2)) < eps);
        bool three = (abs(cross(vc1, vc2, vb1, vb2)) < eps);

        if (one && two && three) {
            // correct way to check for intersection: imagine bounding boxes
            // [a, b] overlap with [c, d], need >= left endpts and <= right endpts
            // [max(a, c) <= min(b, d)] 
            
            bool Xoverlap = max(min(x1, x2), min(x3, x4)) <= min(max(x1, x2), max(x3, x4));
            bool Yoverlap = max(min(y1, y2), min(y3, y4)) <= min(max(y1, y2), max(y3, y4));
            if (Xoverlap && Yoverlap) {
                ans = 0;
                intersect = true;
            }
        }

        // Step 2: check if the endpoints are the same
        bool ac = (x1 == x3) && (y1 == y3);
        bool ad = (x1 == x4) && (y1 == y4);
        bool bc = (x2 == x3) && (y2 == y3);
        bool bd = (x2 == x4) && (y2 == y4);

        if (ac || ad || bc || bd) {
            ans = 0;
            intersect = true;
        }

        // Step 3: both lines - other two points have to be on opposite sides

        // 3a: let a -> b be the line
        // I will always cross with point a first
        
        ld crossC = cross(va1, va2, vb1, vb2); // p1p3 x p2p3
        ld crossD = cross(vc1, vc2, vd1, vd2); // p1p4 x p2p4

        // 3b: let c -> d be line
        // cross with point c first
        
        ld crossA = cross(ve1, ve2, vf1, vf2); // p3p1 x p4p1
        ld crossB = cross(vg1, vg2, vh1, vh2); // p3p2 x p4p2

        bool oppo1 = (crossC * crossD < -eps);
        bool oppo2 = (crossA * crossB < -eps);

        if (oppo1 && oppo2) {
            ans = 0;
            intersect = true;
        }
    
        cout << fixed << setprecision(2) << ans << endl;
        
        //print(ans);


        space;

    }   



    return 0;
}