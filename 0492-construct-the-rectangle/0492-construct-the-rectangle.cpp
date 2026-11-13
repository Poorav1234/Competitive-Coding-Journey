class Solution {
public:
    vector<int> constructRectangle(int area) {
        int length = 0, width = 0;
        int l = area, w = 1;

        while(l >= w){
            long long product = (long long)l * w; 
            
            if (product == area) {
                length = l;
                width = w;
                l--;
                w++;
            } 
            else if (product > area) {
                l--; 
            } 
            else {
                w++; 
            }
        }
        return {length, width};
    }
};