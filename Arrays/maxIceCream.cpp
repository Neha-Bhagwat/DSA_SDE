// It is a sweltering summer day, and a boy wants to buy some ice cream bars.
// At the store, there are n ice cream bars. You are given an array costs of length n, where costs[i] is the price of the ith ice cream bar in coins. The boy initially has coins coins to spend, and he wants to buy as many ice cream bars as possible. 
// Note: The boy can buy the ice cream bars in any order.
// Return the maximum number of ice cream bars the boy can buy with coins coins.
// You must solve the problem by counting sort.
// Example 1:

// Input: costs = [1,3,2,4,1], coins = 7
// Output: 4
// Explanation: The boy can buy ice cream bars at indices 0,1,2,4 for a total price of 1 + 3 + 2 + 1 = 7.
// Example 2:

// Input: costs = [10,6,8,7,7,8], coins = 5
// Output: 0
// Explanation: The boy cannot afford any of the ice cream bars.
// Example 3:

// Input: costs = [1,6,3,1,2,5], coins = 20
// Output: 6
// Explanation: The boy can buy all the ice cream bars for a total price of 1 + 6 + 3 + 1 + 2 + 5 = 18.

//Here, i used a map, instead of which a frequency array was expected

class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {;
        int count = 0, n = costs.size();
        map<int,int> numbers;
    
        for(int i = 0; i < n; i++)
        {
            //if map doesnt have that key
            if(numbers.find(costs[i]) != numbers.end()) numbers.find(costs[i])->second++;
            else numbers.insert({costs[i], 1});
            // cout<<"No of icecreams :"<<numbers[costs[i]]<<" Cost : "<<costs[i]<<" Index : "<<i<<endl; 
        }

        //now the map is created and ordered
        int j = 0;
        int maxi = *max_element(costs.begin(), costs.end());
        // cout<<maxi<<endl;
        while(j <= maxi && coins > 0)
        {
            // cout<<"No of icecreams that cost "<<j<<" : "<<numbers[j]<<". No of coins left : "<<coins<<endl;
            if(numbers[j]>0 && coins>=j) 
            {   
                count++;
                numbers[j]--;
                coins = coins - j;
                // cout<<"Count : "<<count<<" Cost of icecream : "<<j<<endl;
            }
            else j++;
        }
        return count;
    }
};
