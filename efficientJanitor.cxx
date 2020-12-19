/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include<string>
#include<cstdlib>
#include<vector>
#include<algorithm>
using namespace std;

// efficient janitor similar to boat rescue
int numRescueBoats(vector<float> people, float limit) {
        sort(people.begin(), people.end());
        int i = 0, j = people.size() - 1;
        int ans = 0;

        while (i <= j) {
            ans++;
            if (people[i] + people[j] <= limit)
                i++;
            j--;
        }

        return ans;
    }
int getlen(string in)
{
    int res = in.size();
    int n=in.size();
    string temp = in;
    for(int i=1;i<n;i++)
    {
        if(temp[i] != in[0]) continue;
        int cnt =0;
        int k=i;
        for(int j=0;j<n;j++)
        {
            if(temp[k++] == in[j]) cnt++;
            else {break;}
        }
        if(cnt >0) res+=cnt;
        
    }
    return res;
}
int main()
{
    
  cout << numRescueBoats({1.01, 1.01, 3.0, 2.7, 1.99, 2.3, 1.7}, 3);
    return 0;
}
