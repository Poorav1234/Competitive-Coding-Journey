class Solution {
public:
    vector<string> findOcurrences(string text, string first, string second) {
        vector<string> occurences;
        string curr = "";
        vector<string> words;
        for(int i = 0; i < text.size(); i++){
            if(text[i] != ' '){
                curr += text[i];
                if(i == text.size()-1) {
                    words.push_back(curr);
                }
            }
            else{
                words.push_back(curr);
                curr = ""; 
            }
        }
        for(int i = 0; i < words.size()-2; i++){
            if(words[i] == first && words[i+1] == second) occurences.push_back(words[i+2]);
        }
        return occurences;
    }
};