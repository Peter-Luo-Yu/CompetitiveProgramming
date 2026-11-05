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


#define ll  __int128_t
#define ld long double
#define endl "\n"


int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    // This problem isn't too hard to understand, but the implementation had
    // to be done cleverly to avoid the TLE verdict.

    // Essentially, it is another brute force:
    // for each string, for each removed character, for each other string:

    // you check if the string with one removed char equals another string already present
    // Optimization: you realize a hash value is just an integer
    // How to quickly find if an integer already exists in set of integers?
    // Use binary search instead of linear search.

    int n; cin >> n;
    vector<string> arr (n);

    ll A = 1000000007, B = 1000000000000000003;
    vector<vector<ll>> hash (n);
    vector<ll> p(1e6 + 5); // power
    p[0] = 1;
    for (int i = 1; i < 1e6 + 5; i++) {
        p[i] = (p[i - 1] * A) % B;
    }

    //print(p);
    
    vector<ll> vals (n); // just to store the hash of all strings

    for (int j = 0; j < n; j++) {
        cin >> arr[j];
        
        vector<ll> h(arr[j].size());    // hash of each prefix

        
        h[0] = arr[j][0] - 'a' + 1;
        for (int i = 1; i < arr[j].size(); i++) {
            h[i] = (h[i - 1] * A + (arr[j][i] - 'a' + 1)) % B;
        }
        
        //print(h);
        
        hash[j] = h;

        vals[j] = h[arr[j].size() - 1];     
    }

    //print(hash);

    // don't forget to sort you dummy, you can't BS on an unsorted array.
    sort (vals.begin(), vals.end());
    
    vector<bool> ans (n);
    // for each word
    for (int i = 0; i < n; i++) {
        // we delete the jth letter
        
        vector<ll> h = hash[i];    // hash of each prefix


        for (int j = 0; j < arr[i].size(); j++) {

            print(j);
            
            
            // the difficult part is computing the hash value of the new string
            // new = before | deleted char |  after 


            
            ll before = (j == 0) ? 0 : h[j - 1];

            //print(h, arr[i].size(), j);
            
            ll after = (j == arr[i].size() - 1) ? 0 : 
                       ((h[arr[i].size() - 1] - (h[j] * p[arr[i].size() - 1 - j] % B)) + B) % B;

            
            // before has to be multiplied by the len of after
            ll val = ((before * p[arr[i].size() - 1 - j]) % B + after) % B;


            int idx = lower_bound(vals.begin(), vals.end(), val) - vals.begin();
            print(idx);

            if (idx < n && vals[idx] == val) {
                
                ans[i] = true;
            }
            
            space;
                
        }

        space;

    }

    print(ans);


    bool notypo = true;
    for (int i = 0; i < n; i++) {
        if (ans[i]) {
            cout << arr[i] << endl;
            notypo = false;
        }
    }

    if (notypo) {
        cout << "NO TYPOS" << endl;
    }
    
        

    return 0;
}