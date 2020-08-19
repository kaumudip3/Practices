
// val: an integer representing Node.val
// random_index: the index of the node (range from 0 to n-1) where random pointer points to, or null if it does not point to any node.

// head = [[3,null]]
// head = [[1,0]]

// Input: head = [[7,null],[13,0],[11,4],[10,2],[1,0]]
// Output: [[7,null],[13,0],[11,4],[10,2],[1,0]]
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == NULL)
            return nullptr;
        map<Node*, Node*>oldtonew;
        Node*ptr = head, *res = nullptr, *ptr2 = nullptr;
        
        while(ptr)
        {
            Node *temp = new Node(ptr->val);
            oldtonew[ptr] = temp;
            if(res == nullptr) {
                res = ptr2 = temp;
            }
            else{
            ptr2->next=temp;
            ptr2 = temp;
            }
            
            ptr=ptr->next;
            cout << temp->val;
        }
        cout << "here 1";
        //if(oldtonew.size() == 1) return res;
        ptr = head;
        while(ptr)
        {
             cout << "here 2";
            Node*random = ptr->random;
            Node* newNode = oldtonew[ptr];
            
            if(random == nullptr) newNode->random = nullptr;
            
            newNode->random = oldtonew[random];
            ptr=ptr->next;
        }
 return res;    
    }
};
