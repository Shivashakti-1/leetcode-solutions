class Solution {
    public List<Integer> busiestServers(int k, int[] arrival, int[] load) {
        TreeSet<Integer> available = new TreeSet<>();

        PriorityQueue<long[]> busy = new PriorityQueue<>(
            (a, b) -> Long.compare(a[0], b[0])
        );

        int[] count = new int[k];

        for (int i = 0; i < k; i++) {
            available.add(i);
        }

        for (int i = 0; i < arrival.length; i++) {

            while (!busy.isEmpty() &&
                   busy.peek()[0] <= arrival[i]) {

                long[] server = busy.poll();
                available.add((int) server[1]);
            }

            int target = i % k;

            Integer server = available.ceiling(target);

            if (server == null && !available.isEmpty()) {
                server = available.first();
            }

            if (server == null) {
                continue;
            }

            available.remove(server);

            long freeTime = (long) arrival[i] + load[i];

            busy.offer(new long[]{freeTime, server});

            count[server]++;
        }

        int maxRequests = 0;

        for (int c : count) {
            maxRequests = Math.max(maxRequests, c);
        }

        List<Integer> ans = new ArrayList<>();

        for (int i = 0; i < k; i++) {
            if (count[i] == maxRequests) {
                ans.add(i);
            }
        }

        return ans;
        
    }
}