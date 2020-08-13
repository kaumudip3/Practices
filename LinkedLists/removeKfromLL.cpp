// Singly-linked lists are already defined with this interface:
// template<typename T>
// struct ListNode {
//   ListNode(const T &v) : value(v), next(nullptr) {}
//   T value;
//   ListNode *next;
// };
// Input:
// l: [3, 1, 2, 3, 4, 5]
// k: 3
// Expected Output:
// [1, 2, 4, 5]
//
// Input:
// l: [3, 2,3, 1, 2, 3, 4, 5]
// k: 3
// Expected Output:
// [2, 1, 2, 4, 5]
//
// Input:
// l: [3, 1, 2, 3, 4, 5,3,3,3,4]
// k: 3
// Expected Output:
// [1, 2, 4, 5,4]
//
//
ListNode<int> * removeKFromList(ListNode<int> * l, int k) {
    if(l == nullptr )
    {
        return NULL;
    }
ListNode<int>* ptr = l;
    
    ListNode<int>* preptr = ptr;

    
    while(ptr != nullptr)
    {
        if(ptr->value == k)
        {
            if(preptr == l){
            l = ptr->next;
            preptr = preptr->next;
            ptr = preptr;
            }
            else {  
            // do not lose the previous pointer here
               while(ptr->next && ptr->next->value==k) 
               {
                   ptr= ptr->next;
               }
                   preptr->next = ptr->next;
                   preptr = preptr->next;
                   ptr = preptr;
            }                                       
           
        }
        
           
       else {
           preptr = ptr;
       ptr = ptr->next;
       }
    }
    
    return l;
}
