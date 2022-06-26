/*
You are given the heads of two sorted linked lists list1 and list2.

Merge the two lists in a one sorted list. The list should be made by splicing together the nodes of the first two lists.

Return the head of the merged linked list.

Runtime: 0ms | beats 100% of other submissions
Memory Usage: 6MB | beats 69% of other submissions
*/


#include <stdio.h>
#include <stdlib.h>


struct ListNode {
    int val;
    struct ListNode *next;
 };

struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2){
    if(!list1)
        return list2;
    if(!list2)
        return list1;
    if(list1->val < list2->val){
        list1->next = mergeTwoLists(list1->next, list2);
        return list1;
    }
    else{
        list2->next= mergeTwoLists(list1, list2->next);
        return list2;
    }
    
}


int main(void){
    return 0;
}