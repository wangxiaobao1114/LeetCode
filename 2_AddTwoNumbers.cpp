class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode dummy(0);
        ListNode* result = & dummy;
        int carry = 0;
        while (l1 != nullptr || l2 != nullptr || carry == 1 ) {
            result -> next = new ListNode(0);
            result = result -> next;
            int tempVal = 0;
            if (l1 != nullptr) {
                tempVal += l1 -> val;
                l1 = l1 -> next;
            }
            if (l2 != nullptr) {
                tempVal += l2 -> val;
                l2 = l2 -> next;
            }
            if (carry == 1) {
                tempVal++;
            }
            //不用if判断
            result -> val = tempVal % 10;
            carry = tempVal / 10;
        }
        return dummy.next;
    }
};