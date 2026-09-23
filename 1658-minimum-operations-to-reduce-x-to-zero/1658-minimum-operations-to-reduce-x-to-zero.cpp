class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n=nums.size();
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
        }
        int t=sum-x;
        if(t==0){
            return n;
        }
        int l = 0, s = 0, longest = -1;
        for (int r = 0; r < n; r++) {
            s += nums[r];
            while (l <= r && s > t) {
                s -= nums[l];
                l++;
            }
            if (s == t)
                longest = max(longest, r - l + 1);
        }
        return longest == -1 ? -1 : n - longest;

    }
};