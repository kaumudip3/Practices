//You're given 2 huge integers represented by linked lists. Each linked list element is a number from 0 to 9999
// that represents a number with exactly 4 digits. The represented number might have leading zeros. Your task is
// to add up these huge integers and return the result in the same format.

//Example
// For a = [9876, 5432, 1999] and b = [1, 8001], the output should be
// addTwoHugeNumbers(a, b) = [9876, 5434, 0].
// Explanation: 987654321999 + 18001 = 987654340000.

//For a = [123, 4, 5] and b = [100, 100, 100], the output should be
// addTwoHugeNumbers(a, b) = [223, 104, 105].
// Explanation: 12300040005 + 10001000100 = 22301040105.


/**
* Definition for singly-linked list.*/
#include <iostream>
#include<map>
#include<algorithm>
#include<vector>
using namespace std;

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };




std::vector<long> getNum(ListNode* l)
{
	vector<long> res;
	while (l)
	{
		res.push_back(l->val);
		l = l->next;
	}
	// reverse vec
	int ll = res.size();
	for (int i = 0; i<ll / 2; i++)
	{
		swap(res[i], res[ll - i - 1]);
		cout << res[i] << " ";
	}
	return res;
}
ListNode* addTwoHugeNumbers(ListNode * a, ListNode * b) {
	vector<long> num1;
	vector<long> num2;
	ListNode* res = nullptr, *ptr=nullptr;
	num1 = getNum(a); cout << "\n";
	num2 = getNum(b);
	long a1 = 0, b1 = 0, carry = 0;
	int maxlen = num1.size() > num2.size() ? num1.size() : num2.size();

	for (int i = 0; i<maxlen; i++)
	{
		a1 = (i < (int)num1.size()) ? num1[i] : 0;
		b1 = (i < (int)num2.size()) ? num2[i] : 0;
		long sum1 = a1 + b1 + carry;
		carry = sum1 / 10000;
		ListNode *temp = new ListNode(sum1 % 10000);
		cout << sum1 << " " << carry << "=  " << temp->val;
		if (!res)
			res = ptr = temp;
		else {
			temp->next = ptr;
			ptr = temp;
		}

	}
	if (carry >0)
	{
		ListNode *temp = new ListNode(carry);
		temp->next = ptr;
		ptr = temp;

	}
	res = ptr;
	return res;


}

	int main()
{
	std::cout << "Hello World!\n";
	ListNode *l1 = new ListNode(1);
	ListNode *l2 = new ListNode(3);
	l1->next = l2;
  
  ListNode *l11 = new ListNode(5);
  
  	ListNode *l133 = addTwoHugeNumbers(l1, l11);
	
	return 0;
}
