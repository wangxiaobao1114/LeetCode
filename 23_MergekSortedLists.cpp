//Solution1
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
private:
     ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode dummy(0);
        ListNode* head = &dummy;
        while (l1 != nullptr && l2 != nullptr) {
            if (l1 -> val < l2 -> val) {
                head -> next = l1;
                l1 = l1 -> next;
            }
            else {
                head -> next = l2;
                l2 = l2 -> next;
            }
            head = head -> next;
        }
        if (l1 != nullptr) {
            head -> next = l1;
        }
        if (l2 != nullptr) {
            head -> next = l2;
        }
        return dummy.next;
    }
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.size() == 0) {
            return nullptr;
        }
        ListNode dummy(0);
        ListNode* head = &dummy;
        head -> next = lists[0];
        for (int i = 1; i < lists.size(); ++i) {
            head -> next = mergeTwoLists(head->next, lists[i]);
        }
        return dummy.next;
        
    }
};

//Solution2
class Solution {
private:
    struct cmp{
      bool operator() (ListNode* l1, ListNode* l2) {  //why?!
          return l1 -> val > l2 -> val;
      }  
    };  
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode dummy(0);
        ListNode* head = &dummy;
        priority_queue<ListNode*, vector<ListNode*>, cmp> que;
        for (int i = 0; i < lists.size(); ++i) {
            if (lists[i] != nullptr) {
                que.push(lists[i]);
            }
        }
        while (!que.empty()) {
            ListNode* temp = que.top();
            head -> next = temp;
            head = head -> next;
            que.pop();
            if (temp -> next != nullptr) {
                que.push(temp->next);
            }
        }
        return dummy.next;
    }    
};