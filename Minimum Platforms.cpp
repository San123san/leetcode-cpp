class Solution {
  public:
    int minPlatform(vector<int>& arr, vector<int>& dep) {
        // code here
        int n = arr.size();
        vector<pair<int, int>> events;
        
        for(int i = 0; i < n; i++) {
            events.push_back({arr[i], 1});
            events.push_back({dep[i], -1}); 
        }
        
        sort(events.begin(), events.end(), [](const pair<int,int>& a, const pair<int,int>& b) {
            if(a.first != b.first) return a.first < b.first;
            return a.second > b.second;
        });
        
        int platforms = 0;
        int maxPlatforms = 0;
        
        for(int i = 0; i < events.size(); i++) {
            platforms += events[i].second; 
            maxPlatforms = max(maxPlatforms, platforms);
        }
        
        return maxPlatforms;
    }
};
