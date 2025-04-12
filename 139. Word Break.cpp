#include <iostream>
#include <vector>
#include <unordered_set>
#include <string>
using namespace std;

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.length();
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        unordered_set<int> dp; 
        string sto = "";

        for(int i = 0; i < n; i++){
            sto += s[i];
            if(dict.find(sto) != dict.end()){
                dp.insert(i); 
            }

            for(int j = 0; j < i; j++){
                if(dp.find(j) != dp.end()){
                    string sub = s.substr(j + 1, i - j);
                    if(dict.find(subk) != dict.end()){
                        dp.insert(i);
                        break;
                    }
                }
            }
        }

        return dp.find(n - 1) != dp.end(); // if we can reach end
    }
};
