class Solution {
public:
    void dfs(int i, int j, vector<vector<int>>& grid, int& area) {
        int rows = grid.size();
        int cols = grid[0].size();
        if (i < 0 || j < 0 || i >= rows || j >= cols || grid[i][j] == 0) {
            return;
        }
        grid[i][j] = 0;
        area++;
        dfs(i, j + 1, grid, area);
        dfs(i, j - 1, grid, area);
        dfs(i + 1, j, grid, area);
        dfs(i - 1, j, grid, area);
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        int maxArea = 0;

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] >= 1) {
                    int area = 0;
                    dfs(i, j, grid, area);
                    maxArea = max(maxArea, area);
                }
            }
        }
        return maxArea;
    }
};