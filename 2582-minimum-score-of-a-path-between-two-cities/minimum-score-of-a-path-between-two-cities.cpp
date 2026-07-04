class Solution {
public:

    void dfs(int node,
             vector<vector<pair<int,int>>> &adj,
             vector<int>& visited,
             int &ans)
    {

        visited[node] = 1;


        for(auto it : adj[node])
        {
            int neighbour = it.first;
            int distance = it.second;


            ans = min(ans, distance);


            if(!visited[neighbour])
            {
                dfs(neighbour, adj, visited, ans);
            }
        }
    }


    int minScore(int n, vector<vector<int>>& roads) {
        
        vector<vector<pair<int,int>>> adj(n+1);


        // make graph
        for(auto road : roads)
        {
            int u = road[0];
            int v = road[1];
            int d = road[2];


            adj[u].push_back({v,d});
            adj[v].push_back({u,d});
        }


        vector<int> visited(n+1,0);

        int ans = INT_MAX;


        dfs(1, adj, visited, ans);


        return ans;
    }
};