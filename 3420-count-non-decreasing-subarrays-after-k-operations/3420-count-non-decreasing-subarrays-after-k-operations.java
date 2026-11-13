class Solution {
    public long countNonDecreasingSubarrays(int[] nums, int k) {
        int n = nums.length;

        long ans = 0;
        long cost = 0;

        int j = n - 1;

        Deque<int[]> dq = new ArrayDeque<>();

        for (int i = n - 1; i >= 0; i--) {

            int num = nums[i];
            int count = 1;

            while (!dq.isEmpty() && dq.peekLast()[0] < num) {

                int[] last = dq.pollLast();

                cost += (long) (num - last[0]) * last[1];

                count += last[1];
            }

            dq.offerLast(new int[]{num, count});

            while (cost > k) {

                int[] first = dq.peekFirst();

                int rightmostNum = first[0];

                cost -= (long) rightmostNum - nums[j];

                j--;

                if (first[1] > 1) {
                    first[1]--;
                } else {
                    dq.pollFirst();
                }
            }

            ans += j - i + 1;
        }

        return ans;        
    }
}