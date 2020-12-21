#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);


/*
 * Complete the 'variantsCount' function below.
 *
 * The function is expected to return a LONG_INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. INTEGER s0
 *  3. INTEGER k
 *  4. INTEGER b
 *  5. INTEGER m
 *  6. LONG_INTEGER a
 */

long variantsCount(int n, int s0, int k, int b, int m, long a) {
long res=0;
if(n==0) return 0;
vector<long> s(n+1, 0);
s[0] = s0;
for(int i=1;i<n;i++)
{
    s[i] = (k*s[i-1]+b);
    s[i] = s[i]%m +1+s[i-1];
}
sort(s.begin(), s.end());

int st=0,ed=s.size()-1;

while(ed >=st)
{
    if(s[st] >0 && s[st]< a){
    if(s[st]*s[ed] <=a)
    {
        res+= 2*(ed-st)+1;
       
        st++;
    }
    else {
    ed--;
    }
    }
    else{    st++;}
}
return res;
}

int main()
