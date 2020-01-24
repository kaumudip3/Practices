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


	

	vector<int> getborder(int mat[][4], int m, int n, int border)
	{
		vector<int> c;
		int imin = 0 + border;
		int imax = m - border-1;

		for (int i = imin; i <= imax; i++)
		{
			for (int j = imin; j <= imax; j++)
			{
				if (i == imin || j == imin || j == imax || i == imax )
				{
					c.push_back(mat[i][j]);
				}
			}
		}
		return c;
	}
}


int main()
{
	//std::vector<int> a(10, 0);
	int i = 0;
	//std::vector<int> a1{-52, 2, 31, 56, 47, 29, -35 };
	/*while (i < 10)
	{
		a.push_back(i + 2);
		i++;
	}*/
	//bool t = alternatingSort(a1);
	//t;
	//std::string a1 = "abvc";
	//std::string a2 = "xyza";
	//std::string r = mergeStrings(a1, a2);
	vector<int> input = getDigits(10223);
	//long ans = processData(input);
	//cout << ans;
	std::vector<int> a{ 0, 41, 8,16,294,32 };
	std::vector<int> a1{ 2,6, 109, 892, 206 };
	//std::vector<int> ans = mergeSorted(a, a1);
	i = 0;
	//while (i < ans.size())
	//{
//		cout << ans[i++]<< " ";
//	}
//	int l = getMaxAPlen(ans);
	//l;

	//append 2  vectors
	a.insert(a.end(), a1.begin(), a1.end());
	// append 2 vectors:
	int l = getllap(a);
	l;
	cout <<l << " ";

	// Matrix sort
	const int nn = 4, mm = 4;
	int mat1[mm][nn] = {
		{3,2,4,55},
		{6,7,4,2},
	{3,5,2,1},
	{1,2,3,4}
	};
	std::vector<int> ans = getborder(mat1, 4, 4, 0);
	i = 0;
	while (i < ans.size())
	{
			cout << ans[i++]<< " ";
		}
	sort(ans.begin(), ans.end());
	//rewrite]
	int k = 0;
	for (int i = 0; i < mm; i++)
	{
		for (int j = 0; j < nn; j++)
		{
			if (i == 0 || j == 0 || j == nn - 1 || i == mm - 1)
			{
				mat1[i][j] = ans[k++];
			}
		}
	}
	cout << mat1[0][0] << " ";
	/*std::vector<int> ans1;
	for (int i = 1; i < mm-1; i++)
	{
		for (int j = 1; j < nn-1; j++)
		{
			if (i == 0+1 || j == 0+1 || j == nn-2 || i == mm -2)
			{
				ans1.push_back(mat1[i][j]);
			}
		}
	}
	i = 0;
	while (i < ans1.size())
	{
		cout << ans1[i++] << " ";
	}*/

	std::vector<int> ans0 = getborder(mat1, 4, 4, 0);
	std::vector<int> ans1 = getborder(mat1, 4, 4, 1);
	//std::vector<int> ans = getborder(mat1, 4, 4);

	while (i < ans0.size())
	{
		cout << ans0[i++] << " ";
	}
	cout << endl;
	while (i < ans1.size())
	{
		cout << ans1[i++] << " ";
	}
	cout << endl;
}