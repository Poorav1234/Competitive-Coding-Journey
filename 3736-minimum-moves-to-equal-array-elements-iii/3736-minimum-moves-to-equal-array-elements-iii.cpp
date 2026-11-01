class Solution {
public:
    int minMoves(vector<int>& nums) {
        int maxValue=0, sum=0, n=nums.size();
        for(int x: nums){
            sum += x;
            maxValue = max(maxValue, x);
        }
        return n *maxValue - sum;
    }
};