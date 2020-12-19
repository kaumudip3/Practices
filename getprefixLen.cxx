/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include<string>
#include<cstdlib>
using namespace std;

int getlen(string in)
{
    int res = in.size();
    int n=in.size();
    if(n==0) return 0;
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
    
    cout<< " " << (getlen("ababaa") == 11);
    cout<< " " << (getlen("abcabcd") == 10);
    cout<< " " << (getlen("aa") == 3);
    return 0;
}
