
class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size();

        vector<int> freeCount(n, 0);

        // Step 1: Calculate free copies for every item
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(i != j && items[j][0] % items[i][0] == 0) {
                    freeCount[i]++;
                }
            }
        }

        // Step 2: Store price, value and original index
        vector<vector<int>> a;

        for(int i = 0; i < n; i++) {
            a.push_back({
                items[i][1],
                freeCount[i] + 1
            });
        }

        // Sort by price in descending order
        sort(a.rbegin(), a.rend());

        const int NEG = -1000000000;

        // Best value using items with price greater than current price
        vector<int> dp(budget + 1, NEG);
        dp[0] = 0;

        int ans = 0;
        int i = 0;

        while(i < n) {
            int p = a[i][0];

            // DP for selections containing at least one item
            // whose price is exactly p
            vector<int> curr(budget + 1, NEG);

            int j = i;

            while(j < n && a[j][0] == p) {
                int price = a[j][0];
                int value = a[j][1];

                for(int cost = budget; cost >= price; cost--) {

                    if(dp[cost - price] != NEG) {
                        curr[cost] = max(
                            curr[cost],
                            dp[cost - price] + value
                        );
                    }

                    if(curr[cost - price] != NEG) {
                        curr[cost] = max(
                            curr[cost],
                            curr[cost - price] + value
                        );
                    }
                }

                j++;
            }

            // Calculate answer for cheapest price p
            for(int cost = 0; cost <= budget; cost++) {
                if(curr[cost] != NEG) {
                    ans = max(
                        ans,
                        curr[cost] + (budget - cost) / p
                    );
                }
            }

            // Add current price group to normal knapsack DP
            for(int x = i; x < j; x++) {
                int price = a[x][0];
                int value = a[x][1];

                for(int cost = budget; cost >= price; cost--) {
                    if(dp[cost - price] != NEG) {
                        dp[cost] = max(
                            dp[cost],
                            dp[cost - price] + value
                        );
                    }
                }
            }

            i = j;
        }

        return ans;
    }
};
