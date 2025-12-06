class Solution {
public:
    int maxStop(int n, int m, vector<vector<int>> &trains) {
        // Group trains by their required platform number
        vector<vector<pair<int, int>>> platforms(m + 1);
        
        for (auto& train : trains) {
            int arrival = train[0];
            int departure = train[1];
            int platform = train[2];
            // Store as (departure, arrival) for sorting by departure time
            platforms[platform].emplace_back(departure, arrival);
        }
        
        int totalTrains = 0;
        
        // For each platform, apply greedy activity selection
        for (int p = 1; p <= m; ++p) {
            if (platforms[p].empty()) continue;
            
            // Sort by departure time (first element of pair)
            sort(platforms[p].begin(), platforms[p].end());
            
            int count = 1;  // First train always selected
            int lastDep = platforms[p][0].first;
            
            for (size_t j = 1; j < platforms[p].size(); ++j) {
                // Can select if arrival >= previous departure
                if (platforms[p][j].second >= lastDep) {
                    count++;
                    lastDep = platforms[p][j].first;
                }
            }
            
            totalTrains += count;
        }
        
        return totalTrains;
    }
};
