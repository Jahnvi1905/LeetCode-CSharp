class Solution {
public:

    bool possible(vector<int>& pos,int m,int dist){

        int placed=1;

        int last=pos[0];

        for(int i=1;i<pos.size();i++){

            if(pos[i]-last>=dist){

                placed++;
                last=pos[i];
            }
        }

        return placed>=m;
    }

    int maxDistance(vector<int>& position,int m){

        sort(position.begin(),position.end());

        int low=1;

        int high=position.back()-position.front();

        while(low<high){

            int mid=(low+high+1)/2;

            if(possible(position,m,mid))
                low=mid;

            else
                high=mid-1;
        }

        return low;
    }
};