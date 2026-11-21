class Solution {
public:
   vector<vector<int>> adj;
    vector<int> newParent;
    vector<int> ans;
    vector<int> last;

    void dfs1(int node, string& s) {

        int c = s[node] - 'a';

        // Store the previous nearest ancestor
        int prev = last[c];

        // Find the new parent
        if (prev != -1) {
            newParent[node] = prev;
        }

        // Current node becomes the nearest
        // ancestor for its character
        last[c] = node;

        // Traverse original children
        for (int child : adj[node]) {
            dfs1(child, s);
        }

        // Backtrack
        last[c] = prev;
    }

    int dfs2(int node, vector<vector<int>>& tree) {

        int size = 1;

        for (int child : tree[node]) {
            size += dfs2(child, tree);
        }

        ans[node] = size;

        return size;
    }

    vector<int> findSubtreeSizes(vector<int>& parent, string s) {

        int n = parent.size();

        adj.resize(n);
        newParent = parent;
        ans.resize(n, 0);
        last.assign(26, -1);

        // Build original tree
        for (int i = 1; i < n; i++) {
            adj[parent[i]].push_back(i);
        }

        // Step 1: Find new parents
        dfs1(0, s);

        // Step 2: Build modified tree
        vector<vector<int>> tree(n);

        for (int i = 1; i < n; i++) {
            tree[newParent[i]].push_back(i);
        }

        // Step 3: Calculate subtree sizes
        dfs2(0, tree);

        return ans; 
    }
};