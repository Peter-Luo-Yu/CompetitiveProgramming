#include <iostream>
#include <vector>
#include <string>
using namespace std;

void min_reversals_needed(int N, string cows) {
    vector<int> prefixG(N + 1, 0), prefixH(N + 1, 0);
    
    // Compute prefix sums for 'G' and 'H'
    for (int i = 0; i < N; ++i) {
        prefixG[i + 1] = prefixG[i] + (cows[i] == 'G');
        prefixH[i + 1] = prefixH[i] + (cows[i] == 'H');
    }
    
    // Initial count of 'G' in even positions
    int current_g_count = 0;
    for (int i = 1; i < N; i += 2) {
        if (cows[i] == 'G') current_g_count++;
    }
    
    int max_g_count = current_g_count;
    int min_reversals = 0;
    
    // Try reversing even-length prefixes
    for (int j = 2; j <= N; j += 2) { // j is the prefix length
        int g_in_prefix = prefixG[j];
        int h_in_prefix = prefixH[j];
        
        // Compute new 'G' count in even positions after reversing
        int new_g_count = g_in_prefix - current_g_count + (N / 2 - h_in_prefix);
        
        if (new_g_count > max_g_count) {
            max_g_count = new_g_count;
            min_reversals = 1; // Since one reversal achieves the best count
        }
    }
    
    cout << min_reversals << endl;
}

int main() {
    int N;
    string cows;
    cin >> N >> cows;
    min_reversals_needed(N, cows);
    return 0;
}