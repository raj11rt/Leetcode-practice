class Solution {
public:
    string reverseStr(string s, int k) {
        int n=s.size();
        for(int i=0;i<n;i+=2*k){
            int l=i;
            int r=min(i+k-1,n-1);
            while(l<r){
                char temp=s[l];
                s[l]=s[r];
                s[r]=temp;
                l++;
                r--;
            }
        }
        return s;
    }
};