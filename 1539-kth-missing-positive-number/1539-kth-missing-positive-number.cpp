class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        unordered_set<int> st;
        int n = arr.size();
        for(int i=0;i<n;i++){
            st.insert(arr[i]);
        }
        int i=1;
        while(k){
            if(st.find(i)!=st.end()){
                i++; 
            }
            else{
                i++; k--;
            }
        }
        return i-1;
    }
};