/*Given an array of n positive integers and a positive integer s, find the minimal length of a contiguous subarray of which the sum ≥ s. If there isn't one, return 0 instead.

Example: 

Input: s = 7, nums = [2,3,1,2,4,3]
Output: 2
Explanation: the subarray [4,3]
*/

class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
    int st = 0, e= 0, cnt = -1, len = nums.size();
        int ss=0; 
        if(len == 0) return 0;
        cout << len <<" ";
        while(st <len && e < len)
        {
           ss += nums[e];
            if(ss >= s)
            {
                 cout << e << "="; 
                if(cnt > (e-st+1) ||cnt <0) cnt = e-st+1;
                    st++; 
                    e=st;
                    ss=0;
            } 
            else
            e++;
        }
    
        return (cnt > 0 ) ?cnt:0;
    }
};
