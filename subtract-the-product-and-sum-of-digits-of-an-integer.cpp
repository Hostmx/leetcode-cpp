class Solution {
public:
    int subtractProductAndSum(int n) {
        int product = 1;
        int sum = 0;
        if(n < 0)
            n = -n;
        else if(n==0)
            return 0;

        while(n > 0)
        {
            int remainder = n % 10;
            n /= 10;
            sum += remainder;
            product *=remainder;
        }
        return product - sum;
    }
};
