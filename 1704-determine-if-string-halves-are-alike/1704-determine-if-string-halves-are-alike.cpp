class Solution {
public:
    bool isVowel(char c){
        if(c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U' || c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') return true;
        return false;
    }
    bool halvesAreAlike(string s) {
        int half = s.size() / 2;
        int first = 0, second = 0;
        for(int i = 0; i < s.size(); i++){
            if(i < half){
                if(isVowel(s[i])) first++;
            }
            else{
                if(isVowel(s[i])) second++;
            }
        }
        return first == second;
    }
};