class Solution {
    unordered_set<string> validStrings;
public:
    
    void solve(string &s, int i, string &curr, int count, int &maxLen){
        int n = s.size();
        if(count < 0) return;
        if(i == n){
            if(count == 0){
                if(curr.length() > maxLen){
                    maxLen = curr.length();
                    validStrings.clear();
                }

                if(curr.length() == maxLen){
                    validStrings.insert(curr);
                }
            }
            return;
        }

        if(s[i] != '(' && s[i] != ')'){
            curr.push_back(s[i]);
            solve(s, i+1, curr, count, maxLen);
            curr.pop_back();
            return;
        }

        curr.push_back(s[i]);
        solve(s, i+1, curr, count + (s[i] == '(' ? 1 : -1), maxLen);
        curr.pop_back();
        solve(s, i+1, curr, count, maxLen);
    }
    vector<string> removeInvalidParentheses(string s) {
        int maxLen = 0, open = 0, i = 0;
        string curr = "";
        validStrings.clear();
        solve(s, i, curr, open, maxLen);
        return vector<string>(validStrings.begin(), validStrings.end());
    }
};