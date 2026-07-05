class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
        vector<int> adj[numCourses];


        // create graph
        for(auto it : prerequisites)
        {
            int a = it[0];
            int b = it[1];


            // b before a
            // b --> a
            adj[b].push_back(a);
        }


        vector<int> indegree(numCourses,0);


        for(int i=0;i<numCourses;i++)
        {
            for(auto it: adj[i])
            {
                indegree[it]++;
            }
        }



        queue<int> q;


        for(int i=0;i<numCourses;i++)
        {
            if(indegree[i]==0)
                q.push(i);
        }


        vector<int> topo;


        while(!q.empty())
        {
            int node=q.front();
            q.pop();


            topo.push_back(node);


            for(auto it: adj[node])
            {
                indegree[it]--;


                if(indegree[it]==0)
                    q.push(it);
            }
        }


        return topo.size()==numCourses;
    }
};