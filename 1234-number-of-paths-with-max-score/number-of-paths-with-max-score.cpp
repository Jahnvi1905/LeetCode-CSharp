class Solution {
public:

    vector<int> pathsWithMaxScore(vector<string>& board) {
        
        int n = board.size();

        int mod = 1e9+7;


        vector<vector<int>> score(n, vector<int>(n,-1));
        vector<vector<int>> ways(n, vector<int>(n,0));


        // start point S
        score[n-1][n-1] = 0;
        ways[n-1][n-1] = 1;



        for(int i=n-1;i>=0;i--)
        {
            for(int j=n-1;j>=0;j--)
            {

                if(board[i][j]=='X')
                    continue;


                if(i==n-1 && j==n-1)
                    continue;



                int best = -1;
                int count = 0;



                vector<pair<int,int>> dir = {
                    {1,0},
                    {0,1},
                    {1,1}
                };


                for(auto d:dir)
                {
                    int ni = i+d.first;
                    int nj = j+d.second;


                    if(ni<n && nj<n && score[ni][nj]!=-1)
                    {

                        if(score[ni][nj] > best)
                        {
                            best = score[ni][nj];
                            count = ways[ni][nj];
                        }

                        else if(score[ni][nj] == best)
                        {
                            count = 
                            (count + ways[ni][nj])%mod;
                        }
                    }
                }



                if(best == -1)
                    continue;



                int value = 0;


                if(board[i][j]>='1' && board[i][j]<='9')
                {
                    value = board[i][j]-'0';
                }



                score[i][j] = best + value;

                ways[i][j] = count;

            }
        }


        if(ways[0][0]==0)
            return {0,0};


        return {score[0][0], ways[0][0]};
    }
};