class Solution {
public:
    string digitSum(string s, int k) {
        string answer = "";
        while(s.size() > k){
            string temp = "";
            for(int i = 0; i < s.size(); i+=k){
                int sum = 0;
                for(int j = i; j < s.size(); j++){
                    if(j >= i + k) break;
                    sum += (s[j] - '0');
                }
                temp += to_string(sum);
            }
            s = temp;
        }
        return s;
    }
};