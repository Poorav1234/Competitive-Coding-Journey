class Solution {
public:
    int scoreOfParentheses(string s) {
        
        int score = 0;
        vector<int> st;

        for(int i = 0; i < s.size(); i++) {

            if(s[i] == '(') {
                st.push_back(score);
                score = 0;
            }
            else {
                if(s[i-1] == '('){
                    score = st.back() + 1;
                } else {
                    score = st.back() + (2 * score);
                }
                st.pop_back();
            }
        }

        return score;
    }
};