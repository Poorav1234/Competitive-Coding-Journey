class Solution {
public:
    string largestGoodInteger(string num) {
        string answer = "";
        for(int i = 0; i < num.size()-2; i++){
            int first = num[i] - '0';
            int second = num[i+1] - '0';
            int third = num[i+2] - '0';
            if(first == second && first == third){
                string tmp = to_string(first) + to_string(first) + to_string(first);
                if(answer < tmp) answer = tmp;
            }
        }
        return answer;
    }
};