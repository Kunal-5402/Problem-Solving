class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if (n == 0)
            return {};
        if (n == 1)
            return {0};

        vector<vector<int>> adj(n);
        vector<int> indegree(n, 0);

        for (auto& edge : edges) {
            int a = edge[0];
            int b = edge[1];

            adj[a].push_back(b);
            adj[b].push_back(a);

            indegree[a]++;
            indegree[b]++;
        }
        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 1)
                q.push(i);
        }

        vector<int> ans;

        while (q.size() > 0) {

            ans.clear();
            int size = q.size();

            while (size--) {
                int leaf = q.front();
                q.pop();

                ans.push_back(leaf);

                for (auto& neighbor : adj[leaf]) {
                    indegree[neighbor]--;
                    if (indegree[neighbor] == 1)
                        q.push(neighbor);
                }
            }
        }

        return ans;
    }
};