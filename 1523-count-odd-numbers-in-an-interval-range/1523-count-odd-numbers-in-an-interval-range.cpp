class Solution {
public:
    int countOdds(int low, int high) {
        if(low%2==0 and high%2==0)
        return abs(low-high)/2;
        return abs(low-high)/2+1;
    }
};