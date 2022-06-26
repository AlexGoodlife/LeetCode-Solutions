/*
Given the head of a singly linked list, return true if it is a palindrome.

Runtime: 145ms | beats 98% of other submissions
Memory Usage: 41.6 MB | beats 66% of other submissions
*/



#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct ListNode {
    int val;
    struct ListNode *next;
};


bool is_equal(struct ListNode*first, struct ListNode*second){
    while(first!= NULL){
        if(first->val != second->val)
            return false;
        first = first->next;
        second = second->next;
    }
    return true;
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


bool isPalindrome(struct ListNode* head){
    struct ListNode* fast = head;
    struct ListNode * slow = head;
    struct ListNode * slow_prev;
    while(fast != NULL && fast->next != NULL){
        fast = fast->next->next;
        slow = slow->next;
        }
    struct ListNode* reversed = reverseList(slow);
    return is_equal(reversed, head);

}

int main(void){
    return 0;
}