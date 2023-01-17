class Solution {
public:
    
    int minFlipsMonoIncr(string s) {
        int n= s.size();
       int cnt=0,cnt2=0,ans=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='1') cnt++;
            
        }
        ans = s.size()-cnt;
        for(int i=0;i<s.size();i++){
            if(s[i]=='1') cnt2++;
            ans = min(ans,cnt2+n-cnt+cnt2 -i-1 );
        }
        return ans;
        }
};