class Solution {
public:
    vector<string> answer;
    void solve(string& digits, unordered_map<int, string>& numberToString, int index, string& temp) {
        if (temp.size() == digits.size()) {
            answer.push_back(temp);
            return;
        }
        int c = digits[index] - '0';
        for (int i = 0; i < numberToString[c].size(); i++) {
            temp.push_back(numberToString[c][i]);

            solve(digits, numberToString, index + 1, temp);

            temp.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        unordered_map<int, string> numberToString;
        numberToString[2] = "abc";
        numberToString[3] = "def";
        numberToString[4] = "ghi";
        numberToString[5] = "jkl";
        numberToString[6] = "mno";
        numberToString[7] = "pqrs";
        numberToString[8] = "tuv";
        numberToString[9] = "wxyz";
        string tmp = "";
        solve(digits, numberToString, 0, tmp);
        return answer;
    }
};