class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int,int>> g[n];
        for(int i=0;i<flights.size();i++){
            int u=flights[i][0];
            int v=flights[i][1];
            int wt=flights[i][2];

            g[u].push_back({v,wt});
        }
        queue<pair<int,pair<int,int>>>q;
        vector<int>d(n,INT_MAX);
        d[src]=0;
        q.push({src,{0,-1}});

        while(q.size()>0){
            auto val=q.front();
            int u=val.first;
            int c=val.second.first;
            int s=val.second.second;
            q.pop();

            for(auto edge:g[u]){
                int v=edge.first;
                int wt=edge.second;
                if(d[v]>c+wt && s+1<=k){
                    d[v]=c+wt;
                    q.push({v,{d[v],s+1}});
                }
            }
        }
        if(d[dst]==INT_MAX){
            return -1;
        }
        return d[dst];
    }
};