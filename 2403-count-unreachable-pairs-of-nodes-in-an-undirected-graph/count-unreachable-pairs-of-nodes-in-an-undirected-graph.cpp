class Solution {
public:

long long dfs(int node,
vector<int> adj[],
vector<int>& vis){


    vis[node]=1;


    long long count=1;



    for(auto it:adj[node]){


        if(!vis[it]){


            count += dfs(it,adj,vis);
        }
    }



    return count;
}



long long countPairs(int n, vector<vector<int>>& edges){


    vector<int> adj[n];


    for(auto e:edges){

        adj[e[0]].push_back(e[1]);

        adj[e[1]].push_back(e[0]);
    }



    vector<int> vis(n,0);



    long long ans=0;

    long long remaining=n;



    for(int i=0;i<n;i++){


        if(!vis[i]){


            long long size=dfs(i,adj,vis);


            ans += size*(remaining-size);


            remaining -= size;
        }
    }



    return ans;
}
};