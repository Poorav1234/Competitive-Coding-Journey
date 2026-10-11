class Solution {
public:
    bool judgeSquareSum(int c) {
        long long left = 0, right = sqrt(c);
        while(left <= right){
            long long rr = right * right;
            long long ll = left * left;
            if(rr + ll == c) return true;
            else if(rr + ll > c) right--;
            else if(rr + ll < c) left++;
        }
        return false;
    }
};