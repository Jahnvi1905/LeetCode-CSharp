class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        // Ek dp vector banayein 'amount + 1' size ka
        // Isme initial value 'amount + 1' (max limit/infinity) rakh rahe hain
        vector<int> dp(amount + 1, amount + 1);
        
        // Base case: 0 amount banane ke liye 0 coins chahiye
        dp[0] = 0;
        
        // 1 se lekar target amount tak loop chalayein
        for (int i = 1; i <= amount; i++) {
            for (int j = 0; j < coins.size(); j++) {
                // Agar coin ki value current amount se chhoti ya barabar hai
                if (i - coins[j] >= 0) {
                    dp[i] = min(dp[i], dp[i - coins[j]] + 1);
                }
            }
        }
        
        // Agar value update nahi hui, matlab amount banana impossible hai
        if (dp[amount] > amount) {
            return -1;
        } else {
            return dp[amount];
        }
    }
};


// class Solution {
// public:

//     int helper(vector<int>& coins, int amount,vector<int>& dp){
//         int n = coins.size();
//         if(amount == 0){
//             return 0;
//         }

//         if(amount<0){
//             return -1;
//         }

//         if(dp[amount] != -1){
//             return dp[amount];
//         }
        
//         int minCoins = INT_MAX;
//         for(int i=0 ; i<n ;i++){
//             int result = helper(coins,amount-coins[i],dp);

//             if(result!=-1){
//                 minCoins = min(minCoins,result+1);
//             }
//         }
//          if(minCoins == INT_MAX){
//                 return dp[amount]= -1;
//             }else{
//                 return dp[amount] = minCoins;
//             }
//     }
//     int coinChange(vector<int>& coins, int amount) {

//         if(amount<0){
//             return -1;
//         }
//         vector<int> dp(amount+1,-1);
//      return helper(coins,amount,dp);


//     }
// };

