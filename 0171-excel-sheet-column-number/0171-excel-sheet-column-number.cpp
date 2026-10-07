class Solution {
public:
    int titleToNumber(string columnTitle) {
        int n = columnTitle.size();
        int answer = 0;
        for(char ch : columnTitle) {
            answer = answer * 26 + (ch - 'A' + 1);
        }
        return answer;
    }
};