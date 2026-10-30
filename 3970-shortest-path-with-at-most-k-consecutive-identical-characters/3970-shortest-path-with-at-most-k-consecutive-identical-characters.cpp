class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
        
        unordered_map<int, vector<pair<int, int>>> adj;

        for (auto& edge: edges) {

            int u = edge[0];
            int v = edge[1];
            int w = edge[2];

            adj[u].push_back({v, w});
        }

        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;

        vector<vector<int>> dist(n, vector<int>(k+1, INT_MAX));
        pq.push({0, 0, 1}); // w, node, count
        dist[0][1] = 0;

        while (!pq.empty()) {

            auto [currW, node, count] = pq.top();
            pq.pop();

            if (currW > dist[node][count]) continue;

            if (node == n-1) {
                return currW;
            }

            for (auto& nbr : adj[node]) {

                int nextNode = nbr.first;
                int nextW =    nbr.second + currW;
                int nextCount = 1;

                if (labels[nextNode] == labels[node]) {
                   nextCount += count;
                }

                // cout << nextNode << " , " << nextW << ", " << nextCount << endl;
                if (nextCount <= k && dist[nextNode][nextCount] > nextW) {
                    // cout << "Runs" << endl;
                    pq.push({nextW, nextNode, nextCount});
                    dist[nextNode][nextCount] = nextW;
                }
            }
        }

        return -1;
    }
};

