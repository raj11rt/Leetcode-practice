class Solution {
public:
    void dfs(int i,vector<vector<int>>& isConnected,vector<bool>& vis){
        int n=isConnected[0].size();
        vis[i]=true;
        for(int j=0;j<n;j++){
            if(isConnected[i][j]==1 && vis[j]!=true){
                dfs(j,isConnected,vis);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected[0].size();
        vector<bool> vis(n,false);
        int ans=0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                ans++;
                dfs(i,isConnected,vis);
            }
        }
        return ans;
    }
};