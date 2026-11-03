class Solution {
    public void solve(int n, int open, int close, String current, List<String> ans)
    {
        if(current.length()==2*n)
        {
            ans.add(current);
            return;
        }
        if(open<n)
        {
            solve(n,open+1,close,current+"(",ans);
        }
        if(close<open)
        {
            solve(n,open,close+1,current+")",ans);
        }
    }
    public List<String> generateParenthesis(int n) {
        List<String> ans=new ArrayList<>();

        solve(n,0,0,"",ans);

        return ans;        
    }
}