class Solution {
public:
    int solve(int i, int j,int xorVal, vector<vector<int>>& grid,vector<vector<vector<int>>>& dp){
        if(i >= grid.size() || j >= grid[0].size()){
            return INT_MAX;
        }
        xorVal = xorVal ^ grid[i][j];
        if (i == grid.size() - 1 && j == grid[0].size() - 1) {
            return xorVal; 
        }
        if (dp[i][j][xorVal] != -1) {
            return dp[i][j][xorVal];
        }
        
        int right = solve(i, j+1, xorVal, grid, dp);
        int left = solve(i+1, j, xorVal, grid, dp);
        return dp[i][j][xorVal] = min(right, left);
    }
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(1024, -1)));
        
        return solve(0, 0, 0, grid, dp);
    }
};