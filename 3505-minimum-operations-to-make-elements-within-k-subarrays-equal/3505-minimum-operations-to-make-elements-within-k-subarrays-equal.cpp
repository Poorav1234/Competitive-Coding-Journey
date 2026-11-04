#include <vector>
#include <queue>
#include <unordered_map>
#include <cmath>
#include <algorithm>

using namespace std;

class Solution {
public:
    long long minOperations(vector<int>& nums, int x, int k) {
        int n = nums.size();
        vector<long long> cost(n - x + 1, 0);
        
        priority_queue<int> max_heap; // Left half
        priority_queue<int, vector<int>, greater<int>> min_heap; // Right half
        
        long long sum_left = 0, sum_right = 0;
        int left_size = 0, right_size = 0; // Tracks accurate active element counts
        unordered_map<int, int> to_delete;
        
        auto prune = [&]() {
            while (!max_heap.empty() && to_delete[max_heap.top()] > 0) {
                to_delete[max_heap.top()]--;
                max_heap.pop();
            }
            while (!min_heap.empty() && to_delete[min_heap.top()] > 0) {
                to_delete[min_heap.top()]--;
                min_heap.pop();
            }
        };
        
        auto balance = [&]() {
            if (left_size > right_size + 1) {
                int val = max_heap.top();
                max_heap.pop();
                min_heap.push(val);
                sum_left -= val;
                sum_right += val;
                left_size--;
                right_size++;
            } else if (left_size < right_size) {
                int val = min_heap.top();
                min_heap.pop();
                max_heap.push(val);
                sum_right -= val;
                sum_left += val;
                right_size--;
                left_size++;
            }
            prune();
        };
        
        auto add = [&](int val) {
            prune();
            if (max_heap.empty() || val <= max_heap.top()) {
                max_heap.push(val);
                sum_left += val;
                left_size++;
            } else {
                min_heap.push(val);
                sum_right += val;
                right_size++;
            }
            balance();
        };
        
        auto remove = [&](int val) {
            to_delete[val]++;
            if (!max_heap.empty() && val <= max_heap.top()) {
                sum_left -= val;
                left_size--;
            } else {
                sum_right -= val;
                right_size--;
            }
            prune();
            balance();
        };
        
        // Process the very first window
        for (int i = 0; i < x; i++) {
            add(nums[i]);
        }
        
        long long median = max_heap.top();
        cost[0] = (median * left_size - sum_left) + (sum_right - median * right_size);
        
        // Slide across the remaining windows
        for (int i = 1; i <= n - x; i++) {
            remove(nums[i - 1]);
            add(nums[i + x - 1]);
            
            median = max_heap.top();
            // ✅ Using accurate left_size and right_size counters fixes the arithmetic bug
            cost[i] = (median * left_size - sum_left) + (sum_right - median * right_size);
        }
        
        // Step 2: DP to pick k non-overlapping windows
        long long INF = 1e16;
        vector<vector<long long>> dp(n + 1, vector<long long>(k + 1, INF));
        
        for (int i = 0; i <= n; i++) {
            dp[i][0] = 0;
        }
        
        for (int j = 1; j <= k; j++) {
            for (int i = x; i <= n; i++) {
                dp[i][j] = dp[i - 1][j];
                if (dp[i - x][j - 1] != INF) {
                    dp[i][j] = min(dp[i][j], dp[i - x][j - 1] + cost[i - x]);
                }
            }
        }
        
        return dp[n][k];
    }
};
