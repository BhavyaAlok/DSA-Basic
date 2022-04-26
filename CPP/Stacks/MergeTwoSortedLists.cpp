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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        
        
        ListNode* lo1 = list1;
        ListNode* lo2 = list2;
     
        ListNode* p = NULL;
        ListNode* temp = NULL;
        
        while(lo1 != NULL && lo2!= NULL)
        {
            if(lo1->val < lo2->val)
            {
                ListNode* x = new ListNode(lo1->val);
                if(p==NULL){p=x; temp =p;}
                else{
                    temp->next = x;
                     temp= temp->next;
                }
                lo1 = lo1->next;
            }
            else
            {
                ListNode* x = new ListNode(lo2->val);
                if(p==NULL){p=x; temp=p;}
                else{
                    temp->next = x;
                    temp= temp->next;
                }
                lo2=lo2->next; 
            }
            
             
        }
        while(lo1 != NULL)
        {
                 ListNode* x = new ListNode(lo1->val);
            if(p==NULL){p=x; temp=x;}
                else{
                    temp->next = x;
                     temp= temp->next;
                }
            lo1 = lo1->next; 
        }
        while(lo2 != NULL)
        {
            ListNode* x = new ListNode(lo2->val);
            if(p==NULL){p=x; temp=x;}
                else{
                    temp->next = x;
                     temp= temp->next;
                }
            lo2=lo2->next; 
        }
        
        
        return p;
    }
};
