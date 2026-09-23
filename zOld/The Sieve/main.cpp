#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl "\n"
#define print(arr) for (auto x : arr) cout << x << ' '; cout << '\n';

int main() {

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n; cin >> n;

    vector<int> primes; 
    vector<bool> is_prime (n+1, true);
    is_prime[0] = is_prime[1] = false;

    for (int i = 2; i * i <= n; i++){
        if (is_prime[i]){
            for (int j = i * i; j <= n; j+=i){
                is_prime[j] = false;
            }
            
        }
    }
    //print(is_prime);

    for (int i = 2; i <= n; i++){
        if (is_prime[i]){
            primes.push_back(i);
        }
    }

    
    cout << "Biggest: " << primes[primes.size() - 1] << endl;

    return 0;
}