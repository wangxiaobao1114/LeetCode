class Solution {
private:
    ListNode* reverseKelement(ListNode* head, int k) {
        ListNode* result = nullptr;
        for (int i = 0; i < k; ++i) {
            ListNode* temp = head -> next;
            head -> next = result;
            result = head;
            head = temp;
        }
        return result;
    }
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head == nullptr) {
            return head;
        }
        ListNode dummy(0);
        dummy.next = head;
        head = &dummy;
        
        ListNode* runner = head -> next;
        int flag = 1;
        for (int i = 0; i < k; ++i) {
            if (runner -> next != nullptr || (runner -> next == nullptr && k == i + 1) ) { //恰好k个到结尾情况没考虑， 例如[1,2] 2情况
                runner = runner -> next;
            }
            else {
                flag = 0;
                break;
            }
        }
        while (flag == 1) {
            ListNode* temp1 = head -> next;
            head -> next = reverseKelement(temp1, k);
            temp1 -> next = runner;
            head = temp1;
            for (int i = 0; i < k; ++i) {
                if (runner != nullptr && (runner -> next != nullptr || (runner -> next == nullptr && k == i + 1)) ) { //对应添加runner !=  nullptr
                    runner = runner -> next;
                }
                else {
                    flag = 0;
                    break;
                }
            }
        }
        return dummy.next;
    }
};