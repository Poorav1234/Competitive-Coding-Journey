class Solution {
public:
    string removeOuterParentheses(string s) {
        string answer = "";
        int count = 0;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '(') count++;
            else if(s[i] == ')') count--;
            if((count == 1 && s[i] == '(') || (count == 0 && s[i] == ')')){
                continue;
            } else {
                answer += s[i];
            }
        }
        return answer;
    }
};