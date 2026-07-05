class Solution {
public:

int orangesRotting(vector<vector<int>>& grid){

    int n=grid.size();
    int m=grid[0].size();


    queue<pair<int,int>> q;

    int fresh=0;


    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){

            if(grid[i][j]==2)
                q.push({i,j});

            if(grid[i][j]==1)
                fresh++;
        }
    }


    int time=0;

    int dr[]={1,-1,0,0};
    int dc[]={0,0,1,-1};


    while(!q.empty() && fresh){

        int size=q.size();

        time++;


        while(size--){

            auto [r,c]=q.front();
            q.pop();


            for(int k=0;k<4;k++){

                int nr=r+dr[k];
                int nc=c+dc[k];


                if(nr>=0&&nc>=0&&nr<n&&nc<m
                   && grid[nr][nc]==1){

                    grid[nr][nc]=2;

                    fresh--;

                    q.push({nr,nc});
                }
            }
        }
    }


    if(fresh)
        return -1;


    return time;
}
};