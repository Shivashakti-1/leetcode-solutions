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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* p = new ListNode(0);
        p->next=head;

        ListNode* l=p;
        ListNode* r = p;

        for(int i=0;i<n;i++)
        {
            r=r->next;
        }

        while(r->next!=nullptr)
        {
            l=l->next;
            r=r->next;
        }
        l->next=l->next->next;

        return p->next;
        
    }
};