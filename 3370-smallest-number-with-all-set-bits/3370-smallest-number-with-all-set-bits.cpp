class Solution {
public:
    int smallestNumber(int n) {
        // Space Complexity : O(1) 
        // Time Complexity : Log n 
        int ans = 1;

        while (ans < n) {
            ans = (ans << 1) | 1;
        }

        return ans;
    }
};