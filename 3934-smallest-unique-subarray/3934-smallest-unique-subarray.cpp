class Solution {
public:
    int smallestUniqueSubarray(vector<int>& nums) {
        int n = nums.size();

        vector<int> sa(n), rank(n), newRank(n);
        iota(sa.begin(), sa.end(), 0);

        sort(sa.begin(), sa.end(), [&](int a, int b) {
            return nums[a] < nums[b];
        });

        int classes = 1;
        rank[sa[0]] = 0;

        for (int i = 1; i < n; i++) {
            if (nums[sa[i]] != nums[sa[i - 1]])
                classes++;

            rank[sa[i]] = classes - 1;
        }

        // Build Suffix Array using doubling
        for (int len = 1; classes < n; len *= 2) {

            auto cmp = [&](int a, int b) {
                if (rank[a] != rank[b])
                    return rank[a] < rank[b];

                int x = (a + len < n) ? rank[a + len] : -1;
                int y = (b + len < n) ? rank[b + len] : -1;

                return x < y;
            };

            sort(sa.begin(), sa.end(), cmp);

            newRank[sa[0]] = 0;
            int newClasses = 1;

            for (int i = 1; i < n; i++) {
                if (cmp(sa[i - 1], sa[i]))
                    newClasses++;

                newRank[sa[i]] = newClasses - 1;
            }

            rank.swap(newRank);
            classes = newClasses;
        }

        // Build inverse suffix array
        vector<int> pos(n);

        for (int i = 0; i < n; i++)
            pos[sa[i]] = i;

        // Kasai's LCP algorithm
        vector<int> lcp(n, 0);
        int k = 0;

        for (int i = 0; i < n; i++) {
            int p = pos[i];

            if (p == n - 1) {
                k = 0;
                continue;
            }

            int j = sa[p + 1];

            while (i + k < n && j + k < n &&
                   nums[i + k] == nums[j + k]) {
                k++;
            }

            lcp[p] = k;

            if (k > 0)
                k--;
        }

        // Find smallest unique subarray
        int ans = n;

        for (int i = 0; i < n; i++) {
            int left = (i > 0) ? lcp[i - 1] : 0;
            int right = lcp[i];

            int candidate = max(left, right) + 1;

            if (candidate <= n - sa[i])
                ans = min(ans, candidate);
        }

        return ans;
        
    }
};