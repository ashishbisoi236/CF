// Brief Explanation

// Return if list is empty or singleton or if k is 0.
// Compute the size of the list.
// Link the last node of the list with head. (A circular list is created)
// If k is greater than size of the list, take modulus. k = k % size
// Find the position (pi) from where to break the circle. size - k % size
// Mark next element (pi+1) the new head.
// Break the circle!

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next || !k) return head;
        
        auto temp = head;
        
        // Compute the size of the linked list.
        int size = 1;
        while (temp->next) {
            temp = temp->next;
            ++size;
        }
        
        // Circular linked list is created.
        temp->next = head;
        
        // If k is greater than size of the linked list then take modulus.
        k %= size;
        
        // Find the last node in the list after k rotations.
        while(--size >= k) {
            temp = temp->next;
        }
        
        // Make the next of last the new head.
        head = temp->next;
        
        // Break the circle.
        temp->next = nullptr;
        
        return head;
    }
};

// My solution

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL)
            return head;
        vector<int> v;
        ListNode* temp = head;
        while(temp != NULL) {
            v.push_back(temp->val);
            temp = temp->next;
        }
        k = k % v.size();
        temp = head;
        int len = v.size();
        for(int i = 0; i < len; i++) {
            temp->val = v[(len - k + i) % len];
            temp = temp->next;
        }
        return head;
    }
};