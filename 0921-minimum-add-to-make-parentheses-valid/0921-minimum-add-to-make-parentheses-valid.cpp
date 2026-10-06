class Solution {
public:
    int minAddToMakeValid(string s) {
        vector<char> parantheses;
        int answer = 0;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '('){
                parantheses.push_back('(');
            }
            else if(s[i] == ')' && parantheses.empty()){
                answer++;
            }
            else if(s[i] == ')' && parantheses.size() > 0){
                parantheses.pop_back();
            }
        }
        return answer + parantheses.size();
    }
};