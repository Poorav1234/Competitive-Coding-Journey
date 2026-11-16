class Solution {
public:
    string binary(int n){
        string bin = "";
        while(n > 0){
            if(n % 2 == 1) bin += "1";
            else bin += "0";
            n /= 2;
        }
        return bin;
    }
    int minimumFlips(int n) {
        string bin = binary(n);
        int flips = 0;
        int left = 0, right = bin.size()-1;
        while(left < bin.size()){
            if(bin[left] != bin[right]) flips++;
            left++;
            right--;
        }
        return flips;
    }
};