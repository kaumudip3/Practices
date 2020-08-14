//Reverse a singly linked list.

//Example:
//Input: 1->2->3->4->5->NULL
//Output: 5->4->3->2->1->NULL

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
     // in place iterative
        if (head == NULL) return head;
        ListNode *ptr, *cur, *after;
        ptr = head;
        cur = head->next;
        ptr->next = NULL;
        while (cur != NULL) {
            after = cur->next;
            cur->next = ptr;
            ptr = cur;
            cur = after;
        }
        
        return ptr;
        
        /* Approach 2
        ListNode *res=nullptr;
        ListNode *temp=nullptr, *ptr= head, *nxt=nullptr;
        
        while(ptr!= nullptr)
        {
            temp = new ListNode(ptr->val);
            if(ptr->next ){
                if( nxt == nullptr){
                nxt = new ListNode(ptr->next->val);
                nxt->next = temp;
                ptr = ptr->next;
                    res = nxt; // if only 1 node exists
                }
                else{
                    temp->next = nxt;
                    nxt = temp;
                }
                
            }
            else{
                res = temp;
                temp->next = nxt;
                return res;
            }
           
            ptr = ptr->next;
        }
      
        return res;*/
    }
};
