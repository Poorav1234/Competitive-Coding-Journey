class Solution {
public:
    int maximizeExpressionOfThree(vector<int>& nums) {
        int a = INT_MIN;
        int b = INT_MIN;
        int c = INT_MAX;
        for(int n : nums){
            if(n < c) c = n;
            if(a <= n){
                b = a;
                a = n;
            }
            else if(b <= n && a > n){
                b = n;
            }
        }
        return (a + b - c);
    }
};