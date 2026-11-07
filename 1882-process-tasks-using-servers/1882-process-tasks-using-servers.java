class Solution {
    public int[] assignTasks(int[] servers, int[] tasks) {
     int n = servers.length;
        int m = tasks.length;

        PriorityQueue<int[]> available = new PriorityQueue<>(
            (a, b) -> {
                if (a[0] != b[0]) {
                    return Integer.compare(a[0], b[0]);
                }
                return Integer.compare(a[1], b[1]);
            }
        );

        PriorityQueue<long[]> busy = new PriorityQueue<>(
            (a, b) -> {
                if (a[0] != b[0]) {
                    return Long.compare(a[0], b[0]);
                }
                if (a[1] != b[1]) {
                    return Long.compare(a[1], b[1]);
                }
                return Long.compare(a[2], b[2]);
            }
        );

        for (int i = 0; i < n; i++) {
            available.offer(new int[]{servers[i], i});
        }

        int[] ans = new int[m];

        long time = 0;

        for (int i = 0; i < m; i++) {

            time = Math.max(time, i);

            while (!busy.isEmpty() && busy.peek()[0] <= time) {

                long[] server = busy.poll();

                available.offer(new int[]{
                    (int) server[1],
                    (int) server[2]
                });
            }

            if (available.isEmpty()) {

                time = busy.peek()[0];

                while (!busy.isEmpty() && busy.peek()[0] <= time) {

                    long[] server = busy.poll();

                    available.offer(new int[]{
                        (int) server[1],
                        (int) server[2]
                    });
                }
            }

            int[] server = available.poll();

            int weight = server[0];
            int index = server[1];

            ans[i] = index;

            long freeTime = time + tasks[i];

            busy.offer(new long[]{
                freeTime,
                weight,
                index
            });
        }

        return ans;
    }
        
}