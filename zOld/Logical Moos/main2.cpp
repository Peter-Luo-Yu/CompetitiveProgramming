#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    int n, q;
    cin >> n >> q;
    
    vector<string> statement(n);
    for (int i = 0; i < n; i++) {
        cin >> statement[i];
    }
    
    // Parse the boolean statement into OR blocks
    vector<vector<pair<bool, int>>> orBlocks; // Each element is (value, position)
    vector<pair<bool, int>> currentAndBlock;
    
    for (int i = 0; i < n; i += 2) {
        bool value = (statement[i] == "true");
        
        if (i == 0 || (i >= 2 && statement[i - 1] == "or")) {
            // Start a new AND block
            if (!currentAndBlock.empty()) {
                orBlocks.push_back(currentAndBlock);
                currentAndBlock.clear();
            }
        }
        
        currentAndBlock.push_back({value, i});
        
        // If next operator is OR or we're at the end, finish this AND block
        if (i + 1 >= n || (i + 1 < n && statement[i + 1] == "or")) {
            orBlocks.push_back(currentAndBlock);
            currentAndBlock.clear();
        }
    }
    
    // Add the last block if it's not empty
    if (!currentAndBlock.empty()) {
        orBlocks.push_back(currentAndBlock);
    }
    
    // Calculate which blocks evaluate to true
    vector<bool> blockEvals(orBlocks.size());
    for (int i = 0; i < orBlocks.size(); i++) {
        bool blockValue = true;
        for (auto& term : orBlocks[i]) {
            blockValue &= term.first;
        }
        blockEvals[i] = blockValue;
    }
    
    // Find first and last true blocks
    int firstTrueBlock = -1, lastTrueBlock = -1;
    for (int i = 0; i < blockEvals.size(); i++) {
        if (blockEvals[i]) {
            if (firstTrueBlock == -1) firstTrueBlock = i;
            lastTrueBlock = i;
        }
    }
    
    string result;
    
    for (int queryIdx = 0; queryIdx < q; queryIdx++) {
        int l, r;
        string targetStr;
        cin >> l >> r >> targetStr;
        
        // Convert to 0-indexed
        l--;
        r--;
        
        bool targetValue = (targetStr == "true");
        
        // Find affected blocks and whether they're fully or partially affected
        vector<int> affectedBlocks;
        vector<bool> fullyAffected(orBlocks.size(), false);
        
        for (int blockIdx = 0; blockIdx < orBlocks.size(); blockIdx++) {
            bool affected = false;
            int affectedTerms = 0;
            
            for (auto& term : orBlocks[blockIdx]) {
                int pos = term.second;
                if (l <= pos && pos <= r) {
                    affected = true;
                    affectedTerms++;
                }
            }
            
            if (affected) {
                affectedBlocks.push_back(blockIdx);
                fullyAffected[blockIdx] = (affectedTerms == orBlocks[blockIdx].size());
            }
        }
        
        bool isPossible = false;
        
        if (targetValue) {  // Want result to be true
            // Case 1: If any unaffected block is true, result stays true
            bool hasUnaffectedTrueBlock = false;
            for (int i = 0; i < orBlocks.size(); i++) {
                if (blockEvals[i] && find(affectedBlocks.begin(), affectedBlocks.end(), i) == affectedBlocks.end()) {
                    hasUnaffectedTrueBlock = true;
                    break;
                }
            }
            
            // Case 2: If any affected block can be replaced with true
            bool canMakeBlockTrue = false;
            for (int blockIdx : affectedBlocks) {
                if (fullyAffected[blockIdx]) {
                    canMakeBlockTrue = true;
                    break;
                }
            }
            
            isPossible = hasUnaffectedTrueBlock || canMakeBlockTrue;
        } else {  // Want result to be false
            // All blocks must evaluate to false
            
            // Check if unaffected blocks are all false
            bool allUnaffectedBlocksFalse = true;
            for (int i = 0; i < orBlocks.size(); i++) {
                if (blockEvals[i] && find(affectedBlocks.begin(), affectedBlocks.end(), i) == affectedBlocks.end()) {
                    allUnaffectedBlocksFalse = false;
                    break;
                }
            }
            
            // Check if affected blocks can all be made false
            bool allAffectedBlocksCanBeFalse = true;
            for (int blockIdx : affectedBlocks) {
                if (fullyAffected[blockIdx]) {
                    // Can replace with false
                    continue;
                }
                
                // For partially affected blocks, we need at least one unaffected false term
                bool hasUnaffectedFalse = false;
                for (auto& term : orBlocks[blockIdx]) {
                    bool value = term.first;
                    int pos = term.second;
                    if ((pos < l || pos > r) && !value) {
                        hasUnaffectedFalse = true;
                        break;
                    }
                }
                
                if (!hasUnaffectedFalse) {
                    allAffectedBlocksCanBeFalse = false;
                    break;
                }
            }
            
            isPossible = allUnaffectedBlocksFalse && allAffectedBlocksCanBeFalse;
        }
        
        result += (isPossible ? "Y" : "N");
    }
    
    cout << result << endl;
    return 0;
}