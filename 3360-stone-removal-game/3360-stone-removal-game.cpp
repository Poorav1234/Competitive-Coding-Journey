class Solution {
public:
    bool canAliceWin(int n) {
        int stones = 10;
        bool chance = false;
        while(n > 0){
            if(n >= stones){
                n -= stones;
            }
            else{
                return chance;
            }
            stones--;
            chance = !chance;
        }
        return chance;
    }
};