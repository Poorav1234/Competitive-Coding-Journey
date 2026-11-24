class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        
        vector<int> rowsOneCount(rows, 0);
        vector<int> colsOneCount(cols, 0);
        vector<int> rowsZeroCount(rows, 0);
        vector<int> colsZeroCount(cols, 0);
        
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == 1) {
                    rowsOneCount[i]++;
                    colsOneCount[j]++;
                } else {
                    rowsZeroCount[i]++;
                    colsZeroCount[j]++;
                }
            }
        }
        
        vector<vector<int>> answer(rows, vector<int>(cols, 0));
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                answer[i][j] = rowsOneCount[i] + colsOneCount[j] - rowsZeroCount[i] - colsZeroCount[j];
            }
        }
        
        return answer;
    }
};
