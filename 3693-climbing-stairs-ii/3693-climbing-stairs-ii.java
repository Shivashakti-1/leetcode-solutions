class Solution {
    public int climbStairs(int n, int[] costs) {
        long[] dp = new long[n + 1];

        dp[0] = 0;

        for (int i = 1; i <= n; i++) {

            dp[i] = Long.MAX_VALUE;

            for (int jump = 1; jump <= 3; jump++) {

                if (i >= jump) {

                    long currentCost =
                        dp[i - jump] + costs[i - 1] + jump * jump;

                    dp[i] = Math.min(dp[i], currentCost);
                }
            }
        }

        return (int) dp[n];        
    }
}