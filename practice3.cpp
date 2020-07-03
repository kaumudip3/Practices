/* Grouping Options
There are a number of people in a row.They must all be divided into a number of
contiguous groups from left to right.If each group must be at least as large
as the group to its left, determine how many distinct ways groups can be formed.
For a group to be distinct, it must differ in size for at least one group when
sorted ascending.For exmample, [1, 1, 1, 3] is distinct from[1, 1, 1, 2] but
not from[1, 3, 1, 1].

	Time complexity : O(mn)
	Space complexity : O(mn)
	Example 1 :
	Input :
	n = 8
	k = 4
	Output :
	5
	Explanation :
	[1, 1, 1, 5], [1, 1, 2, 4], [1, 1, 3, 3], [1, 2, 2, 3], [2, 2, 2, 2]
	"""
	*/
/*	*/

// Dynamic programming
// need a table 
#include <iostream>
#include<vector>
#include<stdlib.h>
#include<algorithm>
#include<map>
#include<string>
using namespace std;

int calculate(int pos, int prev,
	int left, int k)
{
	// Base Case 
	if (pos == k) {
		if (left == 0)
			return 1;
		else
			return 0;
	}

	// if N is divides completely 
	// into less than k groups 
	if (left == 0)
		return 0;

	int answer = 0;

	// put all possible values  
	// greater equal to prev 
	for (int i = prev; i <= left; i++) {
		cout << "calculate(pos + 1, i," << "left - i, k) " << pos << ","<<left << "= "<<answer<< endl;
		answer += calculate(pos + 1, i,
			left - i, k);
	}
	return answer;
}
int groupMembers(int n, int k)
{
	
	return calculate(0, 1, n, k);
}

class wordCount
{
private:
	std::map<string, int> mp;
public:
	void addword(string w)
	{
		mp[w]++;
	}
	void printData()
	{
		std::map<string, int>::iterator it;
		for (it = mp.begin(); it != mp.end(); it++)
			std::cout << it->first << "->" << it->second << endl;
	}
};
/*matrix_conversion
After a noval algorithm, the int 2D matrix can be converting into another int 2D
matrix. The algorithm is like that:
before_matrix = [[1, 2], [3, 4]]
after_matrix = before_matrix
for i in range(1, len(1)):
after_matrix[i][0] += after_matrix[i - 1][0]
for i in range(1, len(before_matrix[0])):
after_matrix[0][i] += after_matrix[0][i - 1]
for i in range(1, len(before_matrix)):
for j in range(1, len(before_matrix[0])):
after_matrix[i][j] += after_matrix[i][j - 1] + after_matrix[i - 1][j] - after_matrix[i - 1][j - 1]
The every element (x, y) in the new matrix is equale to the sum of previous row
and col. Now, given you a after_matrix, could you get back the before_matrix?

Time complexity:  O(mn)
Space complexity: O(mn)
Example 1:
Input:
[[1, 3],
[4, 10]]
Output:
[[1, 2],
[3, 4]]
Example 2:
Input:
[[1, 3, 6],
[5, 12, 21],
[12, 27, 45]]
Output:
[[1, 2, 3],
[4, 5, 6],
[7, 8, 9]]
"""*/
class Matrixdata
{
public:
	void printnewmatrix(int m, int n )
	{
		vector<vector<int>> res(m); int x = 0;
		for (int i = 0; i < m; i++)
		{
			res[i] = vector<int>(n, 0);
		}
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				cin >> x;
				res[i][j] = x;
			}
		}
		//reprocess

		for (int i = m - 1; i >0; i--)
		{
			for (int j = n - 1; j > 0; j--) {
				int temp = res[i - 1][j] + res[i][j - 1];
				res[i][j] -=temp;
				res[i][j] += (res[i - 1][j - 1]);
			}
		}
		for (int i = m-1; i >0; i--)
		{
			
			res[i][0] = res[i][0] - res[i - 1][0];
			//cout << i << "0" << res[i][0];
		}//cout << endl;	
		for (int i = n-1; i >0; i--)
		{
			res[0][i] = res[0][i] - res[0][i-1];
		}

		

		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++) {
				//int temp = res[i - 1][j] + res[i][j - 1] + res[i - 1][j - 1];
				cout<< res[i][j] <<" ";
			}
			cout << endl;
		}
	}
};

class loadbalancer
{
	/* Load Balance
	Given a int servers and a int array arrival time and int array work load time.
	Therefore, the finishing time is(arrival time + work load time).
	The servers take task in a robin round manner(plus if the server is still
	]working another task, then skip to next server util find the next avaible or
	wait unitil next avaible server).Simulate the servers handling tasks and
	find out which server has a heaviest work load. (Here, the work load is total
	assignied load on this server)

	Example 1:
	Input:
	servers = 2
	arrivals = [10, 7, 6, 20]
	loads = [60, 2, 1 100]*/
	/*
	Output:
	[1]
	Explanation:
	The first wrok is [6, 1] and finish at 7 using server 0.
	The second wrok is [7, 2] and finish at 9 using server 1.
	server 0 finish and add it into queue again.
	The third wrok is [10, 60] and finish at 70 using server 0.
	server 1 finish and add it into queue again.
	The last work is [20, 100] and finish at 120 using server 1.
	Total server 0 = 61, Total sever 1 = 102
	Example 2:
	Input:
	servers = 1
	arrivals = [10, 7, 6, 20]
	loads = [60, 2, 1000, 100]
	Output:
	[0]
	Explanation:
	Only one sever avalible and the left tasks need to wait for excution
	Example 3:
	Input:
	servers = 0
	arrivals = [10, 7, 6, 20]
	loads = [60, 2, 1000, 100]
	Output:
	[]
	Example 4:
	Input:
	servers = 3
	arrivals = [10, 7, 6, 20]
	loads = [1000, 1000, 1000, 1000]
	output:
	[0, 1, 2]
	Explanation:
	Each server has same heaviest work load, return the serve list with ascending order
	*/

public:
	int maxload(int server, vector<int>times, vector<int>val)
	{
		if (server == 0) return 0;
		vector<pair<int, int>> st(times.size(), { 0,0 });
		vector<int> maxserver(server,0);
		std::vector<pair<int, int>> ser(server, { 0,0 }); // 
		
		int res=0;
		for (int i = 0; i < times.size(); i++)
		{
			st.push_back({ times[i],val[i] });
		}
		sort(st.begin(), st.end());
		//cout << st[0].first << st[0].second;

		for (int i = 0; i < st.size(); i++)
		{
			int tt = st[i].first;
			int val = st[i].second;
			for (int j = 0; j < server; j++)
			{
				if (tt > ser[j].first) {
					cout << ser[j].first<<"-"<< maxserver[j]<<endl;
					ser[j].first += tt; //next available time
					maxserver[j] += val;
				}
				
			}
		}
		int maxx = 0; 
		for (int i = 0; i < maxserver.size(); i++)
		{
			if (maxserver[i] > maxx)
			{
				maxx = maxserver[i];
				res = i;
			}
		}

		return res+1;
	}
};

class CountHT
{
public:
	vector<int> getMaxStreaks(vector<string> toss) {
		// Return an array of two integers containing the maximum streak of heads and tails respectively
		vector<int> res(2, 0); // H H H T T T
		int hcnt = 0, tcnt = 0;
		int len = toss.size();
		for (size_t i = 0; i < toss.size(); i++)
		{
			int tmp = 0;
			while (i< len && toss[i] == "Heads" )
			{
				++tmp;
				++i;

			}
			if (tmp > hcnt)
				hcnt = tmp;
			tmp = 0;
			while (i< len && toss[i] == "Tails" )
			{
				tmp++;
				i++;
			}
			if (tmp > tcnt)
				tcnt = tmp;
		}
		res[0] = hcnt;
		res[1] = tcnt;

		return res;
	}

};



int main(int argc, char* argv[])
{
	/*std::vector<int> coordinates(2, 0);
	coordinates = gridproblem(3, 0, 0, "RDD");
	/*for (auto const& value : coordinates)
	{
	std::cout << value << " ";
	}
	coordinates = gridproblem(3, 1, 0, "LLUU");*/

	/* Enter your code here. Read input from STDIN. Print output to STDOUT */

	//	std::cout << groupMembers(8, 4);
	//getch();

	wordCount wc;
	string arr[7] = { "abc","abc","hello","jkl","lm","lm","lm" };
	for (int i = 1; i < argc; ++i)
	{
		wc.addword(argv[i]);
	}
	wc.printData();


	//Matrixdata mm;
	//mm.printnewmatrix(2,2);

	loadbalancer lb;
	std::vector<int> t = {10, 7, 6, 20
};
	std::vector<int> l = { 10, 2, 1, 100 };
	cout << lb.maxload(2, t, l);

	CountHT ct;
	vector<string> inp = { "Heads", "Heads" , "Heads" , "Heads" }; //{"Heads", "Tails", "Tails", "Tails", "Tails"};
	vector<int> ht(2, 0);
		ht = ct.getMaxStreaks(inp);
	cout << ht[0] << " " << ht[1];
	system("pause");


	return 0;
}
