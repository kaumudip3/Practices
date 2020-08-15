// Singly-linked lists are already defined with this interface:
// template<typename T>
// struct ListNode {
//   ListNode(const T &v) : value(v), next(nullptr) {}
//   T value;
//   ListNode *next;
// };
//
ListNode<int> * reverseNodesInKGroups(ListNode<int> * l, int k) {
    ListNode<int> *head = l;
    if (head == NULL) 
        return head; 
  
    // Create deque to store the address 
    // of the nodes of the linked list 
    deque<ListNode<int> *> q; 
  
    // Store head pointer in current to 
    // traverse the linked list 
    ListNode<int> * current = head; 
    int i; 
  
    // Iterate through the entire linked 
    // list by moving the current 
    while (current != NULL) { 
        i = 1; 
  
        // Store addresses of the k 
        // nodes in the deque 
        while (i <= k) { 
            if (current == NULL) {
                if(i<=k){
                q.clear();
                }
                break; 
                
            }
            q.push_back(current); 
            current = current->next; 
            i++; 
        } 
  
        /* pop first and the last value from  
        the deque and swap the data values at  
        those addresses 
        Do this till there exist an address in  
        the deque or deque is not empty*/
        while (!q.empty()) { 
            ListNode<int> * front = q.front(); 
            ListNode<int> * last = q.back(); 
            swap(front->value, last->value); 
  
            // pop from the front if 
            // the deque is not empty 
            if (!q.empty()) 
                q.pop_front(); 
  
            // pop from the back if 
            // the deque is not empty 
            if (!q.empty()) 
                q.pop_back(); 
        } 
    } 
    return head; 
}
