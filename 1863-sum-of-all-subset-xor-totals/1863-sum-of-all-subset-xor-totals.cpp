class Solution {
public:
    void solve(vector<int> &nums, int i, int xr,int &sum)
    {
        if(i==nums.size())
        {
            sum+=xr;
            return;
        }
        
        solve(nums, i+1, nums[i]^xr, sum);

        solve(nums, i+1, xr, sum);
    }
    int subsetXORSum(vector<int>& nums) {
        int sum=0;
        
        solve(nums,0,0,sum);

        return sum;        
    }
};