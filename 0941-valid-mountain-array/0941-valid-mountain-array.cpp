class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        int chadhav = 0, dhodav = 0;
        if(arr.size() < 3) return false;
        for(int i = 1; i < arr.size(); i++){
            if(arr[i-1] < arr[i] && dhodav > 0) return false;
            else if(arr[i-1] < arr[i] && dhodav <= 0) chadhav++;
            else if(arr[i-1] > arr[i] && chadhav <= 0) return false;
            else if(arr[i-1] > arr[i]) dhodav++;
            else return false;
        }
        if((chadhav != 0 && dhodav == 0) || (chadhav == 0 && dhodav != 0)) return false;
        return true;
    }
};