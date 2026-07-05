class Solution {
public:

void dfs(int node,vector<int> adj[],vector<int>& vis){

    vis[node]=1;


    for(auto it:adj[node]){

        if(!vis[it])
            dfs(it,adj,vis);
    }
}


bool validPath(int n, vector<vector<int>>& edges,
int source,int destination){

    vector<int> adj[n];

    for(auto e:edges){

        adj[e[0]].push_back(e[1]);
        adj[e[1]].push_back(e[0]);
    }


    vector<int> vis(n,0);


    dfs(source,adj,vis);


    return vis[destination];
}
};