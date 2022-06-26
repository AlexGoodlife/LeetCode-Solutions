/*
Given the head of a singly linked list, return the middle node of the linked list.

If there are two middle nodes, return the second middle node.

Runtime: 0ms | beats 100% of other submissions
Memory Usage: 6.1 MB
*/


#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};


struct ListNode* middleNode(struct ListNode* head){
    struct ListNode* fast = head;
    struct ListNode * slow = head;
    while(fast != NULL && fast->next != NULL){
        fast = fast->next->next;
        slow = slow->next;
        }
    return slow;
}


int main(void){
    return 0;
}