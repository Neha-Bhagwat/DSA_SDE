class Solution {
public:
    double myPow(double x, int n) {
        //the logic here is that, if we have a even power, we do (x^2)^n/2. if odd, then prod = prod*(x) and then you get an even power that you have to compute
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
                power = (power-1);
            }
        }
        if(n<0)
        {
            product = 1/product;
        }
        return product;
    }
};
