/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include<vector>
#include<map>
#include<set>
#include<cstdlib>
#include<algorithm>
using namespace std;

int min_steps(std::vector<int>arr)
{
    if(arr.size() < 2) return 0;
    std::sort(arr.begin(), arr.end());
    set<int> sa;
    
    int min1 = arr[0];
    std::map<int, int> freq;
    for(auto x : arr)
    {
        freq[x]++;
        sa.insert(x);
    }
    if(freq.size() < 2) return 0;
    vector<int> noduplicates;
    for(auto i : sa)
    {
        noduplicates.push_back(i);
    }
    int fprev = freq[noduplicates[0]];
    int res=0;
    for(int i=1;i<sa.size();i++)
    {
        res += arr.size()-fprev;
        fprev += freq[noduplicates[i]];
    }
    return res;
}
int main()
{
    
    vector<int> a = {50};int i=0;
    cout<<"\n"<<i++ << (min_steps({50}) == 0);
    cout<<"\n" <<i++<< (min_steps({10,10}) == 0);
    cout<<"\n" <<i++<< (min_steps({5, 2, 1}) == 3);
    cout<<"\n" <<i++<< (min_steps({4, 5, 5, 4, 2}) == 6);
    cout<<"\n" <<i++<< (min_steps({1, 2, 2, 3, 3, 4}) == 9);
    cout<<"\n" <<i++<< (min_steps({1, 1, 2, 2, 2, 3, 3, 3, 4, 4}) == 15);
    return 0;
}
