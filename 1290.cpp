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
    int getDecimalValue(ListNode* head) {
        ListNode *curr=head;
        ListNode *prev=nullptr;
        while(curr)
        {
            ListNode *nextnode=curr->next;
            curr->next=prev;
            prev=curr;
            if(!nextnode) break;
            curr=nextnode;
        }
        int power=0;
        int ans=0;
        while(curr)
        {
            if(curr->val==1)
            {
                ans+=1<<power;
            }
            power++;
            curr=curr->next;
        }
        return ans;
    }
};
