#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> filterRestaurants(vector<vector<int>>& restaurants, int veganFriendly, int maxPrice, int maxDistance) {
        vector<pair<int, int>> filtered;
        
        for (const auto& r : restaurants) {
            if (r[3] <= maxPrice && r[4] <= maxDistance && (veganFriendly == 0 || r[2] == 1)) {
                filtered.push_back({r[1], r[0]});
            }
        }
        
        sort(filtered.begin(), filtered.end(), greater<pair<int, int>>());
        
        vector<int> answer;
        for (auto p : filtered) {
            answer.push_back(p.second);
        }
        
        return answer;
    }
};
