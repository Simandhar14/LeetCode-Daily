//brute force

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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        ListNode *dummy=new ListNode(0);
        dummy->next=head;
        for(int &num:nums)
        {
            ListNode *curr=dummy->next;
            ListNode *temp=new ListNode(0);
            ListNode *newhead=temp;
            while(curr)
            {
                if(curr->val!=num)
                {
                    temp->next=curr;
                    temp=temp->next;
                }
                curr=curr->next;
            }
            temp->next=nullptr;
            dummy->next=newhead->next;
        }
        return dummy->next;
    }
};

//better approach
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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int> values(begin(nums), end(nums));
        ListNode* dummy = new ListNode(0);
        ListNode* curr = head;
        ListNode* temp = dummy;
        while (curr) {
            if (!values.count(curr->val)) {
                temp->next = curr;
                temp = temp->next;
            }
            curr = curr->next;
        }
        temp->next = nullptr;
        return dummy->next;
    }
};
