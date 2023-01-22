class Solution {
public:
    bool ispalindrom(string &s,int l, int r){
        while(l<r){
            if(s[l++]!=s[r--]) return false;
        }
        return true;
    }
    
    void parting(string &s, int start, vector<string> &part, vector<vector<string>> &ans){
        int n= s.length();
        if(start==n){
            ans.push_back(part);
        }
        else{
            for(int i= start;i<n;i++){
                if(ispalindrom(s,start,i)){
                    part.push_back(s.substr(start,i-start+1));
                    parting(s,i+1,part,ans);
                    part.pop_back();
                }
            }
        }
    }
    
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> part;
        parting(s,0, part, ans);
        return ans;
    }
    
    
};