/*
A linked list is given such that each node contains an additional random pointer which could point to any node in the list or null.

Return a deep copy of the list.
*/

class Solution{
public:
	RandomListNode* copyRandomList(RandomListNode* head){
		for(RandomListNode* cur = head;cur;){
			RandomListNode* node = new RandomListNode(cur->label);
			node->next = cur->next;
			cur->next =node;
			cur = cur->next->next;
		}
		for(RandomListNode* cur=head;cur;){
			if(cur->random!=nullptr){
				cur->next->random = cur->random->next;
			}
			cur = cur->next->next;
		}
		RandomListNode dummy(-1);
		for(RandomListNode* cur =head, *new_cur=&dummy;cur;){
			new_cur->next = cur->next;
			new_cur = new_cur->next;
			cur->next = cur->next->next;
			cur = cur->next;
		}
		return dummy.next;
	}
};