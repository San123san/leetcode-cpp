// User function Template for C++

class Solution {
  public:
    vector<vector<int>> sortedMatrix(int N, vector<vector<int>> Mat) {
        // code here
        vector<int> store;
        
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                store.push_back(Mat[i][j]);
            }
        }
        sort(store.begin(), store.end());
        int c = 0;
        
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                Mat[i][j] = store[c++];
            }
        }
        return Mat;
    }
};
