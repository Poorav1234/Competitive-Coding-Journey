class Solution {
public:
    int countGoodRectangles(vector<vector<int>>& rectangles) {
        int count = 0;
        int maxLength = 0;
        vector<int> lengths;
        for(vector<int> arr : rectangles){
            int minL = min(arr[0], arr[1]);
            lengths.push_back(minL);
            maxLength = max(maxLength, minL);
        }
        for(int l : lengths) if(l == maxLength) count++;
        return count;
    }
};