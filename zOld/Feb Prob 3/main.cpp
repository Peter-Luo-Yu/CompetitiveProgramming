#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

// Recursive function to check if a sequence can be generated with k PRINT statements
bool can_generate(const vector<int>& sequence, int k) {
    int n = sequence.size();
    
    // Base cases
    if (n == 0) return true;
    if (k == 0) return false;
    
    // If all elements are the same, we need only 1 PRINT statement
    bool all_same = true;
    for (int i = 1; i < n; i++) {
        if (sequence[i] != sequence[0]) {
            all_same = false;
            break;
        }
    }
    if (all_same) return true;
    
    // Try to find repeating patterns
    for (int pattern_len = 1; pattern_len <= n/2; pattern_len++) {
        if (n % pattern_len != 0) continue;
        
        bool is_pattern = true;
        for (int i = 0; i < n; i++) {
            if (sequence[i] != sequence[i % pattern_len]) {
                is_pattern = false;
                break;
            }
        }
        
        if (is_pattern) {
            // Extract the pattern and check if it can be generated with k PRINT statements
            vector<int> pattern(sequence.begin(), sequence.begin() + pattern_len);
            return can_generate(pattern, k);
        }
    }
    
    // Try partitioning the sequence
    for (int cut = 1; cut < n; cut++) {
        vector<int> left(sequence.begin(), sequence.begin() + cut);
        vector<int> right(sequence.begin() + cut, sequence.end());
        
        for (int used_k = 1; used_k < k; used_k++) {
            if (can_generate(left, used_k) && can_generate(right, k - used_k)) {
                return true;
            }
        }
    }
    
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    
    while (t--) {
        int n, k;
        cin >> n >> k;
        
        vector<int> sequence(n);
        for (int i = 0; i < n; i++) {
            cin >> sequence[i];
        }
        
        if (can_generate(sequence, k)) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    
    return 0;
}