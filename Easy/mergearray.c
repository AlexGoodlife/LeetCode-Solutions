/*

You are given two integer arrays nums1 and nums2, sorted in non-decreasing order, and two integers m and n, representing the number of elements in nums1 and nums2 respectively.

Merge nums1 and nums2 into a single array sorted in non-decreasing order.

Runtime 0ms | beats 100% of other submissions
Memory Usage 6MB | beats 76 % of other submissions
*/


#include <stdio.h>
#include <stdlib.h>



void merge(int* a, int nums1Size, int m, int* b, int nums2Size, int n){
    int result = n+m-1;
    int i = m-1;
    int j = n-1;
    while(i >=0 && j >= 0){
        if(a[i] > b[j])
            a[result--] = a[i--];
        else
            a[result--] = b[j--];
    }
    while(j >= 0)
        a[result--] = b[j--];
}

int main(void){
    return 0;
}