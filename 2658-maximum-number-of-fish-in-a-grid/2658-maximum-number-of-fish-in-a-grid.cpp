class Solution {
public:
    void dfs(int i, int j,vector<vector<int>>& grid, int &sum ){
        if(i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] == 0){
            return;
        }
        sum += grid[i][j];
        grid[i][j] = 0;
        dfs(i,j+1, grid, sum);
        dfs(i,j-1, grid, sum);
        dfs(i+1,j, grid, sum);
        dfs(i-1,j, grid, sum);
    }
    int findMaxFish(vector<vector<int>>& grid) {
        int ans = 0;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j] != 0){
                    int sum = 0;
                    dfs(i,j, grid, sum);
                    ans = max(ans, sum); 
                }
            }
        }
        return ans;
    }
};