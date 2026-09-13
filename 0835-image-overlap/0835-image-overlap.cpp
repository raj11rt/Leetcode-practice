class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n=img1.size();
        vector<pair<int,int>>o1,o2;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(img1[i][j]==1){
                    o1.push_back({i,j});
                }
                if(img2[i][j]==1){
                    o2.push_back({i,j});
                }
            }
        }
        map<pair<int,int>,int>m;
        int ans=0;
        for(auto[i,j]:o1){
            for(auto[x,y]:o2){
                int dr=x-i;
                int dc=y-j;

                m[{dr,dc}]++;

                ans=max(ans,m[{dr,dc}]);
            }
        }
        return ans;
    }
};