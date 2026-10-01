class Solution {
public:
    int maxDigitRange(vector<int>& nums) {
        vector<pair<int,int>> frequency;
        int sumOfIntegers = 0;
        int maxRangeDifference = 0;
        for(int num : nums){
            int largestDigit = INT_MIN;
            int smallestDigit = INT_MAX;
            int temp = num;
            while(num != 0){
                int rem = num % 10;
                largestDigit = max(largestDigit, rem);
                smallestDigit = min(smallestDigit, rem);
                num /= 10;
            }
            frequency.push_back({temp,largestDigit - smallestDigit});
            maxRangeDifference = max(maxRangeDifference, largestDigit - smallestDigit);
        }
        for(auto it : frequency){
            if(it.second == maxRangeDifference) sumOfIntegers += it.first;
        }
        return sumOfIntegers;
    }
};