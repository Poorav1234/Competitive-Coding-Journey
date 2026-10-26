// BFS Not understood
class Solution {
public:
    int countIslands(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();

        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};

        int cnt = 0;

        queue<pair<int, int>> q;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] > 0) {
                    long long sum = grid[i][j];
                    q.push({i, j});
                    grid[i][j] = 0;
                    while (!q.empty()) {
                        auto curr = q.front();
                        q.pop();
                        int r = curr.first;
                        int c = curr.second;
                        for (int i = 0; i < 4; i++) {
                            int nr = r + dr[i];
                            int nc = c + dc[i];
                            if (nr >= 0 && nr < n && nc >= 0 && nc < m &&
                                grid[nr][nc] > 0) {
                                sum += grid[nr][nc];
                                grid[nr][nc] = 0;
                                q.push({nr, nc});
                            }
                        }
                    }
                    if (sum % k == 0)
                        cnt++;
                }
            }
        }
        return cnt;
    }
};
