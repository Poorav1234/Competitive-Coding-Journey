class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int sum = 0;
        set<int> s;
        for(int i = 0; i < nums.size(); i++){
            s.insert(nums[i]);
            sum += (s.size() * s.size());
            for(int j = i+1; j < nums.size(); j++){
                s.insert(nums[j]);
                sum += (s.size() * s.size());
            }
            s.clear();
        }
        return sum;
    }
};