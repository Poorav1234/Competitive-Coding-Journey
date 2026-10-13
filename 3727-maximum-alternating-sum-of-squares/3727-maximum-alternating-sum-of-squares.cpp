class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        long long sum = 0;
        int size = nums.size()/2;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] < 0) nums[i] = nums[i] * (-1);
            sum += (nums[i] * nums[i]);
        }
        sort(begin(nums),end(nums));
        for(int i = 0; i < size; i++){
            sum -= (2LL * nums[i] * nums[i]);
        }
        return sum;
    }
};