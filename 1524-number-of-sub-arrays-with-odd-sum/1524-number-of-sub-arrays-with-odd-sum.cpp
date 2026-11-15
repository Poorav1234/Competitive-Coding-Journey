class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int MOD = 1e9 + 7;
        int subArrays = 0;
        long long sum = 0;
        int evenCount = 1, oddCount = 0;
        for(int n : arr){
            sum += n;
            if(sum % 2 == 0){
                subArrays = (subArrays + oddCount) % MOD;
                evenCount++;
            }
            else{
                subArrays = (subArrays + evenCount) % MOD;
                oddCount++;
            }
        }
        return subArrays;
    }
};