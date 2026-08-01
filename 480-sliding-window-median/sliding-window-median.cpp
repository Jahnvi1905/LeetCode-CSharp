class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        vector<double> medians;
        multiset<double> window(nums.begin(), nums.begin() + k);
        
        auto midIt = next(window.begin(), (k - 1) / 2);
        
        for (int i = k; ; ++i) {
            double currentMedian = (k % 2 == 0) ? (*midIt + *next(midIt)) / 2.0 : *midIt;
            medians.push_back(currentMedian);
            
            if (i == nums.size()) {
                break;
            }
            
            window.insert(nums[i]);
            if (nums[i] < *midIt) {
                --midIt;
            }
            
            double outgoingValue = nums[i - k];
            if (outgoingValue <= *midIt) {
                ++midIt;
            }
            
            window.erase(window.lower_bound(outgoingValue));
        }
        
        return medians;
    }
};

