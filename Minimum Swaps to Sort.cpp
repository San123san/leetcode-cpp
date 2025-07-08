class Solution {
  public:
    // Function to find the minimum number of swaps required to sort the array.
    int minSwaps(vector<int>& arr) {
        // Code here
        vector<int> temp(arr.begin(), arr.end());
        sort(temp.begin(), temp.end());
        
        unordered_map<int, int> pos;
        for(int i = 0; i < arr.size(); i++) {
            pos[arr[i]] = i;
        }
        
        int swaps = 0;
        for(int i = 0; i < arr.size(); i++){
            if (temp[i] != arr[i]){
                int ind = pos[temp[i]];
                swap(arr[i], arr[ind]);
                
                pos[arr[i]] = i;
                pos[arr[ind]] = ind;
                swaps++;
            }
        }
        return swaps;
    }
};
