class Solution {
public:
    bool isMiddleElementUnique(vector<int>& nums) {
        int midEle = nums[nums.size() / 2];
        int count = 0;
        for(int n : nums) if(n == midEle) count++;
        return count == 1;
    }
};