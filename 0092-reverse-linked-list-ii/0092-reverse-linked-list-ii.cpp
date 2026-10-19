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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(head==nullptr || left==right)
        {
            return head;
        }

        ListNode* dummy=new ListNode(0);
        dummy->next=head;

        ListNode* before= dummy;

        for(int i=1;i<left;i++)
        {
            before=before->next;
        }

        ListNode* curr= before->next;

        for(int i=0;i<right-left;i++)
        {
            ListNode* nextNode=curr->next;
            curr->next=nextNode->next;
            nextNode->next=before->next;
            before->next=nextNode;
        }

        return dummy->next;
        
    }
};