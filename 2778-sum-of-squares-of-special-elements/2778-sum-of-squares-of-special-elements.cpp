class Solution {
public:
    int sumOfSquares(vector<int>& nums) {
        int sumOfSquares = 0, size = nums.size();
        for(int i = 0; i < size; i++){
            int currIvalue = i+1;
            if(size % currIvalue == 0){
                sumOfSquares += (nums[i] * nums[i]);
            }
        }
        return sumOfSquares;
    }
};