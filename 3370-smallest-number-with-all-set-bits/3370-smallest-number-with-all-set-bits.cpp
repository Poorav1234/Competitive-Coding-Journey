class Solution {
public:
    int smallestNumber(int n) {
        int count = 0;
        while(n > 0) {
            count++;
            n /= 2;
        }
        string s(count, '1');
        int answer = 0;
        for(int i = 0; i < s.size(); i++) answer += pow(2, i); 
        return answer;
    }
};