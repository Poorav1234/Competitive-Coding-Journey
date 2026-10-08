class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        int count = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != -1) {
                int c = 0, idx = nums[i];
                while (nums[idx] != -1) {
                    int temp = idx;
                    idx = nums[idx];
                    c++; 
                    nums[temp] = -1;
                }
                count = max(count, c);
            }
        }
        return count;
    }
};