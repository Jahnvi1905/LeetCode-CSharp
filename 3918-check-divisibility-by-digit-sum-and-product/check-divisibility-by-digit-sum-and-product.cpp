class Solution {
public:
    bool checkDivisibility(int n) {
        int temp = n;
        int digit_sum = 0;
        int digit_product = 1;
        
        // Extract each digit to calculate sum and product
        while (temp > 0) {
            int digit = temp % 10;
            digit_sum += digit;
            digit_product *= digit;
            temp /= 10;
        }
        
        int total_sum = digit_sum + digit_product;
        
        // Return true if n is perfectly divisible by the total sum
        return n % total_sum == 0;
    }
};