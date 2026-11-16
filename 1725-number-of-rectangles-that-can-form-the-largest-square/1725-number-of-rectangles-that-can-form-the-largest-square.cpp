class Solution {
public:
    int countGoodRectangles(vector<vector<int>>& rectangles) {
        int count = 0;
        int maxLength = 0;
        for(vector<int> arr : rectangles){
            int minL = min(arr[0], arr[1]);
            if(minL > maxLength){
                maxLength = minL;
                count = 1;
            }
            else if(minL == maxLength) count++;
        }
        return count;
    }
};