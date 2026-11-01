class Solution {
    public void solve(int start, int n, int k, List<List<Integer>> ans, List<Integer> curr)
    {
        if(curr.size()==k)
        {
            ans.add(new ArrayList<>(curr));

            return;
        }
        for(int i=start;i<=n;i++)
        {
            curr.add(i);

            solve(i+1,n,k,ans,curr);

            curr.remove(curr.size()-1);
        }
    }
    public List<List<Integer>> combine(int n, int k) {
        List<List<Integer>> ans = new ArrayList<>();
        List<Integer> curr = new ArrayList<>();

        solve(1,n,k,ans,curr);

        return ans;        
    }
}