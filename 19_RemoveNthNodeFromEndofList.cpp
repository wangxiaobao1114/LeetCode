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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode dummy(0);
        dummy.next = head;
        head = &dummy;
        ListNode* chaser = head;
        ListNode* runner = head;
        for (int i = 0; i < n; ++i) {
            runner = runner -> next;
        }
        while (runner -> next != nullptr) {
            runner = runner -> next;
            chaser = chaser -> next;
        }
        ListNode* temp = chaser -> next;
        chaser -> next = chaser -> next -> next;
        delete temp;
        return dummy.next;
    }
};