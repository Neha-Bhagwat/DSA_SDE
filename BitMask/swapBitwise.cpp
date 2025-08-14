// You are given two numbers a and b. Your task is to swap the given two numbers.

// Note: Try to do it without a temporary variable.

class Solution {
  public:
    pair<int, int> get(int a, int b) {
        
        a = a^b;
        b = a^b;
        a = a^b;
        
        return {a,b};
    }
};
