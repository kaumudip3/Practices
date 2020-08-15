// Singly-linked lists are already defined with this interface:
// template<typename T>
// struct ListNode {
//   ListNode(const T &v) : value(v), next(nullptr) {}
//   T value;
//   ListNode *next;
// };
//
ListNode<int> * mergeTwoLinkedLists(ListNode<int> * l1, ListNode<int> * l2) {
ListNode<int>* ptr1=l1, *ptr2=l2, *res=nullptr, *ptr3=nullptr;
if(!ptr1) return l2;
if(!ptr2) return l1;
while(ptr1 && ptr2)
{
    if(ptr1->value < ptr2->value){
        if(!res) res = ptr3 = ptr1;
        else {
        ptr3->next =ptr1;
        ptr3 = ptr1;
        }
    
        ptr1 = ptr1->next;
    }
    else{
    if(ptr2->value < ptr1->value){
        if(!res) res = ptr3 = ptr2;
        else {
        ptr3->next =ptr2;
        ptr3 = ptr2;
        }
        ptr2 = ptr2->next;
    }
    else
    {
        //duplicate
        if(!res) {res = ptr3 = ptr2;
        }
        else{ptr3->next = ptr2;
        ptr3 = ptr3->next ;}
        ptr2 = ptr2->next;
        ptr3->next = ptr1;
        ptr1 = ptr1->next;
        ptr3 = ptr3->next; 
    }
    }//else
    
   
    
}

 // if 1 list is read
    if(ptr1)
    ptr3->next = ptr1;
    else {
    ptr3->next = ptr2;
    
    }
return res;

}
