#include <iostream>
#include<vector>
#include<stdlib.h>
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

		/* i = 0;
		while( i < len-1 )
		{
		if(b[i] > b[i+1])
		{
		return false;
		}
		i++;
		}*/
		return true;

	}

	std::string mergeStrings(std::string s1, std::string s2) {
		int len1 = s1.length();
		int len2 = s2.length();
		int i1 = 0, i2 = 0, i3 = 0;
		std::string b = s1+s2;
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

}

int main()
{
	std::vector<int> a(10, 0);
	int i = 0;
	//std::vector<int> a1{-52, 2, 31, 56, 47, 29, -35 };
	while (i < 10)
	{
		a.push_back(i + 2);
		i++;
	}
	//bool t = alternatingSort(a1);
	//t;
	std::string a1 = "abvc";
	std::string a2 = "xyza";
	std::string r = mergeStrings(a1, a2);

}