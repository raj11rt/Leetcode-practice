class Solution {
public:
    bool isCycle(int st,vector<bool>& vis, vector<bool>& r, vector<vector<int>>& prerequisites){
        vis[st]=true;
        r[st]=true;

        for(int i=0;i<prerequisites.size();i++){
            int v=prerequisites[i][0];
            int u=prerequisites[i][1];

            if(u==st){
                if(!vis[v]){
                    if(isCycle(v,vis,r,prerequisites)){
                        return true;
                    }
                }else if(r[v]){
                    return true;
                }
            }
        }
        r[st]=false;
        return false;
    }
    void top(int st,vector<bool>& vis, stack<int>& s, vector<vector<int>>& prerequisites){
        vis[st]=true;

        for(int i=0;i<prerequisites.size();i++){
            int v=prerequisites[i][0];
            int u=prerequisites[i][1];

            if(u==st){
                if(!vis[v]){
                    top(v,vis,s,prerequisites);
                }
            }
        }
        s.push(st);
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<bool> vis(numCourses,false);
        vector<bool> r(numCourses,false);
        vector<int> ans;

        for(int i=0;i<numCourses;i++){
            if(!vis[i]){
                if(isCycle(i,vis,r,prerequisites)){
                    return ans;
                }
            }
        }
        stack<int> s;
        vis.assign(numCourses,false);

        for(int i=0;i<numCourses;i++){
            if(!vis[i]){
                top(i,vis,s,prerequisites);
            }
        }
        while(s.size()>0){
            ans.push_back(s.top());
            s.pop();
        }
        return ans;
    }
};