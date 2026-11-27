class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size();

        // Step 1: Calculate free items for each item type
        vector<int> freeItems(n, 0);

        for (int i = 0; i < n; i++) {
            int factor = items[i][0];

            for (int j = 0; j < n; j++) {
                if (i != j && items[j][0] % factor == 0) {
                    freeItems[i]++;
                }
            }
        }

        // Step 2: DP initialization
        const int NEG = -1e9;

        vector<int> dp(budget + 1, NEG);
        dp[0] = 0;

        // Step 3: Process each item type
        for (int i = 0; i < n; i++) {

            int p = items[i][1];
            int f = freeItems[i];

            vector<int> prev = dp;
            vector<int> next = dp;

            // Process each remainder modulo price
            for (int r = 0; r < p && r <= budget; r++) {

                int best = NEG;

                for (int t = 0, c = r;
                     c <= budget;
                     t++, c += p) {

                    // Consider buying at least one copy
                    if (t > 0) {

                        int x = c - p;

                        if (prev[x] != NEG) {
                            best = max(best, prev[x] - (t - 1));
                        }
                    }

                    // First copy gives free items.
                    // Additional copies give only 1 each.
                    if (best != NEG) {
                        next[c] = max(next[c], f + t + best);
                    }
                }
            }

            dp = next;
        }

        // Step 4: Maximum answer within budget
        return *max_element(dp.begin(), dp.end());
        
    }
};