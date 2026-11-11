class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        long long common = min(need1, need2);
        long long pairCost = min((long long)costBoth, (long long)cost1 + cost2);
        
        long long rem1 = need1 - common;
        long long rem2 = need2 - common;
        
        long long total = common * pairCost 
                        + rem1 * min(cost1, costBoth) 
                        + rem2 * min(cost2, costBoth);
                        
        return total;
    }
};
