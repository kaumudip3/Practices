  ListNode* reverse(ListNode* node) 
    { 
        if (node == NULL) 
            return NULL; 
        if (node->next == NULL) { 
            head = node; 
            return node; 
        } 
        ListNode* node1 = reverse(node->next); 
        node1->next = node; 
        node->next = NULL; 
        return node; 
    } 
