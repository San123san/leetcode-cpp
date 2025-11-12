class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();

        int totalGas = accumulate(begin(gas), end(gas), 0);
        int totalCost = accumulate(begin(cost), end(cost), 0);

        if(totalGas < totalCost) return -1;

        int res_idx = 0;
        int total = 0;

        for(int i = 0; i < n; i++){
            total += gas[i] - cost[i];

            if(total < 0){
                res_idx = i + 1;
                total = 0;
            }
        }
        return res_idx;
    }
};
