class Solution {
public:
    vector<pair<int, int>> directions = {
        {2,1}, {1,2}, {-1, 2}, {-2, 1}, {-2, -1}, {-1, -2}, {1, -2}, {2, -1}
    };
    bool backTrack(vector<vector<int>>& grid, int x, int y, int moveNum, int n){
        if(moveNum == n * n){
            return true;
        }
        for(auto [dx, dy] : directions){
            int nx = x + dx;
            int ny = y + dy;

            if(nx >= 0 && ny >= 0 && nx < n && ny < n && grid[nx][ny] == moveNum){
                if(backTrack(grid, nx, ny, moveNum + 1, n)){
                    return true;
                }
            }
        }
        return false;
    }
    bool checkValidGrid(vector<vector<int>>& grid) {
        int n = grid.size();
        if(grid[0][0] != 0) return false;

        return backTrack(grid, 0, 0, 1, n);
    }
};
