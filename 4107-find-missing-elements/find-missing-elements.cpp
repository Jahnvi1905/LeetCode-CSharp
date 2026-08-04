class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        
        std::vector<int> missing;
        
        // Check for gaps between adjacent elements
        for (size_t i = 0; i < nums.size() - 1; ++i) {
            int current = nums[i];
            int next = nums[i + 1];
            
            // If there is a gap between consecutive numbers, fill it
            for (int miss_val = current + 1; miss_val < next; ++miss_val) {
                missing.push_back(miss_val);
            }
        }
        
        return missing;
    }
};