/////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 19. Remove Nth Node From End of List - LeetCode

/*
Given the head of a linked list, remove the nth node from the end of the list and return its head.
Example 1:
I : head = [1,2,3,4,5], n = 2
O : [1,2,3,5]

Example 2:
I : head = [1], n = 1
Output: []

Example 3:
I : head = [1,2], n = 1
Output: [1]
*/
///////////////////////////////////////////////////////////////////////////////////////////////////////////

/* 
Approach :

    1. Take 2 pointers. f = head+k, s= head
    2. Move both pointers by 1 step each. 
       When F reaches end of list s reaches the parent of kth node from end.
    3. Delete kth node from end. 
*/

////////////////////////////////////////////////////////////////////////////////////////////////////////////
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
        ListNode* f = head, *s = head;
               
        while(n--) f= f->next;  // Reach the nth node.
        if(!f){
            head = head->next;      //It means we have to delete 1st node
            delete s;               //Delete pointer and free the memory pointed by it.
            return head;
        }
        while(f->next){
            s = s->next; 
            f = f->next;
        }
        auto temp = s->next;        // copy the address of node pointed by target node
        s->next = s->next->next;    // parent of target now points to the node after target node
        delete temp;                // Delete kth node and free memory allocated to it.
        return head;
    }
};