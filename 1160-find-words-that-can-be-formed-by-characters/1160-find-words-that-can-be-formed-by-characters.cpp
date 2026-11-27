class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        int answer = 0;
        vector<int> freq(26, 0);
        for (char c : chars) freq[c - 'a']++;
        
        for (const string& word : words) {
            vector<int> tempFreq = freq; 
            bool canForm = true;
            
            for (char c : word) {
                if (tempFreq[c - 'a'] == 0) {
                    canForm = false;
                    break;
                }
                tempFreq[c - 'a']--; 
            }
            
            if (canForm) answer += word.size();
        }
        return answer;
    }
};
