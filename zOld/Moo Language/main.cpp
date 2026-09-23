#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <set>
#include <map>

using namespace std;

void print(vector<string> list){
    for (int i = 0; i < list.size(); i++) {
        cout << list[i] << " ";
    } 
    cout << endl;
}

int main() {

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int t; cin >> t; 

    

    for (int i = 0; i < t; i++){
        int N, C, P; cin >> N >> C >> P;
        vector<string> solutions;
        vector<string> orig_noun, orig_tverb, orig_iverb, orig_conj;

        int max = 0;
        int solution_index = -1;

        for (int i = 0; i < N; i++){
            string word, type;
            cin >> word >> type;

            if (type == "noun") {
                orig_noun.push_back(word);
            }
            if (type == "transitive-verb") {
                orig_tverb.push_back(word);
            }
            if (type == "intransitive-verb") {
                orig_iverb.push_back(word);
            }
            if (type == "conjunction") {
                orig_conj.push_back(word);
            }
        }
        
        int num_comma = C; int num_period = P;

        // make sure the answer isn't already 0
        if (orig_noun.size() == 0 || (orig_tverb.size() <= 0 && orig_iverb.size() <= 0) || (orig_tverb.size() > 0 && orig_noun.size()< 2) || P <= 0){
            cout << max << endl;
            cout << endl;
            continue;
        }
        
        if (orig_tverb.size() > 0){      // select one transition verb
            int words = 2;

            string sentence = "";
            sentence += orig_noun[0]; sentence += " ";
            sentence += orig_tverb[0]; sentence += " ";
            
            orig_noun.erase(orig_noun.begin());         // remove Bessie (first noun)
            orig_tverb.erase(orig_tverb.begin());       // remove the first tverb
            
            /* Bessie and tverb got removed
            for (int i = 0; i < orig_noun.size(); i++){
                cout << orig_noun[i] << " ";
            }
            cout << endl; cout << orig_tverb.size();
            */
            
            //cout << "BEFORE: " << sentence << endl;

            for (int i = 1; i <= orig_noun.size(); i++) { // selected to put i number of nouns on the trans verb.
                vector<string> noun = orig_noun, tverb = orig_tverb, iverb = orig_iverb, conj = orig_conj;
                string s = sentence; 
                int periods = num_period; int commas = num_comma;

                int count = words;
                //print(noun); print(tverb); print(iverb); print(conj);
                
                if (i > 1 && num_comma < i - 1){         // not enough COMMAs
                    continue; 
                }

                for (int j = 0; j < i; j++) {           // add in the nouns
                    if (j != i-1){
                        s += noun[0] + ", "; 
                        commas--;
                    } else {
                        s += noun[0] + " ";
                    }
                    count++;
                    noun.erase(noun.begin());
                }
                
                if (conj.size() > 0){                   // use conj if possible
                    s += conj[0];
                    conj.erase(conj.begin());
                    count++;

                } else {
                    s += ".";
                    periods--;
                }

                //cout << "1: " << s << " -count: " << count << endl;

                bool can_conj = false;

                while (tverb.size() > 0 && noun.size() >= 2 || iverb.size() > 0 && noun.size() >= 1){
                    if (tverb.size() > 0 && noun.size() >= 2){
                        s += " " + noun[0];
                        noun.erase(noun.begin());
                        s += " " + tverb[0];
                        tverb.erase(tverb.begin());
                        s += " " + noun[0];
                        noun.erase(noun.begin());
                        count += 3;
                    }
                    else if (iverb.size() > 0 && noun.size() >= 1){
                        s += " " + noun[0];
                        noun.erase(noun.begin());
                        s += " " + iverb[0];
                        iverb.erase(iverb.begin());
                        count += 2;
                    }

                    if (can_conj && conj.size() > 0 && (noun.size() > 0 && iverb.size() > 0 || noun.size() > 1 && tverb.size() > 0)){                   // use conj if possible
                        s += " " + conj[0];
                        conj.erase(conj.begin());
                        count++;
                        can_conj = !can_conj;
                    } else {
                        s += ".";
                        periods--;
                        can_conj = !can_conj;
                    }

                }
                
                //cout << "2: " << s << " -count: " << count << endl;

                if (count > max && periods >= 0 && commas >= 0){
                    max = count;
                    solution_index++;
                    solutions.push_back(s);
                }
            } 
        } 
        cout << max << endl;
        if (solution_index == -1){
            cout << 0 << endl;
            cout << endl;
        } else {
            cout << solutions[solution_index] << endl;
        }

    }
    
    return 0;
}