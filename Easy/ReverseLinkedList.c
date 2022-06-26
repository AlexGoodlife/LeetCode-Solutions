/*
Given the head of a singly linked list, reverse the list, and return the reversed list.

Runtime: 0 ms Iterative, 3 ms Recursive | beats 100% of other submissions
Memory Usage: 6.5 MB both
*/


#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

// ITERATIVE
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

//RECURSIVE 
struct ListNode* put(int x, struct ListNode* s){
    struct ListNode* r = (struct ListNode*) malloc(sizeof(struct ListNode));
    r->val = x;
    r->next = s;
    return r;
}

struct ListNode* calc(struct ListNode* head,struct ListNode* result){
    return head->next == NULL ? put(head->val, result) : calc(head->next, put(head->val, result));
}

struct ListNode* reverseListRec(struct ListNode* head){
    return head ==NULL ? head : calc(head, NULL);
}


int main(void){
    return 0;
}