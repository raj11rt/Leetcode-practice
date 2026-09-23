class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        
        priority_queue<pair<int,int>,
                       vector<pair<int,int>>,
                       greater<pair<int,int>>> pq;
        
        vector<int> vis(n, 0);
        
        pq.push({0, 0}); // {cost, point}
        
        int ans = 0;
        
        while (!pq.empty()) {
            auto [cost, u] = pq.top();
            pq.pop();
            
            if (vis[u])
                continue;
            
            vis[u] = 1;
            ans += cost;
            
            for (int v = 0; v < n; v++) {
                if (!vis[v]) {
                    int d = abs(points[u][0] - points[v][0]) +
                            abs(points[u][1] - points[v][1]);
                    
                    pq.push({d, v});
                }
            }
        }
        
        return ans;
    }
};