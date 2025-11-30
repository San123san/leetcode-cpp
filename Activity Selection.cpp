class Solution {
public:
    int activitySelection(vector<int> &start, vector<int> &finish) {
        int n = start.size();
        vector<pair<int, int>> activities;
        
        // Create vector of pairs (start time, finish time)
        for(int i = 0; i < n; i++) {
            activities.push_back({start[i], finish[i]});
        }
        
        // Custom comparator: sort by finish time (second element)
        sort(activities.begin(), activities.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
            return a.second < b.second;
        });
        
        int count = 1;
        int lastFinish = activities[0].second;
        
        for(int i = 1; i < n; i++) {
            if(activities[i].first >= lastFinish) {
                count++;
                lastFinish = activities[i].second;
            }
        }
        
        return count;
    }
};
