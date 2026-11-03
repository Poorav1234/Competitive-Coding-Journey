
class Solution {
public:
    int rotatedDigits(int n) {
        int digits = 0;
        for(int i = 1; i <= n; i++){
            int newNum = 0;
            int oriNum = i;
            int temp = i;
            int pos = 1;
            bool valid = true;

            while(temp > 0){
                int rem = temp % 10;

                if(rem == 3 || rem == 4 || rem == 7){
                    valid = false;
                    break;
                }
                else if(rem == 6) newNum += 9 * pos;
                else if(rem == 9) newNum += 6 * pos;
                else if(rem == 2) newNum += 5 * pos;
                else if(rem == 5) newNum += 2 * pos;
                else newNum += rem * pos;

                temp /= 10;
                pos *= 10;
            }

            if(valid && newNum != oriNum)
                digits++;
        }
        return digits;
    }
};
