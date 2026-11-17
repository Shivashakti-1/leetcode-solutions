class Solution {
public:
    int minimumChanges(string s, int k) {
         int n = s.size();

        // Step 1: Precompute substring costs
        vector<vector<int>> cost(n, vector<int>(n, INT_MAX));

        for (int i = 0; i < n; i++) {

            for (int j = i + 1; j < n; j++) {

                int len = j - i + 1;

                // Try all proper divisors
                for (int d = 1; d < len; d++) {

                    if (len % d != 0) continue;

                    int changes = 0;

                    // Divide into d groups
                    for (int r = 0; r < d; r++) {

                        int cnt = (len - 1 - r) / d + 1;

                        // Make each group palindrome
                        for (int t = 0; t < cnt / 2; t++) {

                            int left = i + r + t * d;

                            int right = i + r + (cnt - 1 - t) * d;

                            if (s[left] != s[right]) {
                                changes++;
                            }
                        }
                    }

                    cost[i][j] = min(cost[i][j], changes);
                }
            }
        }

        // Step 2: DP
        const int INF = 1e9;

        vector<vector<int>> dp(
            n + 1, vector<int>(k + 1, INF)
        );

        // Base case
        dp[0][0] = 0;

        // Step 3: Partition into exactly k parts
        for (int parts = 1; parts <= k; parts++) {

            for (int i = 2 * parts; i <= n; i++) {

                // Starting index of last substring
                for (int p = 2 * (parts - 1); p <= i - 2; p++) {

                    if (dp[p][parts - 1] == INF) {
                        continue;
                    }

                    dp[i][parts] = min(
                        dp[i][parts],
                        dp[p][parts - 1] + cost[p][i - 1]
                    );
                }
            }
        }


        return dp[n][k];
        
    }
};