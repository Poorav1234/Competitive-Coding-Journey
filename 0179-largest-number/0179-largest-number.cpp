class Solution {
public:
    string largestNumber(vector<int>& nums) {
        string answer = "";
        for(int i = 0; i < nums.size(); i++){
            for(int j = 0; j < nums.size()-1; j++){
                string n1 = to_string(nums[j]);
                string n2 = to_string(nums[j+1]);
                if(n1+n2 < n2+n1){
                    int temp = nums[j];
                    nums[j] = nums[j+1];
                    nums[j+1] = temp;
                }
            }
        }
        bool res = true;
        for(int num : nums) {
            if(num != 0) res = false;
            answer += to_string(num);
        }
        return res == true ? "0" : answer;
    }
};