/*
You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. 
Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Runtime 32 ms | beats 11.66 % of other submissions
Memory usage 7.8 MB | beats 46.30 % of other submissions

*/

#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};


struct ListNode* append(int x, struct ListNode* s)
{
  struct ListNode * r = (struct ListNode*) malloc(sizeof(struct ListNode));
  r -> val = x;
  r -> next = s;
  return r;
}

struct ListNode* reverseList(struct ListNode* head)
{
    struct ListNode* prev = NULL;
    struct ListNode* current = head;
    struct ListNode* next;
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    return prev;
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    struct ListNode * r;
    int carry= 0;
    int put = 0;
    while(l1 != NULL || l2 != NULL){
        int first = (l1 != NULL) ? l1->val : 0;
        int second = (l2 != NULL) ? l2->val : 0;
        put = first + second + carry;
        carry = put / 10;
        r =append(put % 10, r);
        if(l1 != NULL)
            l1 = l1->next;
        if(l2 != NULL)
            l2 = l2->next;
    }
    if(carry > 0){
        r =append(carry, r);
    }
    struct listNode * result = reverseList(r);
    return result;
}

int main(void){
    return 0;
}