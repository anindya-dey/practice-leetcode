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
    ListNode* deleteMiddle(ListNode* head) {
        ListNode *prev, *slow, *fast;
        slow = fast = head;
        prev = nullptr;
        
        while(fast && fast->next) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        
        if(prev) {
            ListNode *nodeToDel = slow;
            prev->next = slow->next;
            nodeToDel = nullptr;
            delete nodeToDel;
        } else {
            ListNode *nodeToDel = head;
            head = head->next;
            nodeToDel = nullptr;
            delete nodeToDel;
        }
        
        return head;
    }
};