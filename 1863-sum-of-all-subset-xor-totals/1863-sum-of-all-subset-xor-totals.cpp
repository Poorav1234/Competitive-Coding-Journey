class Solution {
public:
    void solve(int i, vector<int> &nums, int &xorAns, int &answer){
        int n = nums.size();
        if(i == n){
            answer += xorAns;
            return;
        }
        solve(i + 1, nums, xorAns, answer);

        xorAns ^= nums[i];
        
        solve(i + 1, nums, xorAns, answer);
    }
    int subsetXORSum(vector<int>& nums) {
        int xorAnswer = 0, xorVal = 0;
        solve(0, nums, xorVal, xorAnswer);
        return xorAnswer;
    }
};