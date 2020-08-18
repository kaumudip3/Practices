// n is a power of three if and only if i is an integer. we check if a number is an integer by taking the decimal part (using % 1) and checking if it is 0.


class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n==0) return false;
        if(n == 1) return true;
      return fmod(log10(n)/log10(3), 1)==0;
    
   
    }
};
