class Solution {
    public int findTheDistanceValue(int[] arr1, int[] arr2, int d) {
       Arrays.sort(arr2);

        int ans = 0;

        for (int x : arr1) {

            int idx = lowerBound(arr2, x - d);

            if (idx == arr2.length || arr2[idx] > x + d) {
                ans++;
            }
        }

        return ans;
    }

    public int lowerBound(int[] arr, int target) {

        int low = 0;
        int high = arr.length;

        while (low < high) {

            int mid = low + (high - low) / 2;

            if (arr[mid] < target) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }

        return low;
    }
}