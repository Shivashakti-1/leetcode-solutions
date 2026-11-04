import java.util.*;

class Solution {

    class MedianWindow {

        TreeMap<Integer, Integer> left = new TreeMap<>();
        TreeMap<Integer, Integer> right = new TreeMap<>();

        long leftSum = 0;
        long rightSum = 0;

        int leftSize = 0;
        int rightSize = 0;
        int target;

        MedianWindow(int x) {
            target = (x + 1) / 2;
        }

        void add(int val) {
            if (left.isEmpty() || val <= left.lastKey()) {
                left.merge(val, 1, Integer::sum);
                leftSum += val;
                leftSize++;
            } else {
                right.merge(val, 1, Integer::sum);
                rightSum += val;
                rightSize++;
            }
            balance();
        }

        void remove(int val) {
            if (left.containsKey(val)) {
                removeFromMap(left, val);
                leftSum -= val;
                leftSize--;
            } else {
                removeFromMap(right, val);
                rightSum -= val;
                rightSize--;
            }
            balance();
        }

        void removeFromMap(TreeMap<Integer, Integer> map, int val) {
            int count = map.get(val);
            if (count == 1) {
                map.remove(val);
            } else {
                map.put(val, count - 1);
            }
        }

        void balance() {
            while (leftSize > target) {
                int val = left.lastKey();

                removeFromMap(left, val);
                leftSum -= val;
                leftSize--;

                right.merge(val, 1, Integer::sum);
                rightSum += val;
                rightSize++;
            }

            while (leftSize < target && !right.isEmpty()) {
                int val = right.firstKey();

                removeFromMap(right, val);
                rightSum -= val;
                rightSize--;

                left.merge(val, 1, Integer::sum);
                leftSum += val;
                leftSize++;
            }
        }

        long getCost() {
            long median = left.lastKey();

            long leftCost = median * leftSize - leftSum;
            long rightCost = rightSum - median * rightSize;

            return leftCost + rightCost;
        }
    }

    public long minOperations(int[] nums, int x, int k) {

        int n = nums.length;
        int m = n - x + 1;

        long[] cost = new long[m];

        MedianWindow window = new MedianWindow(x);

        for (int i = 0; i < x; i++) {
            window.add(nums[i]);
        }

        for (int i = 0; i < m; i++) {
            cost[i] = window.getCost();

            if (i < m - 1) {
                window.remove(nums[i]);
                window.add(nums[i + x]);
            }
        }

        long INF = Long.MAX_VALUE / 4;

        long[][] dp = new long[k + 1][n + 1];

        for (int j = 0; j <= k; j++) {
            Arrays.fill(dp[j], INF);
        }

        for (int i = 0; i <= n; i++) {
            dp[0][i] = 0;
        }

        for (int j = 1; j <= k; j++) {
            for (int i = 1; i <= n; i++) {

                dp[j][i] = dp[j][i - 1];

                if (i >= x && dp[j - 1][i - x] != INF) {
                    long take = dp[j - 1][i - x] + cost[i - x];
                    dp[j][i] = Math.min(dp[j][i], take);
                }
            }
        }

        return dp[k][n];
    }
}