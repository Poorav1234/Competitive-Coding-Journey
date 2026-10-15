class Solution {
public:
    vector<string> printVertically(string s) {
        vector<string> words;
        string temp = "";
        int maxLen = 0;
        for(int i = 0; i < s.size(); i++){
            if(s[i] != ' '){
                temp += s[i];
            }
            else{
                maxLen = max<int>(maxLen, temp.size());
                words.push_back(temp);
                temp = "";
            }
            if(i == s.size()-1) {
                maxLen = max<int>(maxLen, temp.size());
                words.push_back(temp);
            }
        }
        vector<string> answer(maxLen, string(words.size(),' '));
        for(int i = 0; i < maxLen; i++){
            for(int j = 0; j < words.size(); j++){
                if (i < words[j].size()) {
                    answer[i][j] = words[j][i];
                }
            }
            while(!answer[i].empty() && answer[i].back() == ' ') {
                answer[i].pop_back();
            }
        }
        return answer;
    }
};