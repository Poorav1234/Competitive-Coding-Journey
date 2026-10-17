class Solution {
public:
    static int digitSum(int num) {
        int sum = 0;
        while (num != 0) {
            sum += (num % 10);
            num /= 10;
        }
        return sum;
    }

    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        
        auto lambda = [](auto a, auto b){
            int digitSum1 = digitSum(a);
            int digitSum2 = digitSum(b);

            if(digitSum1 != digitSum2){
                return digitSum1 < digitSum2;
            }

            return a < b;
        };

        vector<int> afterSorted(nums);

        sort(afterSorted.begin(), afterSorted.end(), lambda);

        unordered_map<int, int> valueToIndex;
        for(int i = 0; i < n; i++){
            valueToIndex[nums[i]] = i;
        }

        int swaps = 0;
        for(int i = 0; i < n; i++){
            int expectedValue = afterSorted[i];
            int currentValue = nums[i];

            if(expectedValue == currentValue) continue;

            int index = valueToIndex[expectedValue];

            nums[i] = expectedValue;
            nums[index] = currentValue;
            valueToIndex[expectedValue] = i;
            valueToIndex[currentValue] = index;

            swaps++;
        }
        return swaps;
    }
};
