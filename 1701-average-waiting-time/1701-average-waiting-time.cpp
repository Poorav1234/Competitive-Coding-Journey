class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        int size = customers.size();
        double sum = 0;
        double curr = customers[0][0];
        for(int i = 0; i < size; i++){
            if(curr <= customers[i][0]){
                curr = customers[i][0];
                curr = curr + customers[i][1];
            }
            else{
                curr = curr + customers[i][1];
            }
            sum += (curr - customers[i][0]);
        }
        return double(sum / size);
    }
};