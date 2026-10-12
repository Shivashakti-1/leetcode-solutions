class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l=1;
        int r=*max_element(piles.begin(), piles.end());
        int res=r;

        while(l<=r)
        {
            int k=l+(r-l)/2;
            long long hrs=0;
            for(int p:piles)
            {
                hrs+=ceil(double(p)/k);
            }
            if(hrs<=h)
            {
                res=min(res,k);
                r=k-1;
            }
            else{
                l=k+1;
            }
        }
        return res;

    }
};