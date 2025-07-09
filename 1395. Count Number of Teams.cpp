class Solution {
public:
    int numTeams(vector<int>& rating) {
        int count = 0;
        int n = rating.size();

        for(int j = 1; j < n - 1; j++) {
            int leftS = 0, rightL = 0;
            int leftL = 0, rightS = 0;

            for(int i = 0; i < j; i++) {
                if(rating[i] < rating[j]) leftS++;
                if(rating[i] > rating[j]) leftL++;
            }

            for(int k = j + 1; k < n; k++) {
                if(rating[k] > rating[j]) rightL++;
                if(rating[k] < rating[j]) rightS++;
            }

            count += leftS * rightL;
            count += leftL * rightS;
        }
        return count;
    }
};
