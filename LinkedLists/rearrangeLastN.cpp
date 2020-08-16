// Given a singly linked list of integers l and a non-negative integer n, move the last n list nodes to the beginning of the linked list.
//  0<n<= list.len 
// Example
 // For l = [1, 2, 3, 4, 5] and n = 3, the output should be
// rearrangeLastN(l, n) = [3, 4, 5, 1, 2];
// For l = [1, 2, 3, 4, 5, 6, 7] and n = 1, the output should be
// rearrangeLastN(l, n) = [7, 1, 2, 3, 4, 5, 6].

// Singly-linked lists are already defined with this interface:
// template<typename T>
// struct ListNode {
//   ListNode(const T &v) : value(v), next(nullptr) {}
//   T value;
//   ListNode *next;
// };
//
ListNode<int> * rearrangeLastN(ListNode<int> * l, int n) {

// approach 1 : Calculate len of list
// prev pointer
// reattach
/*ListNode<int> *ptr = l, *fast=nullptr, *slow=nullptr;
if(n==0 || l == nullptr)
return l;

int len =0;
while(ptr)
{
    ptr = ptr->next;
    len++;
}
if(n == len) return l;

ptr = l;
for(int i=0;i<len-n;i++)
{
    slow = ptr; //prev
    ptr = ptr->next;
    
}
fast = ptr; cout << fast->value;

while(ptr->next) ptr = ptr->next;
cout << ptr->value;
ptr->next = l;// jpin the start
slow->next = nullptr;cout << slow->value;

return fast;
*/
//Approach 2*
    ListNode<int>* trailer = l;
    ListNode<int>* ptr = l;
    // traverse first n
    for(int i = 0; i < n; i++){
        ptr = ptr->next;
    }
    
    if(n == 0 || ptr == NULL)
        return l;
        
    // trailer = len-n
    // i.e. end of list and start at next
    while(ptr->next){
        ptr = ptr->next;
        trailer = trailer->next;
    }
    ListNode<int>* result = trailer->next;
    trailer->next = NULL;
    ptr->next = l;
    return result;

}
