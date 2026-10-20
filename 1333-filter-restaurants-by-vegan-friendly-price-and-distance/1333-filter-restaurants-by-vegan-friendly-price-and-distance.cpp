class Solution {
public:
    vector<int> filterRestaurants(vector<vector<int>>& restaurants, int veganFriendly, int maxPrice, int maxDistance) {
        vector<pair<int,int>> f;
        for(vector<int> temp : restaurants){
            if(veganFriendly == 0 && temp[2] == 0 && temp[3] <= maxPrice && temp[4] <= maxDistance){
                f.push_back({temp[0], temp[1]});
            }
            if(temp[2] == 1 && temp[3] <= maxPrice && temp[4] <= maxDistance){
                f.push_back({temp[0], temp[1]});
            }
        }

        vector<int> answer;
        sort(f.begin(), f.end(), [](auto &a, auto &b){
            if (a.second == b.second) {
                return a.first > b.first; 
            }
            return a.second > b.second;
        });
        for(auto it : f){
            answer.push_back(it.first);
        }
        return answer;
    }
};