// User function Template for C++

class Solution {
  public:
    void solve(vector<vector<int>>& matrix, int n, int m, int xs, int ys, int xd, int yd, vector<vector<int>>& vis, int& res, int sum){
        if(xs == xd && ys == yd){
            res = max(res, sum);
            return;
        }
        if(xs < 0 || xs >= n || ys < 0 || ys >= m || vis[xs][ys] == 1) return;
        
        // up
        if(xs > 0 && vis[xs-1][ys] != 1 && matrix[xs-1][ys] == 1){
            vis[xs][ys] = 1;
            solve(matrix, n, m, xs - 1, ys, xd, yd, vis, res, sum + 1);
            vis[xs][ys] = 0;
        }
        
        // down
        if(xs < n - 1 && vis[xs+1][ys] != 1 && matrix[xs+1][ys] == 1){
            vis[xs][ys] = 1;
            solve(matrix, n, m, xs + 1, ys, xd, yd, vis, res, sum + 1);
            vis[xs][ys] = 0;
        }
        
        //left
        if(ys > 0 && vis[xs][ys-1] != 1 && matrix[xs][ys-1] == 1){
            vis[xs][ys] = 1;
            solve(matrix, n, m, xs, ys - 1, xd, yd, vis, res, sum + 1);
            vis[xs][ys] = 0;
        }
        
        if(ys < m - 1 && vis[xs][ys+1] != 1 && matrix[xs][ys+1] == 1){
            vis[xs][ys] = 1;
            solve(matrix, n, m, xs, ys + 1, xd, yd, vis, res, sum + 1);
            vis[xs][ys] = 0;
        }
    }
    int longestPath(vector<vector<int>> matrix, int xs, int ys, int xd, int yd) {
        // code here
        int res = 0;
        int n = matrix.size();
        int m = matrix[0].size();
        if(matrix[xs][ys] == 0) return -1;
        vector<vector<int>> vis(n, vector<int>(m, 0));
        solve(matrix, n, m, xs, ys, xd, yd, vis, res, 0);
        
        if(res == 0) return -1;
        return res;
    }
};
