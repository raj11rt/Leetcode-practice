class Solution {
public:
    bool check(int n,int t){
        int p=1;
        while(n>0){
            int r=n%10;
            p=p*r;
            n=n/10;
        }
        return p%t==0;
    }
    int smallestNumber(int n, int t) {
        while(!check(n,t)){
            n++;
        }
        return n;
        
    }
};