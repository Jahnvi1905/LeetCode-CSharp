class Solution {
public:
    int divide(int dividend, int divisor) {

        // overflow case
        if(dividend == INT_MIN && divisor == -1)
            return INT_MAX;

        long long dvd = dividend;
        long long dvs = divisor;

        // sign check
        bool negative = (dvd < 0) ^ (dvs < 0);

        // make positive
        dvd = llabs(dvd);
        dvs = llabs(dvs);

        long long quotient = 0;

        while(dvd >= dvs) {

            long long temp = dvs;
            long long multiple = 1;

            while((temp << 1) <= dvd) {
                temp <<= 1;
                multiple <<= 1;
            }

            dvd -= temp;
            quotient += multiple;
        }

        if(negative)
            quotient = -quotient;

        return (int)quotient;
    }
};