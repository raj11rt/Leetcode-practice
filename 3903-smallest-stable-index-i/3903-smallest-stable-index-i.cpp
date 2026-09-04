class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n=nums.size();
        int i=0;
        int ans;
        int mx=INT_MIN;
        int mn=INT_MAX;
        bool t=false;
        while(i<n){
            for(int j=0;j<i+1;j++){
                mx=max(nums[j],mx);
            }
            for(int j=i;j<n;j++){
                mn=min(nums[j],mn);
            }
            int dif=mx-mn;
            if(dif<=k){
                return i;
            }
            mx=INT_MIN;
            mn=INT_MAX;
            i++;
        }
        return -1;
    }
};