class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int rows = mat.size();
        int cols = mat[0].size();

        bool odd = true;
        vector<int> answer(rows * cols, 0);
        int index = 0;

        for(int i = 0; i < rows; i++){
            int r = i;
            int c = 0;
            if(odd){
                while(r >= 0 && c < cols){
                    answer[index++] = mat[r][c];  
                    r--;
                    c++;
                }
            }
            else{
                vector<int> o;
                while(r >= 0 && c < cols){
                    o.push_back(mat[r][c]);
                    r--;
                    c++;
                }
                reverse(begin(o), end(o));
                for(int k = 0; k < o.size(); k++){
                    answer[index++] = o[k];
                }
            }
            odd = !odd;
        }
        int temp = 1;
        for(int i = 1; i < cols; i++){
            int r = rows - 1;
            int c = i;
            if(odd){
                while(r >= 0 && c < cols ){
                    answer[index++] = mat[r][c];  
                    r--;
                    c++;
                }
            }
            else{
                vector<int> o;
                while(r >= 0 && c < cols){
                    o.push_back(mat[r][c]);
                    r--;
                    c++;
                }
                reverse(begin(o), end(o));
                for(int k = 0; k < o.size(); k++){
                    answer[index++] = o[k];
                }
            }
            temp++;
            odd = !odd;
        }
        
        return answer;
    }
};