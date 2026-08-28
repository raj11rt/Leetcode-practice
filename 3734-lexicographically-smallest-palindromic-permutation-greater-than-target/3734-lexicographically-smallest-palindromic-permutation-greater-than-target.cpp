class Solution {
public:
    string lexPalindromicPermutation(string s, string target) {
        int n=s.length();
        int h=n/2;
        map<char,int> mp;

        for(char ch:s)
            mp[ch]++;

        int odd=0;
        char mid=0;

        for(auto it:mp){
            if(it.second%2){
                odd++;
                mid=it.first;
            }
        }

        if(odd!=(n%2))
            return "";

        auto makePal=[&](string left){
            string ans=left;
            if(n%2)
                ans+=mid;
            reverse(left.begin(),left.end());
            ans+=left;
            return ans;
        };

        map<char,int> cnt=mp;
        string left="";
        bool ok=true;

        for(int i=0;i<h;i++){
            char ch=target[i];

            if(cnt.find(ch)==cnt.end() || cnt[ch]<2){
                ok=false;
                break;
            }

            cnt[ch]-=2;
            left+=ch;
        }

        if(ok){
            string ans=makePal(left);

            if(ans>target)
                return ans;
        }

        for(int pos=h-1;pos>=0;pos--){
            map<char,int> cnt=mp;
            string left="";
            bool ok=true;

            for(int i=0;i<pos;i++){
                char ch=target[i];

                if(cnt.find(ch)==cnt.end() || cnt[ch]<2){
                    ok=false;
                    break;
                }

                cnt[ch]-=2;
                left+=ch;
            }

            if(!ok)
                continue;

            auto it=cnt.upper_bound(target[pos]);

            while(it!=cnt.end() && it->second<2)
                it++;

            if(it==cnt.end())
                continue;

            left+=it->first;
            cnt[it->first]-=2;

            for(auto x:cnt)
                left+=string(x.second/2,x.first);

            string ans=makePal(left);

            if(ans>target)
                return ans;
        }

        return "";
    }
};