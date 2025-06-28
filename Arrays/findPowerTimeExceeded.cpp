class Solution {
public:
//normal brute force, just make a for loop and multiply that number so many times
//here, the n value can be between 2^31-1 and -2^31
    double myPow(double x, long long int n) {
        double product = 1;
        //we multiply here
        if(n > 0) {
            for(long long int i = 1; i <= n; i++)
            {   
                product *= x;
            }
        }

        else
        {
            //here, we are dividing 
            for(long long int i = 1; i <= abs(n); i++)
            {
                product /= x;
            }
        }
        return product;
    }
};
