class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int n=bills.size();
        int f=0;
        int t=0;
        if(bills[0]!=5){
            return false;
        }
        for(int i=0;i<n;i++){
            if(bills[i]==5){
                f++;
            }else if(bills[i]==10 ){
                if(f<1){
                    return false;
                }
                f--;
                t++;
            }else{
                if(t>0 && f>=1){
                    t--;
                    f--;
                }else if(f>=3){
                    f-=3;
                }else {
                    return false;
                }
            }
        }
        return true ;
    }
};