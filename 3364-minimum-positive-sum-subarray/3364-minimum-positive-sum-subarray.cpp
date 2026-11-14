class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int sum = INT_MAX;
        int subsize = r - l;
        for (int i = 0; i < nums.size(); i++) {
            int tempSum = 0;
            for (int j = i; j < nums.size(); j++) {
                int len = j - i + 1;
                if (len > r) break;
                
                tempSum += nums[j]; 
                
                if (len >= l && tempSum > 0) {
                    sum = min(sum, tempSum);
                }
            }
        }
        return sum == INT_MAX ? -1 : sum;
    }
};