class Solution {
public:
    int minMoves(vector<int>& nums) {
        int minEle = *min_element(begin(nums), end(nums));
        int answer = 0;
        for(int n : nums){
            answer += (n - minEle);
        }
        return answer;
    }
};