class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {

        int n = s.size();

        vector<int> vis(n, 0);

        queue<int> q;

        q.push(0);

        vis[0] = 1;

        int farthest = 0;

        while(!q.empty())
        {
            int i = q.front();
            q.pop();

            if(i == n - 1)
            {
                return true;
            }

            int start = max(i + minJump, farthest + 1);
            int end = min(i + maxJump, n - 1);

            for(int j = start; j <= end; j++)
            {
                if(s[j] == '0' && !vis[j])
                {
                    vis[j] = 1;
                    q.push(j);
                }
            }

            farthest = end;
        }

        return false;
    }
};