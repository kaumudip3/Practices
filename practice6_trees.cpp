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

	// product of digits - sum of digits
	vector<int> getDigits(long num)
	{
		vector<int> a;
		long q = num;
		while (q > 0)
		{
			a.push_back(q % 10);
			q /= 10;
		}
		return a;
	}

	long processData(vector<int> a1)
	{
		long p=1, sum=0;
		int i = 0;
		while (i < a1.size())
		{
			p *= a1[i];
			sum += a1[i];
			i++;
		}
		return (p - sum);
	}
	// Conver to binary
}



/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
   
public:
    vector<int> inorderTraversal(TreeNode* root) {
               // vector<int> list = new LinkedList<>();
        vector<int> list;
        helper(root, list);
        return list;
    }
    
 void helper(TreeNode root, vector<int> list){
        if(root != null){
            helper(root.left, list);
            list.push_back(root.val);
            helper(root.right, list);
        }
    
     
     vector<int>inorder_Morris{
         vector<int> result;
        /*if(root == NULL)
        {
            return;
        }
        inorderTraversal( root->left );
        result.push_back(root->val);
        inorderTraversal( root->right );
        */
        TreeNode *current, *pre; 
  
    //if (root == NULL) 
      //  return; 
  
    current = root; 
    while (current != NULL) { 
  
        if (current->left == NULL) { 
            result.push_back(current->val);
            current = current->right; 
        } 
        else { 
  
            /* Find the inorder predecessor of current */
            pre = current->left; 
            while (pre->right != NULL && pre->right != current) 
                pre = pre->right; 
  
            /* Make current as the right child of its inorder  
               predecessor */
            if (pre->right == NULL) { 
                pre->right = current; 
                current = current->left; 
            } 
  
            /* Revert the changes made in the 'if' part to restore  
               the original tree i.e., fix the right child 
               of predecessor */
            else { 
                pre->right = NULL; 
                 result.push_back(current->val);
                current = current->right; 
            } /* End of if condition pre->right == NULL */
        } /* End of if condition current->left == NULL*/
    } /* End of while */
        return result;
}
 };
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
	//std::string a1 = "abvc";
	//std::string a2 = "xyza";
	//std::string r = mergeStrings(a1, a2);
	vector<int> input = getDigits(123);
	long ans = processData(input);
	cout << ans;
}