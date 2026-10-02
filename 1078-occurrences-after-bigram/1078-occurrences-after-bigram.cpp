class Solution {
public:
    vector<string> findOcurrences(string text, string first, string second) {
        vector<string> occurences;
        string curr = "", prev1 = "", prev2 = "";
        text += " ";
        for(int i = 0; i < text.size(); i++){
            if(text[i] != ' '){
                curr += text[i];
            }
            else{
                if(prev1 == first && prev2 == second) occurences.push_back(curr);
                prev1 = prev2;
                prev2 = curr;
                curr = ""; 
            }
        }
        return occurences;
    }
};