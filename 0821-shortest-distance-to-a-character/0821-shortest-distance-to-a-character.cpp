class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        vector<int> answer(s.size(), 0);
        vector<int> temp;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == c) {
                temp.push_back(i);
            }
        }
        int idx = 0;
        for (int i = 0; i < s.size(); i++) {
            if (idx < temp.size() && temp[idx] == i) {
                idx++;
            } else {
                if (idx >= temp.size())
                    answer[i] = abs(temp[idx - 1] - i);
                else
                    answer[i] = abs(temp[idx] - i);
            }
        }
        idx = temp.size() - 1;
        for (int i = s.size() - 1; i >= 0; i--) {
            if (idx >= 0 && temp[idx] == i) {
                idx--;
            } else {
                if (idx < 0)
                    answer[i] = min(answer[i], abs(temp[idx + 1] - i));
                else
                    answer[i] = min(answer[i], abs(temp[idx] - i));
            }
        }
        return answer;
    }
};