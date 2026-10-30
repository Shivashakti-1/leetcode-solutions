class Solution {
public:
    void getallSubsets(vector<int> &nums, vector<int> &ans, int i, vector<vector<int>> &subs)
    {
        if(i==nums.size())
        {
            subs.push_back({ans});
            return;
        }
        ans.push_back(nums[i]);
        getallSubsets(nums, ans, i+1, subs);

        ans.pop_back();

        int idx=i+1;
        while(idx<nums.size() && nums[idx]==nums[idx-1])
        {
            idx++;
        }

        getallSubsets(nums, ans, idx, subs);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> subs;
        vector<int> ans;
        getallSubsets(nums,ans,0,subs);
        return subs;        
    }
};