#include <iostream>
#include<vector>
#include<stdlib.h>
#include<algorithm>
using namespace std;
//bool alternatingSort(std::vector<int> a);
namespace
{
	bool alternatingSort(std::vector<int> a) {
		int len = size(a);
		std::vector<int> b(len, 0);
		int i = 1;
		b[0] = a[0];
		while (i < len)
		{
			//even
			if (i % 2 == 0)
			{
				b[i] = a[i - 1];
			}

			//odd
			else
			{
				int temp = i / 2;
				b[i] = a[len - 1 - temp];
			}
			if (b[i] < b[i - 1])
			{
				return false;
			}
			i++;
		}

		return true;

	}

	std::string mergeStrings(std::string s1, std::string s2) {
		int len1 = s1.length();
		int len2 = s2.length();
		int i1 = 0, i2 = 0, i3 = 0;
		std::string b = s1 + s2;
		while (s1[i1] || s2[i2])
		{
			if (i1 < len1 && i2 < len2)
			{
				if (s1[i1] < s2[i2])
					b[i3++] = s1[i1++];
				else
					b[i3++] = s2[i2++];
			}
			else {
				if (i1 < len1)
					b[i3++] = s1[i1++];
				else
					b[i3++] = s2[i2++];
			}
		}
		return b;
	}

	// product of digits - sum of digits
	vector<int> getDigits(long num)
	{
		vector<int> a;
		long p = 1, s = 0;
		long q = num;
		while (q > 0)
		{
			long x = q % 10;
			a.push_back(x);
			p *= x;
			s += x;
			q /= 10;
		}
		long ans = p - s;
		return a;
	}

	/*long processData(vector<int> a1)
	{
		long p = 1, sum = 0;
		int i = 0;
		while (i < a1.size())
		{
			p *= a1[i];
			sum += a1[i];
			i++;
		}
		return (p - sum);

	}*/
	// Conver to binary
	
		void bin(unsigned n)
		{
			if (n > 1)
				bin(n >> 1);

			printf("%d", n & 1);
		}
	
		vector<int>mergeSorted(vector<int> a, vector<int> b)
		{
			int len = a.size(), blen = b.size();
			vector<int> c;// ((len + blen), 0);
			int j = 0, i=0;
			for (int k = 0; k < (len+blen); )
			{
				int x = 0;
				if (i < len && j < blen) {
					if (a[i] != b[j])
					{
						x = a[i] < b[j] ? a[i++] : b[j++];
						
					}
					else
					{
						x = a[i];
						i++; j++; 
					}
					c.push_back(x);
					k++;
				}
				else
				{
					while (i < len && j >= blen)
					{
						c.push_back(a[i++]);
						k++;
					}
					while (i >= len && j < blen)
					{
						c.push_back(b[j++]);
						k++;
					}

				}
				
			}
			return c;
		}


	
	

	int getllap(vector<int> a)
	{
		int ans = 2;
		int n = a.size();
		if (n <= 2)
			return n;

		vector<int> llap(n, 2);

		sort(a.begin(), a.end());
		 
		for (int j = n - 2; j >= 0; j--)
		{
			int i = j - 1;
			int k = j + 1;
			while (i >= 0 && k < n)
			{
				if (a[i] + a[k] == 2 * a[j])
				{
					llap[j] = max(llap[k] + 1, llap[j]);
					ans = max(ans, llap[j]);
					i -= 1;
					k += 1;
				}
				else if (a[i] + a[k] < 2 * a[j])
					k += 1;
				else
					i -= 1;
			}
		}
		return ans;
	}

}


int main()
{
	
	int i = 0;

	//vector<int> input = getDigits(10223);
	//long ans = processData(input);
	//cout << ans;
	std::vector<int> a{ 0, 41, 8,16,294,32 };
	std::vector<int> a1{ 2,6, 109, 892, 206 };
	//std::vector<int> ans = mergeSorted(a, a1);
i=0;

	//append 2  vectors
	a.insert(a.end(), a1.begin(), a1.end());
	// append 2 vectors:
	int l = getllap(a);
	l;
	cout <<l << " ";
}