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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *slow, *fast;
        slow = fast = head;
        
        for(int i = 0; i < n; i++) {
            fast = fast->next;
        }
        
        if(!fast) {
            ListNode *nodeToDelete = head;
            head = head->next;
            nodeToDelete->next = nullptr;
            delete nodeToDelete;
            return head;
        }
        
        while(fast->next) {
            slow = slow->next;
            fast = fast->next;
        }
        
        ListNode *nodeToDelete = slow->next;
        slow->next = slow->next->next;
        nodeToDelete->next = nullptr;
        delete nodeToDelete;
        
        return head;
    }
};