class Solution {
    public int minMoves(int[] nums) {
        int maxi = 0;

        for (int i = 0; i < nums.length; i++) {
            maxi = Math.max(maxi, nums[i]);
        }

        int ans = 0;

        for (int i = 0; i < nums.length; i++) {
            ans += maxi - nums[i];
        }

        return ans;        
    }
}