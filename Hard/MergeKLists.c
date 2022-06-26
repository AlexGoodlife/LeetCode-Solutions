/*
You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.

Merge all the linked-lists into one sorted linked-list and return it.

Runtime: 313 ms | beats 41 % of other submissions
Memory Usage 8.5 MB | beats 31% of other submissions
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

struct ListNode* mergeKLists(struct ListNode** lists, int listsSize){
    if(listsSize == 0)
        return NULL;
    if(listsSize == 1)
        return lists[0];
    struct ListNode* result = NULL;
    for(int i = 0; i < listsSize;i++){
        result = mergeTwoLists(result,lists[i]);
    }
    return result;
}


int main(void){
    return 0;
}