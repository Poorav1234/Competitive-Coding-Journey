class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        int nines = sum / 9;
        int remain = sum % 9;

        if(sum > num * 9) return "";

        string answer(nines, '9');
        if(remain > 0) answer += (remain + '0');
        answer.append(num - answer.length(), '0');

        return answer;
    }
};