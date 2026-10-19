class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        int count = 0, freq = 0;
        for(int n : nums){
            if(n == target) freq++;
            if(n < target) count++;
        }
        vector<int> indices(freq, 0);
        for(int i = 0; i < freq; i++){
            indices[i] = count;
            count++;
        }
        return indices;
    }
};