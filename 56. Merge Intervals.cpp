class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> overlap;
        int n = intervals.size();
        sort(intervals.begin(), intervals.end());
        overlap.push_back(intervals[0]);
        
        for(int i = 1; i < n; i++){
            if ((overlap.back()[0] <= intervals[i][0]) && (overlap.back()[1] >= intervals[i][0])){
                  overlap.back()[1] = max(intervals[i][1], overlap.back()[1]);
            } else {
                overlap.push_back(intervals[i]);
            }
        }
        return overlap;
    }
};
