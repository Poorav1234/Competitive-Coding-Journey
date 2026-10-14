class Solution {
public:
    int secondHighest(string s) {
        int first = -1;
        int second = -1;
        for(char c : s){
            if(c >= '0' && c <= '9'){ 
                int n = c - '0';
                if(n > first){
                    second = first;
                    first = n;
                }
                else if(n > second && n < first){
                    second = n;
                }
            }
        }
        return second;
    }
};