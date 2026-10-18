class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
        unordered_map<int, int> f;
        for(int n : nums) if(n % 2 == 0) f[n]++;
        int even = -1, freq = 0;
        for(auto it : f){
            if(it.second == freq){
                even = min(even, it.first);
            }
            if(it.second > freq){
                freq = it.second;
                even = it.first;
            }
        }
        return even;
    }
};