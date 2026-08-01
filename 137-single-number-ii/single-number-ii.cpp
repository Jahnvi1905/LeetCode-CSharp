class Solution {
public:
    int singleNumber(vector<int>& nums) {

        int ans=0;

        for(int b=0;b<32;b++){

            int cnt=0;

            for(int x:nums)

                if(x&(1<<b))
                    cnt++;

            if(cnt%3)

                ans|=(1<<b);
        }

        return ans;
    }
};