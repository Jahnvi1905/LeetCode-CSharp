class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int i = 0;
        int j = 0;

        int ans = 0;

        while(i < nums1.size() && j < nums2.size()) {

            // valid pair
            if(nums1[i] <= nums2[j]) {

                ans = max(ans, j - i);
                j++;
            }
            else {
                // move i forward
                i++;
            }

            // j should never be behind i
            if(i > j) {
                j = i;
            }
        }

        return ans;
    }
};