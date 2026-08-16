class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {
        // Track the frequencies of remainders when divided by 3
        vector<int> count(3, 0);
        for (int stone : stones) {
            count[stone % 3]++;
        }

        // Case 1: The number of type-0 stones (divisible by 3) is even.
        // Even type-0 stones do not shift the initial advantage between players.
        if (count[0] % 2 == 0) {
            // Alice needs at least one stone of type 1 and one stone of type 2 
            // to manipulate the sequence and force Bob into a trap.
            return count[1] > 0 && count[2] > 0;
        }

        // Case 2: The number of type-0 stones (divisible by 3) is odd.
        // Odd type-0 stones effectively switch who gets stuck making the losing move.
        // Alice needs a clear structural advantage in type-1 or type-2 count differences.
        return abs(count[1] - count[2]) > 2;
    }
};
