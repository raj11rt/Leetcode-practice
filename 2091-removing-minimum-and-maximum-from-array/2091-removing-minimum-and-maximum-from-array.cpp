class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n=nums.size();
        vector<int>a(n);
        for(int i=0;i<n;i++){
            a[i]=nums[i];
        }
        sort(a.begin(),a.end());
        int h=a[n-1];
        int l=a[0];
        int f=-1,b=-1;
        for(int i=0;i<n;i++){
            if(nums[i]==h){
                f=i;
            }else if(nums[i]==l){
                b=i;
            }
        }
       int left = min(f, b);
        int right = max(f, b);
        int ans1 = right + 1;
        int ans2 = n - left;
        int ans3 = (left + 1) + (n - right);

        return min({ans1, ans2, ans3});
    }
};