class Solution {
public:
    int maxLength(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;

        for (int i = 0; i < n; i++) {

            long long product = 1;
            long long g = 0;
            long long l = 1;

            for (int j = i; j < n; j++) {

                int x = nums[j];

                // Update product
                product *= x;

                // Update GCD
                g = gcd(g, (long long)x);

                // Update LCM
                l = (l / gcd(l, (long long)x)) * x;

                // Check product equivalence
                if (product == g * l) {
                    ans = max(ans, j - i + 1);
                }
                else if (j - i + 1 >= 3) {
                    // Once invalid for length >= 3,
                    // extending cannot make it valid again.
                    break;
                }
            }
        }
    return ans;
        
    }
};