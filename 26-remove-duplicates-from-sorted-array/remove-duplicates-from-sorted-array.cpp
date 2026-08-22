class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        // if (nums.empty()) return 0;
        
        // int start = 0; // Pointer 1: Unique elements ko track karega
        // int i = 1;     // Pointer 2: Pure array ko scan karega
        
        // while (i < nums.size()) {
        //     // Agar naya unique element milta hai
        //     if (nums[i] != nums[start]) {
        //         start++;                 // Unique boundary ko badhao
        //         nums[start] = nums[i];   // Naye element ko insert karo
        //     }
        //     i++; // Scanning pointer hamesha aage badhega
        // }
        
        // // Total unique elements 'start + 1' honge
        // return start + 1;

        if(nums.empty()) return 0;

        int i=0;
        for (i=0 ; i<nums.size();i++){
            for(int j=i+1 ; j<nums.size() ;){
                if(nums[i]== nums[j]){
                    nums.erase(nums.begin()+j);
                }
                else{
                    j++;
                }
            }
        }
        return nums.size();
    }
};
