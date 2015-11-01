/*
Sort a Linked list using insertion sort.
*/

class Solution{
public:
    ListNode* insertionSortList(ListNode* head) {
    	ListNode* dummy(-1);
    	ListNode* pre= &dummy;
    	pre->next = head;
    	ListNode* cur = head;
    	while(cur){
    		if(cur->next&cur->next->val<cur->val){
    			while(pre->next&&pre->next->val<cur->next->val) pre = pre->next;
    			ListNode* temp= pre->next;
    			pre->next = cur->next;
    			cur->next = cur->next->next;
    			pre->next->next = temp;
    			pre = &dummy;
    		}
    		else cur = cur->next;
    	}
    	return dummy.next;
    }
};