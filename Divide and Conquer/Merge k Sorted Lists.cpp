/*
Merge k sorted linked lists and return it as one sorted list. 
Analyze and describe its complexity.
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
     ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(!l1) return l2;
        if(!l2) return l1;
        ListNode dummy(-1);
        ListNode* p =&dummy;
        for(;l1!=nullptr&&l2!=nullptr;p=p->next){
            if(l1->val<l2->val){
                p->next = l1;
                l1 = l1->next;
            }
            else{
                p->next = l2;
                l2 = l2->next;
            }
        }
        
        p->next = l1==nullptr?l2:l1;
        return dummy.next;
    }
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0) return nullptr;
        if(lists.size()==1) return lists[0];
        if(lists.size()==2) return mergeTwoLists(lists[0],lists[1]);
        int len = lists.size();
        vector<ListNode*> sublist1(lists.begin(),lists.begin()+len/2);
        vector<ListNode*> sublist2(lists.begin()+len/2,lists.end());
        return mergeTwoLists(mergeKLists(sublist1), mergeKLists(sublist2));
    }
};