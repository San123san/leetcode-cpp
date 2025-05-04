class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int n = customers.size();

        int maxUnsat = 0;
        int currUnsat = 0;
        for(int i = 0; i < minutes; i++){
            currUnsat += customers[i] * grumpy[i];
        }

        maxUnsat = currUnsat;

        int i = 0; 
        int j = minutes;

        while(j < n){
            // currUnsat += customers[j] * grumpy[j];
            // currUnsat -= customers[i] * grumpy[i];
            currUnsat = -(customers[i] * grumpy[i]) + currUnsat + customers[j] * grumpy[j];
            maxUnsat = max(currUnsat, maxUnsat);
            i++; j++;
        }

        int res = maxUnsat;
        for(int i = 0; i < n; i++){
            res += customers[i] * (1 - grumpy[i]);
        }

        return res;
    }
};
