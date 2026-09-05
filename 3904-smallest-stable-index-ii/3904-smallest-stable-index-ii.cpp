class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>ms(n);
        ms[n-1]=nums[n-1];
        for(int i=n-2;i>=0;i--){
            ms[i]=min(nums[i],ms[i+1]);
        }
        int mx=INT_MIN;
        for(int i=0;i<n;i++){
            mx=max(mx,nums[i]);
            if(mx-ms[i]<=k){
                return i;
            }
        }
        return -1;
    }
};