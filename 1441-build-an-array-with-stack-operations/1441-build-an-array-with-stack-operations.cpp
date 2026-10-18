class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> answer;
        vector<int> arr;
        for(int i = 1; i <= n; i++) arr.push_back(i);
        int index = 0;
        for(int i = 0; i < n; i++){
            if(index >= target.size()) break;
            if(arr[i] == target[index]){
                answer.push_back("Push");
                index++;
            }
            else{
                answer.push_back("Push");
                answer.push_back("Pop");
            }
        }
        return answer;
    }
};