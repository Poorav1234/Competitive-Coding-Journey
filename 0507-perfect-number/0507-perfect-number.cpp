class Solution {
public:
    bool checkPerfectNumber(int num) {
        if(num == 1) return false;
        long long squareRoot = sqrt(num);
        int answer = 1;
        for(int i = 2; i <= squareRoot; i++){
            if(num % i == 0){
                answer += i;
                answer += (num / i);
            }
        }
        return answer == num;
    }
};