class Solution {
public:
    int minMoves(vector<int>& nums) {
        int moves = 0;
        int maxElement = *max_element(begin(nums),end(nums));
        for(int n : nums) moves += maxElement - n;
        return moves;
    }
};