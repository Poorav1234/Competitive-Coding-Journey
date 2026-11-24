class Solution {
public:
    typedef long long ll;
    int maxLength(vector<int>& nums) {
        int answer = 0;
        int left = 0;
        for (int left = 0; left < nums.size(); left++) {
            ll gcdVal = 0;
            ll lcmVal = 1;
            ll product = 1;
            for (int right = left; right < nums.size(); right++) {
                if (product > 1e14) break; 
                gcdVal = gcd(gcdVal, nums[right]);
                lcmVal = lcm(lcmVal, nums[right]);
                product = product * nums[right];
                if (product == gcdVal * lcmVal) {
                    answer = max(answer, right - left + 1);
                }
            }
        }
        return answer;
    }
};