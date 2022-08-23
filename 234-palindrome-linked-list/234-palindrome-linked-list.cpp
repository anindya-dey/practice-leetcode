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
private:
    bool checkPalindrome(vector<int> &arr) {
        int l = 0, r = arr.size() - 1;
        
        while(l < r) {
            if(arr[l] != arr[r]) return false;
            l++;
            r--;
        }
        
        return true;
    }
public:
    bool isPalindrome(ListNode* head) {
        vector<int> values;
        
        ListNode *curr = head;
        
        while(curr) {
            values.push_back(curr->val);
            curr = curr->next;
        }
        
        return checkPalindrome(values);
    }
};