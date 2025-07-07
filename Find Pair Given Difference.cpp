
class Solution {
  public:
    bool findPair(vector<int> &arr, int x) {
        // code here
        unordered_set<int> findP;
        
        for(int num : arr) {
            if (findP.find(num+x) != findP.end() || findP.find(num-x) != findP.end()) {
                return true;
            }
            
            findP.insert(num);
        }
        return false;
    }
};
