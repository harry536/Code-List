class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        unordered_map<int,int> mp;
        for(int i=1;i<=26;i++){
            mp[order[i-1]-'a'] = i;
        }
        for(auto i : mp){
            cout<<i.first<<" "<<i.second<<" ";
        }
        for(int i=0;i<words.size();i++){
            for(int j=0;j<words[i].size();j++){
                words[i][j] = mp[words[i][j]-'a'];
                
                // cout<<words[i][j]<<" ";
            }
        }
        return is_sorted(words.begin(),words.end());
    }
};