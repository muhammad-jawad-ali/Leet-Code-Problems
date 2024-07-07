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
    ListNode* reverseList(ListNode* head) {
        if(head == NULL){
            return head;
        }
        int len=1;
        ListNode* h = head;


        while(head->next != NULL){
            len++;
            head = head->next;
        }
        head = h;


        ListNode **arr = new ListNode*[len];
        for(int i=len-1;i>=0;i--){
            arr[i] = head;
            head = head->next;
        }
        for(int i=0;i<len-1;i++){
            cout << arr[i]->val << endl;
            arr[i]->next = arr[i+1];
        }
        arr[len-1]->next = NULL;
        head = arr[0];

        delete [] arr;

        return head;
        
    }
};