class Solution {
    private void solve(int idx, int[] arr, int target, List<List<Integer>> ans, List<Integer> ds)
    {
        if(target==0)
        {
            ans.add(new ArrayList<>(ds));
            return;
        }
        for(int i=idx;i<arr.length;i++)
        {
            if(i>idx && arr[i]==arr[i-1])continue;
            if(arr[idx]>target)break;

            ds.add(arr[i]);
            solve(i+1, arr, target-arr[i], ans, ds);
            ds.remove(ds.size()-1);
        }
        
    }
    public List<List<Integer>> combinationSum2(int[] candidates, int target) {
        List<List<Integer>> ans = new ArrayList<>();
        Arrays.sort(candidates);
        solve(0,candidates,target,ans,new ArrayList());

        return ans;        
    }
}