/*
 Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
//You may assume that each input would have exactly one solution, and you may not use the same element twice.
//You can return the answer in any order.

// Runtime: 3 ms | beats 99.9% of other submissions
// Memory usage: 7.1 mb | beats 10.1 % of other submissions

*/

#include <stdio.h>
#include <stdlib.h>


typedef struct{
    int x;
    int i;
}Node;

int node_rank(Node *a, int n, int x)
{
  int result = 0;
  while (n > 0)
  {
    int m = n / 2;
    if (x <= a[m].x)
      n = m;
    else
    {
      result += m+1;
      a += m+1;
      n -= m+1;
    }
  }
  return result;
}

int node_bfind(Node *a, int n, int x)
{
  int r = node_rank(a, n, x);
  return r < n && a[r].x == x ? r : -1;
}

int cmpfunc(const void * a, const void * b){
   int val1 = ((Node*)a)->x;
   int val2 = ((Node*)b)->x;
   return ( val1 - val2 ); 
}

int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    Node *a = (Node*)malloc(sizeof(Node) * numsSize);
    for(int i = 0; i <numsSize;i++){
        a[i].x = nums[i];
        a[i].i = i;
    }
   qsort(a, (size_t)numsSize, sizeof(Node),cmpfunc);
    *returnSize = 2;
    int *result = (int*)malloc(sizeof(int)* (*returnSize));
    for(int i = 0; i < numsSize;i++){
        int find = node_bfind(a+(i+1), numsSize-(i+1), (target - a[i].x));
        if(find != -1){
            result[0] = a[i].i;
            result[1] = (a+i+1)[find].i;
            return result;
        }
    }
    result[0] = 0;
    result[1] = 0;
    return result;
}


int main(void){
    return 0;
}