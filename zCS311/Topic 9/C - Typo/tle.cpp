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

    int n; cin >> n;
    vector<string> arr (n);

    ll A = 999999999999999989, B = 1e18 + 3;
    vector<vector<ll>> hash (n);
    vector<ll> p(1e6 + 5); // power
    p[0] = 1;
    for (int i = 1; i < 1e6 + 5; i++) {
        p[i] = (p[i - 1] * A) % B;
    }

    //print(p);
    
    
    for (int j = 0; j < n; j++) {
        cin >> arr[j];
        
        vector<ll> h(arr[j].size());    // hash of each prefix

        
        h[0] = arr[j][0] - 'a' + 1;
        for (int i = 1; i < arr[j].size(); i++) {
            h[i] = (h[i - 1] * A + (arr[j][i] - 'a' + 1)) % B;
        }
        
        //print(h);
        
        hash[j] = h;

        
    }

    print(hash);

    
    
    vector<bool> ans (n);
    // for each word
    for (int i = 0; i < n; i++) {

        vector<ll> h = hash[i];    // hash of each prefix

        // we delete the jth letter
        for (int j = 0; j < arr[i].size(); j++) {

            print(j);
            
          

            // the difficult part is computing the hash value of the new string
            // new = before + deleted char +  after 


            
            ll before = (j == 0) ? 0 : h[j - 1];

            //print(h, arr[i].size(), j);
            
            ll after = (j == arr[i].size() - 1) ? 0 : 
                       ((h[arr[i].size() - 1] - (h[j] * p[arr[i].size() - 1 - j] % B)) + B) % B;

            
            // before has to be multiplied by the len of after
            ll val = ((before * p[arr[i].size() - 1 - j]) % B + after) % B;


            
            for (int k = 0; k < n; k++) {
                if (i == k) continue;

                print(val, hash[k][arr[k].size() - 1]);

                if (val == hash[k][arr[k].size() - 1]) {
                    ans[i] = true;
                    break;
                }   
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