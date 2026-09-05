class Solution {
public:
    bool isCycle(int s,vector<bool>& vis,vector<bool>& r,vector<vector<int>>& prerequisites){
        vis[s]=true;
        r[s]=true;
        for(int i=0;i<prerequisites.size();i++){
            int v=prerequisites[i][0];
            int u=prerequisites[i][1];
        
            if(u==s){
                if(!vis[v]){
                    if(isCycle(v,vis,r,prerequisites)){
                        return true;
                    }
                }else if(r[v]){
                    return true;
                }
            }
        }
        r[s]=false;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<bool> vis(numCourses,false);
        vector<bool> r(numCourses,false);

        for(int i=0;i<numCourses;i++){
            if(!vis[i]){
                if(isCycle(i,vis,r,prerequisites)){
                    return false;
                }
            }
        }
        return true;
    }
};