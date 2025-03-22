class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> subset;
        vector<int> res;
        if(nums1.size() <= nums2.size()){
            for(int i = 0; i < nums1.size(); i++){
                if(subset.find(nums1[i]) != subset.end()){
                    subset[nums1[i]]++;
                } else {
                    subset[nums1[i]] = 1;
                }
            }
            for (int i = 0; i < nums2.size(); i++) {
                if (subset.find(nums2[i]) != subset.end() && subset[nums2[i]] > 0) {
                    res.push_back(nums2[i]);
                    subset[nums2[i]]--;  
                }
            }
        } else {
            for(int i = 0; i < nums2.size(); i++){
                if(subset.find(nums2[i]) != subset.end()){
                    subset[nums2[i]]++;
                } else {
                    subset[nums2[i]] = 1;
                }
            }
            for (int i = 0; i < nums1.size(); i++) {
                if (subset.find(nums1[i]) != subset.end() && subset[nums1[i]] > 0) {
                    res.push_back(nums1[i]);
                    subset[nums1[i]]--;  
                }
            }
        }
        
        return res;
    }
};
