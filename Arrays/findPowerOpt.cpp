// Implement pow(x, n), which calculates x raised to the power n (i.e., xn).
// Example 1:

// Input: x = 2.00000, n = 10
// Output: 1024.00000
// Example 2:

// Input: x = 2.10000, n = 3
// Output: 9.26100
// Example 3:

// Input: x = 2.00000, n = -2
// Output: 0.25000
// Explanation: 2-2 = 1/22 = 1/4 = 0.25

class Solution {
public:
    double myPow(double x, int n) {
        //the logic here is that, if we have a even power, we do (x^2)^n/2. if odd, then prod = prod*(x) and pow = pow-1 and then you get an even power that you have to compute
        double product = 1;
        //now, we make a copy of n and make it positive
        long long power = n;
        if(power<0){power *= -1;}
        //now, implement logic
        //base case
        while(power) {       
            if(power%2==0)
            {
                x = x*x;
                power = power/2;
            }
            else
            {
                product = product*x;
                power = power-1;
            }
        }
        if(n<0)
        {
            product = 1/product;
        }
        return product;
    }
};
