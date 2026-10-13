class Solution {
public:
    int hammingWeight(int n) {
        int count = 0;
        for (int b = 0; b < 32; b++) {
            if (n & (1 << b)) {
                count++;
            }
        }
        return count;
    }
};