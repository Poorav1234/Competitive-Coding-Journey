class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int mid = nums.size()/2;
        sort(begin(nums), end(nums));
        int midEle = nums[mid];
        int answer = 0;
        for(int n : nums) answer += (abs(n - midEle));
        return answer;
    }
};