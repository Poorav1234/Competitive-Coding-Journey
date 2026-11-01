class Solution {
public:
    int minMoves(vector<int>& nums) {
        int maxElement = *max_element(begin(nums),end(nums));
        int moves = (maxElement * nums.size()) - accumulate(begin(nums),end(nums), 0);
        return moves;
    }
};