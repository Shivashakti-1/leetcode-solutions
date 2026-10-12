class Solution {
public:
    int maximumCandies(vector<int>& candies, long long k) {
        int l=1;
        int r=*max_element(candies.begin(),candies.end());
        int ans=0;

        while(l<=r)
        {
            int m=l+(r-l)/2;
            long long res=0;
            for(int c : candies)
            {
                res+=floor(double(c)/m);
            }

            if(res>=k)
            {
                ans=m;
                l=m+1;
            }
            else
            {
                r=m-1;
            }
            
        }
        return ans;
        
    }
};