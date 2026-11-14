class Solution {
public:
    int solve(int n, int num, int k, int &sum){
        if(num > n + k) return sum;
        if(abs(n - num) <= k && (n & num) == 0) {
            sum += num;
        }
        solve(n, num+1, k, sum);
        return sum;
    }
    int sumOfGoodIntegers(int n, int k) {
        int num = max(0, n - k);                
        int s = 0;
        int sum = solve(n, num, k, s);
        return sum;
    }
};