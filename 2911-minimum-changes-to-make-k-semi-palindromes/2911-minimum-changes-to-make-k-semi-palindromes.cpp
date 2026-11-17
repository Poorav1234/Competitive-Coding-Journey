class Solution {
public:
    int dp[201][101]; 

    // Your two-pointer palindrome check adapted to count mismatches for divisor d
    int countChanges(string s) {
        int n = s.size();
        int minChanges = 1e9;

        for (int d = 1; d < n; d++) {
            if (n % d != 0) continue;

            int changes = 0;
            // Check each group of step 'd' using your two-pointer logic
            for (int start = 0; start < d; start++) {
                int left = start;
                int right = n - d + start;
                while (left < right) {
                    if (s[left] != s[right]) changes++;
                    left += d;
                    right -= d;
                }
            }
            minChanges = min(minChanges, changes);
        }
        return minChanges;
    }

    // Your solve function keeping (s, k, curr, i, j) and s.substr()
    int solve(string &s, int k, int curr, int i, int j) {
        // Base case: last partition takes the remaining substring s[i..j]
        if (curr == k) {
            if (j - i + 1 < 2) return 1e9; // Length must be at least 2
            string sub = s.substr(i, j - i + 1);
            return countChanges(sub);
        }

        if (dp[i][curr] != -1) return dp[i][curr];

        int ans = 1e9;
        // Try splitting s[i..j] at index m for the current partition
        for (int m = i + 1; m <= j - 2 * (k - curr); m++) {
            string sub = s.substr(i, m - i + 1);
            int currentCost = countChanges(sub);
            int nextCost = solve(s, k, curr + 1, m + 1, j);
            ans = min(ans, currentCost + nextCost);
        }

        return dp[i][curr] = ans;
    }

    int minimumChanges(string s, int k) {
        memset(dp, -1, sizeof(dp));
        int curr = 1;
        return solve(s, k, curr, 0, s.size() - 1);
    }
};
