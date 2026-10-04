class Solution {
public:
    vector<vector<int>> dp;
    bool solve(int i, int open, string &s){
        bool res;
        if(open < 0) return false;
        if(i == s.size()){
            return open == 0;
        }

        if(dp[i][open] != -1)
            return dp[i][open];

        if(s[i] == '('){
            res = solve(i+1, open+1, s);
        }
        else if(s[i] == ')'){
            res = solve(i+1, open-1, s);
        }
        else if(s[i] == '*'){
            bool res1 = solve(i+1, open+1, s);
            bool res2 = solve(i+1, open-1, s);
            bool res3 = solve(i+1, open+0, s);
            res = res1 || res2 || res3;
        }
        return dp[i][open] = res;
    }
    bool checkValidString(string s) {
        int n = s.size();
        dp.assign(n, vector<int>(n + 1, -1));
        return solve(0, 0, s);

    }
};