class Solution {
    private void solve(int idx, int target, int[] arr,List<List<Integer>> ans, List<Integer> ds)
    {
        if(idx==arr.length)
        {
            if(target==0)
            {
                ans.add(new ArrayList<>(ds));
            }
            return;
        }

        if(arr[idx]<=target)
        {
            ds.add(arr[idx]);
            solve(idx, target-arr[idx], arr, ans, ds);
            ds.remove(ds.size()-1);
        }
        solve(idx+1, target, arr, ans, ds);
    }
    public List<List<Integer>> combinationSum(int[] candidates, int target) {
        List<List<Integer>> ans = new ArrayList<>();
        List<Integer> ds = new ArrayList<>();   
        solve(0, target, candidates, ans, ds);

        return ans;     
    }
}