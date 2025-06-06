class Solution {
  public:
    void solve(int i, int j, int n, vector<vector<int>>& vis, string path, vector<vector<int>>& maze, vector<string>& ans){
        if(i == n - 1 && j == n - 1){
            ans.push_back(path);
            return;
        }
        
        //down
        if(i + 1 < n && maze[i + 1][j] == 1 && vis[i + 1][j] == 0) {
            vis[i][j] = 1;
            solve(i + 1, j, n, vis, path + 'D', maze, ans);
            vis[i][j] = 0;
        }
        
        //left
        if(j - 1 >= 0 && maze[i][j - 1] == 1 && vis[i][j - 1] == 0){
            vis[i][j] = 1;
            solve(i, j - 1, n, vis, path + 'L', maze, ans);
            vis[i][j] = 0;
        }
        
        //right
        if(j + 1 <  n && maze[i][j + 1] == 1 && vis[i][j + 1] == 0){
            vis[i][j] = 1;
            solve(i, j + 1, n, vis, path + 'R', maze, ans);
            vis[i][j] = 0;
        }
        
        //up
        if(i - 1 >= 0 && maze[i - 1][j] == 1 && vis[i - 1][j] == 0){
            vis[i][j] = 1;
            solve(i - 1, j, n, vis, path + 'U', maze, ans);
            vis[i][j] = 0;
        }
        
    }
    vector<string> ratInMaze(vector<vector<int>>& maze) {
        // code here
        int n = maze.size();
        vector<string> ans;
        vector<vector<int>> vis(n, vector<int>(n,0));
        
        if (maze[0][0] != 1) return ans;
        
        solve(0, 0, n, vis, "", maze, ans);
        return ans;
    }
};
