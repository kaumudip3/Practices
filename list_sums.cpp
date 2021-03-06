/**
* Definition for singly-linked list.*/
#include <iostream>
struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
	int getNumber(ListNode* l1, int *len)
	{
		ListNode* ptr1 = l1;
		int num1 = 0;
		int multiplier = 1;
		while (ptr1 != NULL)
		{
			num1 += multiplier * (ptr1->val);

			multiplier *= 10;
			ptr1 = ptr1->next;

		}
		*len = multiplier;
		return num1;
	}

	ListNode * addTwoNumbers(ListNode* l1, ListNode* l2) {
		ListNode* ptr1 = l1;
		ListNode*ptr2 = l2;
		int num1 = 0, num2 = 0;
		int multiplier = 1;
	
		int len1 = 0;
		int len2 = 0;
		num1 = getNumber(l1, &len1);
		num2 = getNumber(l2, &len2);
		int sum1 = num1 + num2;
		ListNode* newList = NULL;
		multiplier = (len1 > len2) ? len1:len2;
		if (sum1 / multiplier == 0)
		multiplier /= 10;
		ListNode* h = NULL;
		ListNode *ptr = NULL;
		ListNode *ptr12 = NULL;
		int start_m = 10;
		while (multiplier && sum1 != 0)
		{
			int r = sum1 % start_m;
			sum1 = sum1 / start_m;
			if (h == NULL) {
				h = new ListNode(r);
				
			}
			else
			{
				ptr = new ListNode(r);
				
				if (h->next == NULL)
				{
					h->next = ptr;
					
				}
				else {
					ptr12->next = ptr;
					
				}
				ptr12 = ptr;
			}
			multiplier /= 10;

		}
		return h;
	}
	ListNode * addTwoNumbers2(ListNode* l1, ListNode* l2) {
	int sum = 0;
	ListNode *ll = NULL;
	ListNode **node = &ll;
	while (l1 != NULL || l2 != NULL || sum>0)
	{
		//digit sums
		if (l1 != NULL)
		{
			sum += l1->val;
			l1 = l1->next;
		}
		if (l2 != NULL)
		{
			sum += l2->val;
			l2 = l2->next;
		}
		(*node) = new ListNode(sum % 10);
		sum /= 10;
		node = &((*node)->next);
	}
	return ll;
}
};
int main()
{
	std::cout << "Hello World!\n";
	ListNode *l1 = new ListNode(1);
	ListNode *l2 = new ListNode(3);
	l1->next = l2;
	ListNode *l3 = new ListNode(4);
	l2->next = l3;
	Solution s1;
	
	ListNode *r1 = s1.addTwoNumbers(l1, l2);

}