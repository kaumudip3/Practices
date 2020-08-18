// use string stream for string to int problems
#include<sstream>

class Solution {
public:
    int myAtoi(string str) {
        if(str.size() == 0) return 0;
        if(isalpha(str[0])) return 0;
        signed int num=0; 
        stringstream ss(str);
        while(ss >> num)
        {
            //cout << num << " ";
            break;
        }
    return num;        
    }
    
};
