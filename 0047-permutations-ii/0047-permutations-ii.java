class Solution {
    public void solve(int[] nums, boolean[] used,
                      List<Integer> current,
                      List<List<Integer>> ans) {

        if (current.size() == nums.length) {
            ans.add(new ArrayList<>(current));
            return;
        }

        for (int i = 0; i < nums.length; i++) {

            if (used[i]) {
                continue;
            }

            if (i > 0 && nums[i] == nums[i - 1] && !used[i - 1]) {
                continue;
            }

            current.add(nums[i]);
            used[i] = true;

            solve(nums, used, current, ans);

            current.remove(current.size() - 1);
            used[i] = false;
        }
    }

    public List<List<Integer>> permuteUnique(int[] nums) {
        Arrays.sort(nums);

        boolean[] used = new boolean[nums.length];
        List<Integer> current = new ArrayList<>();
        List<List<Integer>> ans = new ArrayList<>();

        solve(nums, used, current, ans);

        return ans;
    }
}