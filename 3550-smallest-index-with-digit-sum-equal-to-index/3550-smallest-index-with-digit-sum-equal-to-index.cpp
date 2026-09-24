class Solution {
public:
    int smallestIndex(vector<int>& nums) {
        int n=nums.size();
        int ans=INT_MAX;
        bool t=false;
        for(int i=0;i<n;i++){
            int s=0;
            while(nums[i]>0){
                int r=nums[i]%10;
                s+=r;
                nums[i]/=10;
            }
            if(s==i){
                t=true;
                ans=min(ans,s);
                break;
            }
        }
        if(t){
            return ans;
        }
        return -1;
    }
};