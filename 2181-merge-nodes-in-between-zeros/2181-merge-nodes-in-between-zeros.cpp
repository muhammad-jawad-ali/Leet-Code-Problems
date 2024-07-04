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
    ListNode* mergeNodes(ListNode* head) {
        int sum=0;
        ListNode* h = new ListNode();
        ListNode* ans = h;
        
        head = head->next;
        while(head->next != NULL){
            sum += head->val;
            if(head->val == 0){                
                h->val = sum;
                h->next = new ListNode();
                h = h->next;
                sum = 0;
            }
            cout << head->val << "    , " << sum << endl;
            head = head->next;
        }
        h->val = sum;
        return ans;
    }
};