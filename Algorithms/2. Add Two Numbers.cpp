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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        vector<int> resVec;
        int result=0;
        int carry=0;
        while (!(l1 == NULL&&l2 == NULL)) {
            if (l1 == NULL) {
                result = l2->val+carry;
                carry = result / 10;
                result %= 10;
                resVec.push_back(result);
                l2 = l2->next;
                continue;
            }
            if (l2 == NULL) {
                result = l1->val + carry;
                carry = result / 10;
                result %= 10;
                resVec.push_back(result);
                l1 = l1->next;
                continue;
            }
            if (l1 != NULL&&l2 != NULL) {
                result = l1->val + l2->val+carry;
                carry = result / 10;
                result %= 10;
                resVec.push_back(result);
                l1 = l1->next;
                l2 = l2->next;
            }
            
        }
        if (carry != 0) {
            resVec.push_back(carry);
        }
        ListNode* r = new ListNode(0);
        ListNode *k = r;
        for (int i = 0; i < resVec.size(); i++) {
            r->next = new ListNode(resVec[i]);
            r = r->next;
        }
        k = k->next;
        return k;
    }
};

//更简洁优雅的代码，来自评论区
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = new ListNode(0);
        ListNode* cur = head;
        int plus = 0;
        while (l1 || l2) {
            int num = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + plus;
            if (num >= 10) {
                num -= 10;
                plus = 1;
            } else plus = 0;
            cur->next = new ListNode(num);
            cur = cur->next;
            if (l1) l1 = l1->next;
            if (l2) l2 = l2->next;
        }
        if (plus) cur->next = new ListNode(1);
        return head->next;
    }
};