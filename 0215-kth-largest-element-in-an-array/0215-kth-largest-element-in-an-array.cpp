class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        map<int,int> m;
        int n=nums.size();
        for(int i=0;i<n;i++){
            m[nums[i]]++;
        }
        auto it=m.rbegin();
        while(k>0){
            k-=it->second;
            if(k<=0){
                return it->first;
            }
            it++;
        }
        return -1;
    }
};