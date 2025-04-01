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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* newHead = new ListNode(-200);
        ListNode* tail = newHead;
        ListNode* temp = head;
        while (temp) {
            if (temp->next) {
                if (temp->val == temp->next->val) {
                    int value = temp->val;
                    tail->next=temp;
                    tail=temp;
                    temp=temp->next;
                    while (temp && temp->val == value)
                        temp = temp->next;
                } else {
                    tail->next = temp;
                    tail = temp;
                    temp = temp->next;
                }
            } else {
                tail->next = temp;
                tail = temp;
                temp = temp->next;
            }
        }
        tail->next = NULL;
        return newHead->next;
    }
};