class Solution {
public:
    
    const int MOD = 1e9 + 7;

    int solve(int i, int j, int move, int m, int n, vector<vector<int>>& grid, vector<vector<vector<int>>>& dp) {

        if (i >= m || j >= n) {
            return 0;
        }

        if (i == m-1 && j == n-1) {
            return 1;
        }

        if (dp[i][j][move] != -1) {
            return dp[i][j][move];
        }

        int ans = 0;

        if (grid[i][j] == 1) {

            // currently i am moving right side so now reach into mirror i have to move down side
            if (move == 0) {
                ans += solve(i+1, j, 1, m, n, grid, dp) % MOD;
            } else {
                ans += solve(i, j+1, 0, m, n, grid, dp) % MOD;
            }
        } else {

            // normal path no mirror
            ans = (solve(i+1, j, 1, m, n, grid, dp) + solve(i, j+1, 0, m, n, grid, dp)) % MOD;
        }

        return dp[i][j][move] = ans % MOD;
    }
    int uniquePaths(vector<vector<int>>& grid) {
        
        int m = grid.size();
        int n = grid[0].size();


        /*
        0 -> move right side
        1 -> move down side
        */

        // vector dp(m+1, vector(n+1, vector<int>(2, -1)));
        // return solve(0, 0, 0, m, n, grid, dp);

        vector dp(m+1, vector(n+1, vector<int>(2, 0)));

        for (int i = m-1; i >= 0; i--) {
            for (int j = n-1; j >= 0; j--) {
                for (int move = 0; move <= 1; move++) {

                    if (i == m-1 && j == n-1) {
                        dp[i][j][move] = 1;
                        continue;
                    }
                    int ans = 0;

                    if (grid[i][j] == 1) {

                        if (move == 0) {
                            ans += dp[i+1][j][1] % MOD;
                        } else {
                            ans += dp[i][j+1][0] % MOD;
                        }
                    } else {
                        ans = (dp[i+1][j][1] + dp[i][j+1][0]) % MOD;
                    }

                    dp[i][j][move] = ans % MOD;
                }
            }
        }

        return dp[0][0][0];
    }
};

