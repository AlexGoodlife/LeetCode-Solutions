/*
Given the head of a linked list, remove the nth node from the end of the list and return its head.

Runtime: 4ms | beats 50 % of other submissions
Memory Usage: 6 MB

*/


#include <stdio.h>
#include <stdlib.h>


struct ListNode {
    int val;
    struct ListNode *next;
};


struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
    struct ListNode* fast = head;
    struct ListNode* slow = head;
    struct ListNode* prev = slow;
    int count = 1;
    if(head->next == NULL)
        return NULL;
    while(fast->next != NULL){
        fast = fast->next;
        if(count >= n){
            prev = slow;
            slow = slow->next;
        }
        count++;
    }
    if(prev == slow){
        head = head->next;
    }
    else{
        prev->next = slow->next == NULL ? NULL : slow->next;
        free(slow);
    }
    return head;
}



int main(void){
    return 0;
}