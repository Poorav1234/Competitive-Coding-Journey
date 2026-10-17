class Solution {
public:
    int digitSum(int num) {
        int sum = 0;
        while (num != 0) {
            sum += (num % 10);
            num /= 10;
        }
        return sum;
    }

    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        vector<pair<pair<int, int>, int>> arr(n);
        for (int i = 0; i < n; i++) {
            arr[i] = {{nums[i], digitSum(nums[i])}, i};
        }

        sort(arr.begin(), arr.end(), [](const auto &a, const auto &b) {
            if (a.first.second == b.first.second) {
                return a.first.first < b.first.first;
            }
            return a.first.second < b.first.second;
        });


        vector<bool> visited(n, false);
        int totalSwaps = 0;

        for (int i = 0; i < n; i++) {
            if (visited[i] || arr[i].second == i) {
                continue;
            }
            int cycleSize = 0;
            int curr = i;
            
            while (!visited[curr]) {
                visited[curr] = true;
                curr = arr[curr].second; 
                cycleSize++;
            }

            if (cycleSize > 1) {
                totalSwaps += (cycleSize - 1);
            }
        }

        return totalSwaps;
    }
};
