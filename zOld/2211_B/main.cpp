#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define endl "\n"
#define print(arr) for (auto x : arr) cout << x << " "; cout << "\n";
#define print2d(arr) for (int i = 0; i < arr.size(); i++) {for (int j = 0; j < arr[i].size(); j++) {cout << arr[i][j] << " ";} cout << "\n";}
#define printG(adj) for (int i = 0; i < adj.size(); i++) {cout << "i: " << i << " | "; for (int j = 0; j < adj[i].size(); j++) {cout << adj[i][j] << " ";} cout << endl;}
#define printP(arr) for (auto x : arr) {cout << x.first << " " << x.second << "\n";}
#define space cout << "----------" << endl;

int N = 100;

vector<ll> lpf(N, 1); // Stores the lowest prime factor (LPF) of every number

// Sieve of Eratosthenes
void sieve() {
    for (ll i = 2; i < N; i++) {
        if (lpf[i] == 1) {
            lpf[i] = i; // 'i' is a prime
            for (ll j = i * i; j < N; j += i) {
                if (lpf[j] == 1)
                    lpf[j] = i; // Set the lowest prime factor
            }
        }
    }
}

// fact[y] = p, where y is factor and p is exponent of x
void factorize(ll x, map<ll, ll> &fact) {
    while (x > 1) {
        fact[lpf[x]]++;
        x /= lpf[x];
    }
}


int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    sieve();
    //print(lpf);

    int t; cin >> t;

    while (t--) {
        ll x, y; cin >> x >> y;

        ll MOD = 676767677;

        
        vector<int> arr;

        for (int i = 0; i < min(x, y); i++) {
            arr.push_back(-1);
        } 
        for (int i = 0; i < max(x, y); i++) {
            arr.push_back(1);
        }


        ll sum = -1, ans = 0;

        if (x == 0 || y == 0) {
            ll n = max (x, y);

            map<ll, ll> fact;
            factorize(n, fact);

            ll poss = 0;
            for (auto x : fact) {
                //cout << "factor: " << x.first << " " << x.second << endl;

                if (x.first != n) {
                    poss += 1;
                }
            }
            
            if (n == 1) {
                poss += 1;
            } else {
                poss += 2; // account for 1 and itself.
            }
            
            cout << poss << endl;

            int num = 0;
            if (x > 0) {
                num = 1;
            } else {
                num = -1;
            }

            for (int i = 0; i < max(x, y); i++) {
                cout << num << " ";
            } cout << endl;

            //space;

            continue;
        }
        
        for (int i = 1; i < arr.size() - 1; i++) {
            if (sum < 0) {
                sum += arr[i];
            } else {
                sum += arr[i];
                
                //cout << "sum: " << sum << endl;

                ll left = arr.size() - i - 1;
                
                //cout << "left: " << left << endl;

                if (left % sum == 0) {
                    ll n = left/sum + 1;
                    
                    //cout << "n: " << n << endl;

                    map<ll, ll> fact;
                    factorize(n, fact);

                    ll poss = 0;
                    for (auto x : fact) {
                        //cout << "factor: " << x.first << " " << x.second << endl;

                        if (x.first != n) {
                            poss += 1;
                        }
                    }
                    poss++; // account for 1 being a factor

                    //cout << "poss: " << poss << endl;

                    ans += poss;
                    ans %= MOD;
                }
            }
        }

        
        ans += 1;   // having only 1 subarray = orig array
        ans %= MOD;

        cout << ans << endl;

        for (int i = 0; i < x; i++) {
            cout << 1 << " ";
        }
        for (int i = 0; i < y; i++) {
            cout << -1 << " ";
        }
        cout << endl;
        

        //space;

    }
    
    
    return 0;
}
