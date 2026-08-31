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
        int f=-1;
        int p=-1;
        int m=INT_MAX;
        int i=1;
        ListNode* prev=head;
        ListNode* curr=head->next;

        while(curr && curr->next){
            ListNode* next=curr->next;
            if(prev->val<curr->val && curr->val>next->val || prev->val>curr->val && curr->val<next->val){
                if(f==-1){
                    f=i;
                }
                else{
                    m=min(m,i-p);
                }
                p=i;
            }
            prev=curr;
            curr=next;
            i++;
        }
        int max=p-f;
        if(f==-1 || f==p){
            return {-1,-1};
        }else{
            return{m,max};
        }
    }
};