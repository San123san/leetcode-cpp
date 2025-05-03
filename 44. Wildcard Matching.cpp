class Solution {
public:
    bool isMatch(string s, string p) {
        int sIdx = 0;
        int pIdx = 0;
        int lastIndexStar = -1;
        int lastIndexStarPosition = -1;

        while(sIdx < s.length()){
            if(pIdx < p.length() && (p[pIdx] == s[sIdx] || p[pIdx] == '?')){
                pIdx++;
                sIdx++;
            }
            else if(pIdx < p.length() && p[pIdx] == '*'){
                lastIndexStar = pIdx;
                lastIndexStarPosition = sIdx;
                pIdx++;
            }
            else if(lastIndexStarPosition != -1){
                pIdx = lastIndexStar + 1;
                lastIndexStarPosition++;
                sIdx = lastIndexStarPosition;
            }
            else{
                return false;
            }
        }
        
        while(pIdx < p.length() && p[pIdx] == '*'){
            pIdx++;
        }

        return pIdx == p.length();
    }
};
