class Solution {
public:
    vector<string> createGrid(int m, int n) {
        vector<string> answer(m, string(n, '#'));
        for(int i = 0; i < n; i++){
            answer[0][i] = '.';
        }
        for(int i = 0; i < m; i++){
            answer[i][n-1] = '.';
        }
        return answer;
    }
};