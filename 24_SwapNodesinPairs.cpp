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
    ListNode* swapPairs(ListNode* head) {
        ListNode dummy(0);
        dummy.next = head;
        head = &dummy;
        while (head -> next != nullptr && head -> next -> next != nullptr) {
            ListNode* temp1 = head -> next;
            head -> next = head -> next -> next;
            ListNode* temp2 = head -> next -> next;
            head -> next -> next = temp1;
            temp1 -> next = temp2;
            head = head -> next -> next;
        }
        return dummy.next;
    }
};