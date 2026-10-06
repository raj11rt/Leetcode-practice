class Solution {
public:
    int minAddToMakeValid(string s) {
        int o=0;
        int c=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                o++;
            }else{
                if(o>0)
                    o--;
                else{
                    c++;
                }
            }
        }
        return o+c;
    }
};