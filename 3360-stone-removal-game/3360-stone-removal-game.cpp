class Solution {
public:
    bool canAliceWin(int n) {
        int stones = 10;
        int turn = 0;
        while(n > 0){
            if(n >= stones){
                n -= stones;
            }
            else{
                if(turn % 2 == 0) return false;
                else return true;
            }
            stones--;
            turn++;
        }
        return turn % 2 == 1;
    }
};