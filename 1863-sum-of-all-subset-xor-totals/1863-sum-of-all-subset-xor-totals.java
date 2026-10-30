class Solution {
    public int solve(int[] nums, int i, int xr)
    {
        if(i==nums.length)
        {
            return xr;
        }
        int include = solve(nums, i+1, nums[i]^xr);

        int exclude = solve(nums, i+1, xr);

        return include+exclude;

    }
    public int subsetXORSum(int[] nums) {
        
        return solve(nums, 0, 0);
        
    }
}