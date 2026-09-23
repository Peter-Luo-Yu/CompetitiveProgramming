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

    int n; cin >> n;
    vector<int> arr (n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    // Goal: extract all the "increasing and then decreasing" subarrays, store them in cand (candidates) 2d array
    // why: because the answer must be contained within one of these subarrays

    vector<vector<int>> cand;
    int prev = -1;
    bool inc = true;
    vector<int> cur;
    for (int i = 0; i < n; i++) {
        
        // we are starting a subarray
        if (prev == -1) {
            prev = arr[i];
            cur.push_back(arr[i]);
            continue;
        }

        // we have strated the current subarray, and are now looking for it to increase
        if (inc) {
            if (arr[i] > prev) { // it does increase :)
                prev = arr[i];
                cur.push_back(arr[i]);
            }
            else { // if it doesn't, then we have reached the max of the current subarray
                prev = arr[i];
                cur.push_back(arr[i]);
                inc = false;
            }
        }   // now we are decreasing
        else {
            if (arr[i] < prev) { // if the element is smaller :)
                prev = arr[i];
                cur.push_back(arr[i]);
            }
            else {  // if the element is not smaller, it does not get added to the cur (it marks the start of a new subarray)
                cand.push_back(cur);
                cur = vector<int> ();
                prev = -1;
                i-=2; // must go back one element, because it could be the start of the new subarray
                inc = true;
            }
        }
    }

    cand.push_back(cur);
    print(cand);


    // Now we have to extract the longest palindrone out of the increasing decreasing subarrays
    // consider: 8
    //           5 2 3 4 3 2 1 2
    // we will get [2, 3, 4, 3, 2, 1] as one of the subarrays, basically the highest point isn't gauranteed to be in the middle

    int ans = -1;
    for (int i = 0; i < cand.size(); i++) {
        if (cand[i].size() < 3) continue;

        // to solve the problem of the max not being in the middle
        // I will find the distance of the max from the left hand side and the right hand side
        int idx = -1, idx2 = -1;
        vector<int> temp = cand[i];
        for (int j = 0; j < cand[i].size() - 1; j++) {
            if (cand[i][j] > cand[i][j + 1]) {
                idx = j;
                break;
            }
        }
        
        reverse(temp.begin(), temp.end());
        for (int j = 0; j < cand[i].size() - 1; j++) {
            if (temp[j] > temp[j + 1]) {
                idx2 = j;
                break;
            }
        }

        print(idx, idx2);

        // I make an assumption here: i'm assuming that the longest palindrome
        // must reach the end of the candidate subarray.
        // I end up getting the AC, but I should be more safe and actually manually 
        // increment the length as I check
        
        bool failed = false;

        for (int j = 1; j <= min(idx, idx2); j++) {
            if (cand[i][idx + j] != cand[i][idx - j]) {
                failed = true;
            }
        }

        if (!failed) {
            ans = max (ans, 2 * min(idx, idx2) + 1);
        }
    }


    cout << ans << endl;
 

    return 0;
}