// Singly-linked lists are already defined with this interface:
// template<typename T>
// struct ListNode {
//   ListNode(const T &v) : value(v), next(nullptr) {}
//   T value;
//   ListNode *next;
// };
//
bool isListPalindrome(ListNode<int> * l) {
// stack approach
// O(n) 
    stack<int> ss;
    ListNode<int> * ptr = l;
    while(ptr)
    {
        ss.push(ptr->value);
        ptr = ptr->next;
    }
    ptr = l;
    while(!ss.empty())
    {
        if(ptr->value == ss.top())
        {
            ss.pop();
            ptr = ptr->next;
        }
        else {
        return false;
        }
    }
    return true;
}

//METHOD 2 (By reversing the list)
//This method takes O(n) time and O(1) extra space.
//1) Get the middle of the linked list.
//2) Reverse the second half of the linked list.
//3) Check if the first half and second half are identical.
//4) Construct the original linked list by reversing the second half again and attaching it back to the first half
