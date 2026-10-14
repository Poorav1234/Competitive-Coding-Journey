class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        string answer(num, '0');

        if (sum > num * 9)
            return "";

        for (int i = 0; i < num && sum > 0; i++) {
            int digit = min(9, sum);
            answer[i] = char('0' + digit);
            sum -= digit;
        }
        
        return answer;
    }
};