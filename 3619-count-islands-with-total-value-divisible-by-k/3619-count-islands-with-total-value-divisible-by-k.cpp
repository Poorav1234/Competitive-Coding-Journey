class Solution {
public:
    vector<vector<int>> directions = {{0,1}, {0, -1}, {1,0}, {-1, 0}};
    long long dfs(int i, int j, vector<vector<int>> &grid){
        long long sum = grid[i][j];
        grid[i][j] = 0;

        for(vector<int> dir : directions){
            int i_ = i + dir[0];
            int j_ = j + dir[1];

            if(i_ >= 0 && j_ >= 0 && i_ < grid.size() && j_ < grid[0].size() && grid[i_][j_] > 0){
                sum += dfs(i_, j_, grid);
            }
        }
        return sum;
    }
    int countIslands(vector<vector<int>>& grid, int k) {
        int count = 0;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j] > 0){
                    long long sum = dfs(i, j , grid);
                    if(sum % k == 0) count++;
                }
            }
        }
        return count;
    }
};