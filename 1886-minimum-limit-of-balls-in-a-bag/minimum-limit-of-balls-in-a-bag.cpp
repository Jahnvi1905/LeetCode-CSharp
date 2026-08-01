class Solution {
public:

    bool possible(vector<int>& nums,int penalty,int maxOp){

        long long ops=0;

        for(int x:nums)
            ops+=(x-1)/penalty;

        return ops<=maxOp;
    }

    int minimumSize(vector<int>& nums,int maxOperations){

        int low=1;

        int high=*max_element(nums.begin(),nums.end());

        while(low<high){

            int mid=low+(high-low)/2;

            if(possible(nums,mid,maxOperations))
                high=mid;

            else
                low=mid+1;
        }

        return low;
    }
};