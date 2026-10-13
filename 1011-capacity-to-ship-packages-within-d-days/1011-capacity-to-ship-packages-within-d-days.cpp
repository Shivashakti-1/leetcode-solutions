
class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int low = *max_element(weights.begin(), weights.end());
        int high = 0;

        for (int w : weights) {
            high += w;
        }

        int ans = high;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            int daysNeeded = 1;
            int currentWeight = 0;

            for (int w : weights) {
                if (currentWeight + w > mid) {
                    daysNeeded++;
                    currentWeight = 0;
                }

                currentWeight += w;
            }

            if (daysNeeded <= days) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return ans;
    }
};
