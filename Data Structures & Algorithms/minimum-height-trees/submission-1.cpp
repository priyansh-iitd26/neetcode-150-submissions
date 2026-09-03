/*
    we find answer in central nodes
        - leaf nodes take us to the central nodes
    answer can be atmost 2 nodes, i.e., there can be atmost 2 MHTs
        - think of it as fermat point in undirected trees
        - there can be `atmost two` fermat points in trees
*/
class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n == 1)
            return {0};

        vector<vector<int>> adj(n);
        vector<int> degree(n);

        for(auto &edge : edges){
            int u = edge[0];
            int v = edge[1];
            degree[u]++;
            degree[v]++;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        queue<int> q;
        for(int i = 0; i < n; i++){
            if(degree[i] == 1)
                q.push(i);
        }

        while(n > 2){
            int sz = q.size();

            n -= sz;

            while(sz--){
                int u = q.front();
                q.pop();

                for(auto &v : adj[u]){
                    degree[v]--;
                    if(degree[v] == 1)
                        q.push(v);
                }
            }
        }

        vector<int> ans;

        while(!q.empty()){
            ans.push_back(q.front());
            q.pop();
        }

        return ans;
    }
};
// tc -> O(n)
// sc -> O(n)