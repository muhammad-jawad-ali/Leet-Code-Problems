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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        ListNode* h = head;
        int len=1;
        while(head->next != NULL){
            len++;
            head = head->next;
        }
 
        if(len < 3){
            return {-1,-1};
        }

        int mind= INT_MAX;
        int maxd= INT_MIN;
        head = h;
        vector<int> ans;


        for(int i=0;i<len-2;i++){
            int a = h->val;
            int b = h->next->val;
            int c = h->next->next->val;
            h = h->next;
            if(  (b>a && b>c) || (b<a && b<c)  ){
                if(ans.size() > 0)
                {
                    if(mind >  (i+2) - ans.back() )
                    {
                        mind = (i+2) - ans.back();
                    }
                }
                ans.push_back(i+2);
                cout << ans.back() << endl;
            }
        }
        if(ans.size() < 2){
            return {-1,-1};
        }
        
        sort(ans.begin(),ans.end());
        maxd = ans[ans.size()-1]- ans[0];



        return {mind,maxd};

    }
};