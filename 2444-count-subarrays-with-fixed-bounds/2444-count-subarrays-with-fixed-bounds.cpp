#define ll long long

class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        ll n=nums.size();
        vector<ll> idxmax;
        vector<ll> idxmin;
        ll ans=0;
        for(int i=0;i<n;i++)
        {
            if(nums[i]==minK)
            {
                idxmin.push_back(i);
            }
            if(nums[i]==maxK)
            {
                idxmax.push_back(i);
            }
        }
        ll last=-1;
        for(ll i=0;i<n;i++)
        {
            if(nums[i]>=minK&&nums[i]<=maxK)
            {
                ll low=0;
                ll high=idxmax.size()-1;
                ll idx1=-1,idx2=-1;
                while(low<=high)
                {
                    ll mid=low+(high-low)/2;
                    if(idxmax[mid]<=i)
                    {
                        idx1=idxmax[mid];
                        low=mid+1;
                    }
                    else
                    {
                        high=mid-1;
                    }
                }

                low=0;
                high=idxmin.size()-1;
                while(low<=high)
                {
                    ll mid=low+(high-low)/2;
                    if(idxmin[mid]<=i)
                    {
                        idx2=idxmin[mid];
                        low=mid+1;
                    }
                    else
                    {
                        high=mid-1;
                    }
                }

                ll mini=min(idx1,idx2);
                if(mini>last&&mini!=-1)
                {
                    ans+=mini-last;
                }
            }
            else
            {
                last=i;
            }
        }
        return ans;
    }
};