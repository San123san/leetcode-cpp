// User function Template for C++

class Solution {
  public:
  
    struct meeting {
        int startTime, endTime, pos;
    };
    
    static bool compare(meeting m1, meeting m2){
        return m1.endTime < m2.endTime;
    }
    
    vector<int> maxMeetings(int N, vector<int> &S, vector<int> &F) {
        vector<int> res;
        
        vector<meeting> meets(N);
        for(int i = 0; i < N; i++){
            meets[i].startTime = S[i];
            meets[i].endTime = F[i];
            meets[i].pos = i + 1;
        }
        
        sort(meets.begin(), meets.end(), compare);
        
        int currTime = -1;
        
        for(int i = 0; i < N; i++) {
            if(meets[i].startTime > currTime) {
                currTime = meets[i].endTime;
                res.push_back(meets[i].pos);
            }
        }
        sort(res.begin(), res.end());
        return res;
    }
};
