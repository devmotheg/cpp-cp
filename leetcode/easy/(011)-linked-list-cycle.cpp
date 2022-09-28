/* Solution #1 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* fast = head, *slow = head;
        
        while (fast) {
            slow = slow->next;
            fast = fast->next;
            if (fast) fast = fast->next;
            
            if (slow && fast && slow == fast) return true;
        }
        
        return false;
    }
};

/* Solution #2 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (not head) return false;
        
        ListNode* slow = head;
        ListNode* fast = head->next;
        
        while (slow not_eq fast) {
            if (not fast or not fast->next) return false;
            
            slow = slow->next;
            fast = fast->next->next;
        }
        
        return true;
    }
};

/* Solution #3 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        unordered_set<ListNode*> seen;
        
        while (head) {
            if (seen.find(head) != seen.end()) return true;
            
            seen.insert(head);
            
            head = head->next;
        }
        
        return false;
    }
};

/* Solution #4 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
    ListNode* reverse_linkedlist(ListNode* head) {
        ListNode* prev = nullptr, *follow = nullptr;
        
        while (head) {
            follow = head->next;
            head->next = prev;
            
            prev = head;
            head = follow;
        }
        
        return prev;
    }
    
public:
    bool hasCycle(ListNode *head) {
        return head && head->next && reverse_linkedlist(head) == head ? true : false;
    }
};
