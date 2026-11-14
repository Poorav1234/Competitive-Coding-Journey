class Solution {
public:
    int dp[501][501];
    bool solve(int turn, int i, int j, int alice, int bob, vector<int>& piles) {
        if (i > j) {
            return alice > bob;
        }
        if (dp[i][j] != -1) return dp[i][j]; 
        if (turn % 2 == 0) {
            return dp[i][j] = solve(turn + 1, i + 1, j, alice + piles[i], bob, piles) || solve(turn + 1, i, j - 1, alice + piles[j], bob, piles);
        } else {
            return dp[i][j] = solve(turn + 1, i + 1, j, alice, bob + piles[i], piles) || solve(turn + 1, i, j - 1, alice, bob + piles[j], piles);
        }
        return alice > bob;
    };
    bool stoneGame(vector<int>& piles) {
        memset(dp, -1, sizeof(dp));
        return solve(0, 0, piles.size() - 1, 0, 0, piles);
    }
};